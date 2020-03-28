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
long long lockTimer = 0; 
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
// int listBool = 0; 
int numLists = 1; 

// locks and such
pthread_mutex_t* mutexPtr;
// pthread_mutex_t mutex; 
volatile int * sLockPtr; 
volatile int sLock = 0; 

// list
SortedList_t ** headPtr; 
SortedListElement_t * myItems; 

// hash function
int hashFunc(const char* keyValue); 

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
        {"lists", required_argument, NULL, 6},
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
            case 6: 
                numLists = atoi(optarg); 
                break; 
            default: 
                fprintf(stderr, "%s", "Incorrect or extra arguments; use --threads=, --iterations=\n"); 
                exit(1); 

        }//end of switch 
    }//end of while loop

    // printf("number of lists: %d\n", numLists); 
    // initialize mutex(es)
    

    if ( m == 1 )
    {
        // pthread_mutex_init(&mutex, NULL); 
        //pthread_mutex_t mutexArray[numLists]; 
        //mutexPtr = &mutexArray[0]; 
        mutexPtr = malloc(numLists*sizeof(pthread_mutex_t)); 
        for (int i = 0; i < numLists; i++)
        {
            if (pthread_mutex_init(&mutexPtr[i], NULL) != 0) 
            { 
                printf("\n mutex initialization failed\n"); 
                exit(1); 
            }
            
        }
        // printf("initialized mutexes\n"); 
    }
    else if ( s == 1 )
    {
        sLockPtr = malloc(numLists*sizeof(int)); 
        for (int i = 0; i < numLists; i++)
        {
            sLockPtr[i] = 0; 
        }
    }


    // initialize empty list
        // SortedList_t *list : header for the list
        // SortedListElement_t *element : element to be added to the list
    SortedList_t * headArray[numLists]; 
    headPtr = &headArray[0]; 
    for (int i = 0; i < numLists; i++)
    {
        headArray[i] = (SortedList_t *) malloc(sizeof(SortedList_t));   //make a node and point head to it  
        headArray[i]->key = NULL; 
        headArray[i]->next = headArray[i]; 
        headArray[i]->prev = headArray[i]; 
    }
    
    // declaring 2D array with all values
    SortedListElement_t allValues[numThreads][numIterations]; 
    myItems = &allValues[0][0]; 
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
	// struct timespec start, end;
	// clock_gettime(CLOCK_MONOTONIC, &start);	
    // initialize array of threads
    pthread_t threadArray[numThreads]; 
    // make threads 
   
    //holds all the thread indices
    int threadIndex[numThreads];  
    for (int i = 0; i < numThreads; i++)
    {
        threadIndex[i] = i; 
    }
    struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);	
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
    long long avgDiff = diff / numOps; 
    long long avgLockTime = lockTimer / numOps; 
    printf("%d,%d,%d,%d,%lld,%lld, %lld\n", numThreads, numIterations, numLists, numOps, diff, avgDiff, avgLockTime);

    //free(headPtr); 
    //free(myItems); 
    // free(sLockPtr); 
    //free(mutexPtr);
    exit(0); 
}

// all of our elements are ready inside of myItems
// here we will portion them into different lists with different heads
// save the head number, so we can operate inside of that with a corresponding lock 
// functions
void *threadFunc(void * num) 
{ 
    int listIndex = 0; 
    
    // arr[i][j] = *(ptr + (i x no_of_cols + j))

    // index saying which thread we are on
    int iIndex = *((int *)num); 
    // initialize each to linked list

    for (int j = 0; j < numIterations; j++)
    {

        int help = iIndex * numIterations + j;
 
        if ( m == 1 )
        {
            struct timespec lockStart, lockEnd;
            // printf("start lock time: %lld\n", lockTimer); 
            // printf("right after declaration: \n"); 
            // printf("lockStart.tv_sec: %ld\n", lockStart.tv_sec); 
            // printf("lockStart.tv_nsec: %ld\n", lockStart.tv_nsec); 
            // printf("lockEnd.tv_sec: %ld\n", lockEnd.tv_sec); 
            // printf("lockEnd.tv_nsec: %ld\n", lockEnd.tv_nsec); 
            if (numLists == 1)
            {
                listIndex = 0; 
            }
            else
            {
                listIndex = hashFunc((myItems+help)->key); 
            }
            // printf("listIndex: %i\n", listIndex);
            clock_gettime(CLOCK_MONOTONIC, &lockStart);	
            pthread_mutex_lock(&mutexPtr[listIndex]); 
            clock_gettime(CLOCK_MONOTONIC, &lockEnd);	
            lockTimer += BILLION * (lockEnd.tv_sec - lockStart.tv_sec) + lockEnd.tv_nsec - lockStart.tv_nsec;
            // printf("after calculation: \n"); 
            // printf("lockStart.tv_sec: %ld\n", lockStart.tv_sec); 
            // printf("lockStart.tv_nsec: %ld\n", lockStart.tv_nsec); 
            // printf("lockEnd.tv_sec: %ld\n", lockEnd.tv_sec); 
            // printf("lockEnd.tv_nsec: %ld\n", lockEnd.tv_nsec); 
            // printf("end lock time: %lld\n", lockTimer); 

        }
        else if ( s == 1 )
        {

            struct timespec lockStart, lockEnd;
            if (numLists == 1)
            {
                listIndex = 0; 
            }
            else
            {
                listIndex = hashFunc((myItems+help)->key); 
            }
            clock_gettime(CLOCK_MONOTONIC, &lockStart);	
            while (__sync_lock_test_and_set(&sLockPtr[listIndex], 1)) while(sLockPtr[listIndex]);
            clock_gettime(CLOCK_MONOTONIC, &lockEnd);	
            lockTimer += BILLION * (lockEnd.tv_sec - lockStart.tv_sec) + lockEnd.tv_nsec - lockStart.tv_nsec;
            // printf("end lock time: %lld\n", lockTimer); 
        }
        SortedList_insert(*(headPtr+listIndex), (myItems+help)); 
        if ( m == 1 )
        {
            pthread_mutex_unlock(&mutexPtr[listIndex]); 
        }
        else if ( s == 1 )
        {
            __sync_lock_release(&sLockPtr[listIndex]);
        }
    }
    if ( s == 1 )
        {
            while (__sync_lock_test_and_set(&sLockPtr[listIndex], 1)) while(sLockPtr[listIndex]);
            counter++; 
            counter*=counter; 
            counter/=counter; 
            counter--; 
            __sync_lock_release(&sLockPtr[listIndex]);
        }    

    if ( m == 1 )
    {
        struct timespec lockStart, lockEnd;
        // printf("start lock time: %lld\n", lockTimer); 
        // printf("right after declaration: \n"); 
        // printf("lockStart.tv_sec: %ld\n", lockStart.tv_sec); 
        // printf("lockStart.tv_nsec: %ld\n", lockStart.tv_nsec); 
        // printf("lockEnd.tv_sec: %ld\n", lockEnd.tv_sec); 
        // printf("lockEnd.tv_nsec: %ld\n", lockEnd.tv_nsec); 
        clock_gettime(CLOCK_MONOTONIC, &lockStart);
        // printf("listIndex: %i\n", listIndex);	
        pthread_mutex_lock(&mutexPtr[listIndex]); 
        clock_gettime(CLOCK_MONOTONIC, &lockEnd);	
        lockTimer += BILLION * (lockEnd.tv_sec - lockStart.tv_sec) + lockEnd.tv_nsec - lockStart.tv_nsec;
        // printf("after calculation: \n"); 
        // printf("lockStart.tv_sec: %ld\n", lockStart.tv_sec); 
        // printf("lockStart.tv_nsec: %ld\n", lockStart.tv_nsec); 
        // printf("lockEnd.tv_sec: %ld\n", lockEnd.tv_sec); 
        // printf("lockEnd.tv_nsec: %ld\n", lockEnd.tv_nsec); 
        // printf("end lock time: %lld\n", lockTimer); 
    }
    else if ( s == 1 )
    {
        struct timespec lockStart, lockEnd;
        //printf("start lock time: %lld\n", lockTimer); 
        clock_gettime(CLOCK_MONOTONIC, &lockStart);	
        while (__sync_lock_test_and_set(&sLockPtr[listIndex], 1))  while(sLockPtr[listIndex]);
        clock_gettime(CLOCK_MONOTONIC, &lockEnd);	
        lockTimer += BILLION * (lockEnd.tv_sec - lockStart.tv_sec) + lockEnd.tv_nsec - lockStart.tv_nsec;
        // printf("end lock time: %lld\n", lockTimer); 
    }
    // get length
    int len = 0; 
    for (int i = 0; i < numLists; i++)
    {
        len += SortedList_length(*(headPtr+i)); 
    }
    
    if (len == -1)
    {
        fprintf(stderr, "Finding length of corrupted list\n"); 
        exit(2); 
    }
    if ( m == 1 )
    {
        pthread_mutex_unlock(&mutexPtr[listIndex]); 
    }
    else if ( s == 1 )
    {
        __sync_lock_release(&sLockPtr[listIndex]);
    }
    // printf("length: %i\n", len);

     // test lookup
     //char * matchKey = malloc(25*sizeof(char)); 
     for (int j = 0; j < numIterations; j++)
    {
        int help = iIndex * numIterations + j; 
        if ( m == 1 )
        {
            struct timespec lockStart, lockEnd;
            // printf("start lock time: %lld\n", lockTimer); 
            // printf("right after declaration: \n"); 
            // printf("lockStart.tv_sec: %ld\n", lockStart.tv_sec); 
            // printf("lockStart.tv_nsec: %ld\n", lockStart.tv_nsec); 
            // printf("lockEnd.tv_sec: %ld\n", lockEnd.tv_sec); 
            // printf("lockEnd.tv_nsec: %ld\n", lockEnd.tv_nsec); 
            if (numLists == 1)
            {
                listIndex = 0; 
            }
            else
            {
                listIndex = hashFunc((myItems+help)->key); 
            }
            clock_gettime(CLOCK_MONOTONIC, &lockStart);	
            pthread_mutex_lock(&mutexPtr[listIndex]); 
            clock_gettime(CLOCK_MONOTONIC, &lockEnd);	
            lockTimer += BILLION * (lockEnd.tv_sec - lockStart.tv_sec) + lockEnd.tv_nsec - lockStart.tv_nsec;
            // printf("after calculation: \n"); 
            // printf("lockStart.tv_sec: %ld\n", lockStart.tv_sec); 
            // printf("lockStart.tv_nsec: %ld\n", lockStart.tv_nsec); 
            // printf("lockEnd.tv_sec: %ld\n", lockEnd.tv_sec); 
            // printf("lockEnd.tv_nsec: %ld\n", lockEnd.tv_nsec); 
            // printf("end lock time: %lld\n", lockTimer); 
        }
        else if ( s == 1 )
        {
            struct timespec lockStart, lockEnd;
            if (numLists == 1)
            {
                listIndex = 0; 
            }
            else
            {
                listIndex = hashFunc((myItems+help)->key); 
            }
            // printf("start lock time: %lld\n", lockTimer); 
            clock_gettime(CLOCK_MONOTONIC, &lockStart);	
            while (__sync_lock_test_and_set(&sLockPtr[listIndex], 1)) while(sLockPtr[listIndex]);
            clock_gettime(CLOCK_MONOTONIC, &lockEnd);	
            lockTimer += BILLION * (lockEnd.tv_sec - lockStart.tv_sec) + lockEnd.tv_nsec - lockStart.tv_nsec;
            // printf("end lock time: %lld\n", lockTimer); 
        }

        // *** USED TO BE DECLARED HERE WORKS WITH ONE LIST LMAO ***//
        // int help = iIndex * numIterations + j; 


        if (numLists == 1)
        {
            listIndex = 0; 
        }
        // else
        // {
        //     // strcpy(matchKey, (myItems+help)->key); 
        //     listIndex = hashFunc(matchKey); 
        // }
        // printf("looking up: %s\n", (myItems+help)->key); 
        // SortedListElement_t* found = SortedList_lookup(*(headPtr+listIndex), (myItems+help)->key); 
        SortedListElement_t* found = SortedList_lookup(*(headPtr+listIndex), (myItems+help)->key); 

        if (found == NULL)
        {
            fprintf(stderr, "Looked up an element in a corrupted list\n");
            exit(2); 
        } 
        // printf("deleting: %s\n", (myItems+help)->key); 
        if (SortedList_delete(found) == 1)
        {
            fprintf(stderr, "Deleting from corrupted list\n"); 
            exit(2); 
        }
        if ( m == 1 )
        {
            pthread_mutex_unlock(&mutexPtr[listIndex]); 
        }
        else if ( s == 1 )
        {
            __sync_lock_release(&sLockPtr[listIndex]);
        }
        // if ( s == 1)
        // {
        //     sleep(.8); 
        // }
        // if ( s == 1 )
        // {
        //     while (__sync_lock_test_and_set(&sLockPtr[listIndex], 1)) while(sLockPtr[listIndex]);
        //     for (int i = 0; i < 1000; i++)
        //     {
        //         if (counter == 0)
        //         {
        //             counter++; 
        //             counter*=counter; 
        //             counter/=counter; 
        //             counter--; 
        //         }
        //         else
        //         {
        //             counter++; 
        //             counter*=counter; 
        //             counter/=counter; 
        //             counter--; 
        //         }
                
        //     }
        //     __sync_lock_release(&sLockPtr[listIndex]);
        // }
    } 
    // done
    return NULL; 
}  

int hashFunc(const char* keyValue)
{
    return atoi(keyValue)%numLists; 
}

