#include "SortedList.h"
#include <stdio.h>
#include <string.h>
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
/**
 * SortedList (and SortedListElement)
 *
 *	A doubly linked list, kept sorted by a specified key.
 *	This structure is used for a list head, and each element
 *	of the list begins with this structure.
 *
 *	The list head is in the list, and an empty list contains
 *	only a list head.  The next pointer in the head points at
 *      the first (lowest valued) elment in the list.  The prev
 *      pointer in the list head points at the last (highest valued)
 *      element in the list.  Thus, the list is circular.
 *
 *      The list head is also recognizable by its NULL key pointer.
 *
 * NOTE: This header file is an interface specification, and you
 *       are not allowed to make any changes to it.
 */
// struct SortedListElement {
// 	struct SortedListElement *prev;
// 	struct SortedListElement *next;
// 	const char *key;
// };
// typedef struct SortedListElement SortedList_t;
// typedef struct SortedListElement SortedListElement_t;


/**
 * SortedList_insert ... insert an element into a sorted list
 *
 *	The specified element will be inserted in to
 *	the specified list, which will be kept sorted
 *	in ascending order based on associated keys
 *
 * @param SortedList_t *list ... header for the list
 * @param SortedListElement_t *element ... element to be added to the list
 */
void SortedList_insert(SortedList_t *list, SortedListElement_t *element)
{
    
    SortedListElement_t* iter; 
    for (iter = list->next; iter != list; iter = iter->next)
    {
        // printf("comparing: %s and %s\n", iter->key, element->key); 
        if (strcmp(iter->key, element->key) >= 0)
        {
            // printf("looks like %s > %s\n", iter->key, element->key); 
            break; 
        }      
    }
    if (opt_yield & INSERT_YIELD)
    {
        sched_yield(); 
    }
    element->prev = iter->prev; 
    element->next = iter; 
    iter->prev->next = element; 
    iter->prev = element; 
    // printf("element: %s\n", element->key); 
    // printf("prev: %s\n", element->prev->key); 
    // printf("next: %s\n", element->next->key); 

}

/**
 * SortedList_delete ... remove an element from a sorted list
 *
 *	The specified element will be removed from whatever
 *	list it is currently in.
 *
 *	Before doing the deletion, we check to make sure that
 *	next->prev and prev->next both point to this node
 *
 * @param SortedListElement_t *element ... element to be removed
 *
 * @return 0: element deleted successfully, 1: corrtuped prev/next pointers
 *
 */
int SortedList_delete( SortedListElement_t *element)
{
    if (element->key == NULL)
        return 1; 
    if (element->next->prev != element)
        return 1; 
    if (element->prev->next != element)
        return 1; 
    if (opt_yield & DELETE_YIELD)
    {
        sched_yield(); 
    }
    element->next->prev = element->prev; 
    element->prev->next = element->next; 
    return 0; 
}

/**
 * SortedList_lookup ... search sorted list for a key
 *
 *	The specified list will be searched for an
 *	element with the specified key.
 *
 * @param SortedList_t *list ... header for the list
 * @param const char * key ... the desired key
 *
 * @return pointer to matching element, or NULL if none is found
 */
SortedListElement_t *SortedList_lookup(SortedList_t *list, const char *key)
{
    // if (list->next->prev != list)
    //     return -1; 
    // if (list->prev->next != list)
    //     return -1; 
    if (key == NULL)
        return NULL; 
    SortedListElement_t* iter; 
    for (iter = list->next; iter != list; iter = iter->next)
    {
        // if (iter->next->prev != iter)
        //     return -1; 
        // if (iter->prev->next != iter)
        //     return -1; 
        if (opt_yield & LOOKUP_YIELD)
        {
            sched_yield(); 
        }
        if (strcmp(iter->key, key) == 0)
            return iter;  
    }
    // fprintf("key not found\n"); 
    return NULL;  
}

/**
 * SortedList_length ... count elements in a sorted list
 *	While enumeratign list, it checks all prev/next pointers
 *
 * @param SortedList_t *list ... header for the list
 *
 * @return int number of elements in list (excluding head)
 *	   -1 if the list is corrupted
 */
int SortedList_length(SortedList_t *list)
{
    if (list->next->prev != list)
        return -1; 
    if (list->prev->next != list)
        return -1; 
    int counter = 0; 
    SortedListElement_t* iter; 
    for (iter = list->next; iter != list; iter = iter->next)
    {
        if (opt_yield & LOOKUP_YIELD)
        {
            sched_yield(); 
        }
        if (iter->next->prev != iter)
            return -1; 
        if (iter->prev->next != iter)
            return -1; 
        counter++; 
    }
    return counter; 
}


