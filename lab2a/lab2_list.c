// chelsey wang
// 705124638
// chelseyyywang@gmail.com

#include "SortedList.h"
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
int numThreads = 1; 
int numIterations = 1; 
int yieldPrint = 0; 
int printed = 0;  
int iii = 0; 
int ddd = 0; 
int lll = 0; 
// int cs = 0; 
// locks and such
pthread_mutex_t mutex;
volatile int sLock = 0; 

// list
SortedList_t * head; 
SortedListElement_t * myList; 



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
        {"yield", required_argument, NULL, 3},  
        {"sync", required_argument, NULL, 5},  

        {0,0,0,0}
    };

    int optargLen = 0; 
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
                // printf("list-yield"); 
                yieldPrint = 1; 
                if (printed == 0)
                {
                    //printf("list-%s", optarg); 
                    printed = 1; 
                }
                optargLen = strlen(optarg); 
                if (optargLen > 3)
                {
                    fprintf(stderr, "%s", "Incorrect usage of --yield=; use --yield=[idl]\n"); 
                    exit(1); 
                }
                for (int i = 0; i<optargLen; i++)
                {
                    if (optarg[i] == 'i')
                    {
                        iii = 1; 
                        opt_yield = opt_yield | INSERT_YIELD; 
                    }
                    else if ( optarg[i] == 'd')
                    {
                        ddd = 1; 
                        opt_yield = opt_yield | DELETE_YIELD; 
                    }
                    else if (optarg[i] == 'l')
                    {
                        lll = 1; 
                        opt_yield = opt_yield | LOOKUP_YIELD; 
                    }
                    else
                    {
                        fprintf(stderr, "%s", "Incorrect usage of --yield=; use --yield=none, [idl]\n"); 
                        exit(1);
                    }
                }
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
    // initialize empty list
        // SortedList_t *list : header for the list
        // SortedListElement_t *element : element to be added to the list
    head = (SortedList_t *) malloc(sizeof(SortedList_t));   //make a node and point head to it  
    head->key = NULL; 
    head->next = head; 
    head->prev = head; 
    // declaring 2D array with all values
    SortedListElement_t allValues[numThreads][numIterations]; 
    myList = &allValues[0][0]; 
    for (int i = 0; i < numThreads; i++)
    {
        for (int j = 0; j < numIterations; j++)
        {
            int randomInt = rand();  
            char* rando = (char*) malloc((25) * sizeof(char));
            //char random[25]; 
            sprintf(rando, "%d", randomInt);
            allValues[i][j].key = rando;  
        }
    }

    // for (int i = 0; i < numThreads; i++)
    // {
    //     for (int j = 0; j < numIterations; j++)
    //     {
    //         printf("i,j: %i,%i: ", i, j); 
    //         printf("%s\n", allValues[i][j].key); 
    //     }
    // }
    /*

    int listNum[2]; 
    listNum[0] = 5; 
    listNum[1] = 8; 
    int * listPtr = listNum; 
    printf("printing %d: ", *(listPtr+1)); 

    */
    
    // example of how to make key stuff work im cyring
    /*
        
        head = (SortedList_t *) malloc(sizeof(SortedList_t));   //make a node and point head to it 
        char aChar = 'a'; 
        char * chPtr = &aChar;
        head->key = chPtr;
        printf("head node: %c\n", *(head->key)); 

    */

    // start timer
    long long diff; 
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);	
    // initialize array of threads
    pthread_t threadArray[numThreads]; 
    // make threads 
   
    //holds all the thread indices
    int threadIndex[numThreads];  
    for (int i = 0; i < numThreads; i++)
    {
        threadIndex[i] = i; 
    }
    // creating 
    for (int i = 0; i < numThreads; i++)
    {
        pthread_create(&threadArray[i], NULL, threadFunc, &threadIndex[i]); 
    }
    // joining 
    for (int i = 0; i < numThreads; i++)
    {
            pthread_join(threadArray[i], NULL);  
    }

    // end clock 
	clock_gettime(CLOCK_MONOTONIC, &end);	

	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;

    // ** linked list print **//
    // printf("linked list: \n");  
    // SortedListElement_t* check; 
    // for (check = head->next; check != head; check = check->next)
    // {
    //     printf("->%s\n", check->key); 
    // }
    //** head print out **//
    // printf("head: \n");  
    // printf("head next: %s\n", head->next->key); 
    // printf("head prev: %s\n", head->prev->key); 
    // ** reverse linked list print out **//
    // printf("linked list reverse: \n");  
    // SortedListElement_t* checkBack; 
    // for (checkBack = head->prev; checkBack != head; checkBack = checkBack->prev)
    // {
    //     printf("<-%s\n", checkBack->key); 
    // }

    

    /*
        the name of the test, which is of the form: list-yieldopts-syncopts: where
            yieldopts = {none, i,d,l,id,il,dl,idl}
            syncopts = {none,s,m}
        the number of threads (from --threads=)
        the number of iterations (from --iterations=)
        the number of lists (always 1 in this project)
        the total number of operations performed: threads x iterations x 3 (insert + lookup + delete)
        the total run time (in nanoseconds) for all threads
        the average time per operation (in nanoseconds).
    */
    if (yieldPrint == 0)
    {
        printf("list-none"); 
        if (m == 1)
            printf("-m,"); 
        else if (s == 1)
            printf("-s,"); 
        else
            printf("-none,"); 
    }
    else if (yieldPrint == 1)
    { 
        printf("list-"); 
        if (iii == 1)
            printf("i"); 
        if (ddd == 1)
            printf("d"); 
        if (lll == 1)
            printf("l"); 
        if (m == 1)
            printf("-m,"); 
        else if (s == 1)
            printf("-s,"); 
        else
            printf("-none,");
    }
    int numOps = numThreads * numIterations * 3; 
    int avgDiff = diff / numOps; 
    printf("%d,%d,1,%d,%lld,%d\n", numThreads, numIterations, numOps, diff, avgDiff);
    exit(0); 
}

// functions
void *threadFunc(void * num) 
{ 
    
    // arr[i][j] = *(ptr + (i x no_of_cols + j))

    // index saying which thread we are on
    int iIndex = *((int *)num); 
    // initialize each to linked list

    for (int j = 0; j < numIterations; j++)
    {

        int help = iIndex * numIterations + j;
        if ( m == 1 )
        {
            pthread_mutex_lock(&mutex); 
        }
        else if ( s == 1 )
        {
            while (__sync_lock_test_and_set(&sLock, 1)) while (sLock);
        }
        SortedList_insert(head, (myList+help)); 
        if ( m == 1 )
        {
            pthread_mutex_unlock(&mutex); 
        }
        else if ( s == 1 )
        {
            __sync_lock_release(&sLock);
        }
    }
        

    if ( m == 1 )
    {
        pthread_mutex_lock(&mutex); 
    }
    else if ( s == 1 )
    {
        while (__sync_lock_test_and_set(&sLock, 1)) while (sLock);
    }
    // get length
    int len = SortedList_length(head); 
    if (len == -1)
    {
        fprintf(stderr, "Finding length of corrupted list\n"); 
        exit(2); 
    }
    if ( m == 1 )
    {
        pthread_mutex_unlock(&mutex); 
    }
    else if ( s == 1 )
    {
        __sync_lock_release(&sLock);
    }
    // printf("length: %i\n", len);

    if ( m == 1 )
    {
        pthread_mutex_lock(&mutex); 
    }
    else if ( s == 1 )
    {
        while (__sync_lock_test_and_set(&sLock, 1)) while (sLock);
    }
     // test lookup
     for (int j = 0; j < numIterations; j++)
    {
        int help = iIndex * numIterations + j; 
        // printf("looking up: %s\n", (myList+help)->key); 
        SortedListElement_t* found = SortedList_lookup(head, (myList+help)->key); 
        if (found == NULL)
        {
            fprintf(stderr, "Looked up an element in a corrupted list\n");
            exit(2); 
        } 
        // printf("deleting: %s\n", (myList+help)->key); 
        if (SortedList_delete(found) == 1)
        {
            fprintf(stderr, "Deleting from corrupted list\n"); 
            exit(2); 
        }
    } 

    if ( m == 1 )
    {
        pthread_mutex_unlock(&mutex); 
    }
    else if ( s == 1 )
    {
        __sync_lock_release(&sLock);
    }
    // done
    return NULL; 
}  

void add(long long *pointer, long long value) 
{ 
    // if ( cs == 1 )
    // {
    //     long long old; 
    //     long long new;
    //     do {
    //         old = *pointer; 
    //         new = old + value; 
    //         if (opt_yield)
    //             sched_yield(); 
    //     }while(__sync_val_compare_and_swap(pointer, old, new) != old); 
    // }
    // else 
    // {
        if ( m == 1 )
        {
            pthread_mutex_lock(&mutex); 
        }
        else if ( s == 1 )
        {
            while (__sync_lock_test_and_set(&sLock, 1)) while (sLock);
        }
        // no touch
            long long sum = *pointer + value;
            if (opt_yield)
                sched_yield();
            *pointer = sum;
        // unlock
        if ( m == 1 )
        {
            pthread_mutex_unlock(&mutex); 
        }
        else if ( s == 1 )
        {
            __sync_lock_release(&sLock);
        }
    //}
}
