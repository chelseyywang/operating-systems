// chelsey wang
// 705124638
// chelseyyywang@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <stdint.h>
#include <sys/types.h>

#define BILLION 1000000000L

// global variables
long long counter = 0; 
int opt_yield = 0; 
int m = 0; 
int s = 0; 
int cs = 0; 
// locks and such
pthread_mutex_t mutex;
volatile int sLock = 0; 

void errorHandler(int sigNum)
{
    if (sigNum == SIGSEGV)
    {
        fprintf(stderr, "%s", "Caught segfault"); 
        exit(4); 
    }
}

void add(long long *pointer, long long value); 

void *threadFunc(void * num); 

void *myThreadFun(void *vargp);

int main(int argc, char** argv)
{
    // int structIndex; 
    static struct option options[] = {
        {"threads", required_argument, NULL, 1}, 
        {"iterations", required_argument, NULL, 2},  
        {"yield", no_argument, NULL, 3},  
        {"sync", required_argument, NULL, 5},  

        {0,0,0,0}
    };

    int numThreads = 1; 
    int numIterations = 1; 

    int c; 
    while ((c = getopt_long(argc, argv, "", options, NULL))!=-1)
    {

        switch (c) {
            case 1: 
                numThreads = atoi(optarg); 
                break; 
            case 2: 
                numIterations = atoi(optarg); 
                break; 
            case 3: 
                opt_yield = 1; 
                printf("add-yield"); 
                break; 
            case 5: 
                if (optarg[0] == 'm' && optarg[1] == '\0')
                {
                    m = 1; 
                }
                else if (optarg[0] == 's' && optarg[1] == '\0')
                {
                    s = 1; 
                }
                else if (optarg[0] == 'c' && optarg[1] == '\0')
                {
                    cs = 1; 
                }
                else
                {
                    fprintf(stderr, "%s", "Incorrect usage of --sync=; use --sync=m, --sync=s, --sync=c only\n"); 
                    exit(1); 
                }
                break; 
            default: 
                fprintf(stderr, "%s", "Incorrect or extra arguments; use --threads=, --iterations=\n"); 
                exit(1); 

        }//end of switch 
    }//end of while loop

    // initialize mutex
    if ( m == 1 )
    {
        if (pthread_mutex_init(&mutex, NULL) != 0) 
        { 
            printf("\n mutex initialization failed\n"); 
            exit(1); 
        }
    }
    // start timer
    long long diff; 
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);	
    // initialize array of threads
    pthread_t threadArray[numThreads]; 
    // make threads 
    for (int i = 0; i < numThreads; i++)
    {
        pthread_create(&threadArray[i], NULL, threadFunc, &numIterations); 
    }
    for (int i = 0; i < numThreads; i++)
    {
        pthread_join(threadArray[i], NULL); 
    }
    // end clock 
	clock_gettime(CLOCK_MONOTONIC, &end);	

	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;

    if ( opt_yield == 1)
    {
        if ( m == 1 )
        {
            printf("-m,");
        }
        else if ( s == 1 )
        {
            printf("-s,");
        }
        else if ( cs == 1 )
        {
            printf("-c,");
        }
        else
        {
            printf("-none,"); 
        }
    }
    else
    {
        if ( m == 1 )
        {
            printf("add-m,");
        }
        else if ( s == 1 )
        {
            printf("add-s,");
        }
        else if ( cs == 1 )
        {
            printf("add-c,");
        }
        else
        {
            printf("add-none,"); 
        }
    }
    int numOps = numThreads * numIterations * 2; 
    int avgDiff = diff / numOps; 
    printf("%d,%d,%d,%lld,%d,%lld\n", numThreads, numIterations, numOps, diff, avgDiff, counter);
    exit(0); 
}

// functions
void *threadFunc(void * num) 
{ 
    int iters = *((int *)num); 
    for (int i = 0; i < iters; i++)
    {
        add(&counter, 1); 
    }
    for (int i =0; i < iters; i++)
    {
        add(&counter, -1); 
    }
    return NULL; 
}  

void add(long long *pointer, long long value) 
{ 
    if ( cs == 1 )
    {
        long long old; 
        long long new;
        do {
            old = *pointer; 
            new = old + value; 
            if (opt_yield)
                sched_yield(); 
        }while(__sync_val_compare_and_swap(pointer, old, new) != old); 
    }
    else 
    {
        if ( m == 1 )
        {
            pthread_mutex_lock(&mutex); 
        }
        else if ( s == 1 )
        {
            while (__sync_lock_test_and_set(&sLock, 1)) while (sLock);
        }
        // no touch
        if ( cs != 1 )
        {
            long long sum = *pointer + value;
            if (opt_yield)
                sched_yield();
            *pointer = sum;
        }
        // unlock
        if ( m == 1 )
        {
            pthread_mutex_unlock(&mutex); 
        }
        else if ( s == 1 )
        {
            __sync_lock_release(&sLock);
        }
    }
    
    
}
