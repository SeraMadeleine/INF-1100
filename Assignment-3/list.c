#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/*
 * List implementation
 */

typedef struct listnode listnode_t;

struct listnode {
    listnode_t *next;
    void *item;
};

struct list {
    listnode_t *head;
    int numitems;
};

/*
 * Returns a newly created, empty list.
 */
list_t *list_create(void) // returns list * -> a pointer to a structure allocated on Heap
{
    list_t *newlist; // add new list to the struckt   
    
    newlist = malloc(sizeof(list_t));  // allocate memory 
    if(newlist == NULL) { // test if there is space to allocate memory 
        return NULL;
    }
    newlist -> head = NULL; // the representation of a empty list 
    newlist -> numitems = 0; // the number of item in the list. Zero because it is suppose to be empty 

    return newlist; // Return the newly created, empty list
}

/*
 * Frees the list; list and nodes, but not the items it holds.
 */
void list_destroy(list_t *list)
{
    listnode_t *node = list -> head; 

    /* If the node not are the last in the list, free the node */
    while (node != NULL) 
    {
        node = node -> next;  
        free(node); 
        return;
    }

    free(list); // free the list 
}

/*
 * Adds an item first in the provided list.
 */
void list_addfirst(list_t *list, void *item)
{    
    listnode_t *node = (listnode_t*) malloc(sizeof(listnode_t)); // allocate memory 
    if (node == NULL) {  // test if there is space to allocate memory 
        return;
    }
    node->item = item; 
    node->next = list->head; 
    list->head = node; 
    list->numitems++; // update the number of items 
    
}

/*
 * Adds an item last in the provided list.
 */
void list_addlast(list_t *list, void *item)  
{
    // declare two nodes, node putting in an item and currentnode for comparing 
    listnode_t *node, *currentnode;  // declear

    node = malloc(sizeof(listnode_t)); // allocate memory 
    if (node == NULL) {  // test if there is space to allocate memory 
        return;
    }

    node -> item = item; 
    node -> next = NULL; 
    currentnode = list -> head;

    if (currentnode == NULL) { // Checks if the node is the last node in the list 
        list -> head = node; 
    }
    else if (currentnode -> next == NULL) { // Run through until the last node  
        currentnode -> next = node; 
    }
    else {
        while (currentnode->next != NULL) { // 
            currentnode = currentnode -> next; 
        }
        currentnode -> next = node; // Set the current node to be the next node 
    }
    list -> numitems++; // update the number of items 

}

/*
 * Removes an item from the provided list, only freeing the node.
 */
void list_remove(list_t *list, void *item)  
{
    listnode_t *node = list->head; // Set the node to be the first in the linked list 

    if (node == NULL) { // Checks if the list are empty 
        return;
    }

    if (node -> item == item) {
        list->head = node->next; // update, so it runs through all the nodes  
        free(node); // free node 
        list -> numitems--;  // update the number of items 
        return;
    }

    /*
    Johannes Figenschau helped me develop this for-loop
    */
    for (listnode_t *currentnode = list->head; currentnode->next !=NULL;currentnode = currentnode->next) {
        if (currentnode->next->item == item) {
            listnode_t *node = currentnode->next;
            currentnode->next = currentnode->next->next;
            free(node); // free node 
            list->numitems--; // update the number of items 
            return;
        }
    }
}

/*
 * Return the number of items in the list.
 */
int list_size(list_t *list)
{
    return list -> numitems; 
}

/*
 * Iterator implementation
 */
struct list_iterator {
    listnode_t *next;
    list_t *list;
};

/*
 * Return a newly created list iterator for the given list.
 */
list_iterator_t *list_createiterator(list_t *list)
{
    list_iterator_t *iterator = malloc(sizeof(list_iterator_t)); // Allocate memory 
    iterator = malloc(sizeof(list_t)); // Allocate memory 
        if(iterator == NULL) { // Test if there is space to allocate memory 
        return NULL;
    }
    
    iterator -> next = list -> head; // Start the iterator at the head of the list 
    iterator -> list = list; 

    return iterator; // Return the iterator 
}


/*
 * Free the memory for the given list iterator.
 */
void list_destroyiterator(list_iterator_t *iter)
{
    /* Free the item before freeing the iter */
    list_iterator_t *iterator; 
    list_t *list;
    iterator -> next = list -> head; 
    while (iterator != NULL)
    {
        iterator = iterator -> next;  
        free(iterator); 
        return;
    }

    free(iter);
}


/*
 * Move iterator to next item in list and return current.
 */
void *list_next(list_iterator_t *iter)
{
    void *current_item =  NULL; 

    if (iter -> next != NULL) { // As long as the node not are the last in the list, run
        current_item = iter -> next -> item; // See if the item are found in the next node in the list 
        iter -> next = iter -> next -> next; 
    }
    return current_item; // Return current item 
}

/*
 * Let iterator point to first item in list again.
 */
void list_resetiterator(list_iterator_t *iter)
{
    iter -> next = iter -> list -> head;
}