/**
 * @file single_list.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "single_list.h"

#define EXIT_ON_NO_MEM(ptr, msg_no_mem)  if(ptr == NULL) \
                                        {\
                                            fprintf(stderr, msg_no_mem);\
                                            exit(EXIT_FAILURE);\
                                        }

#define RETURN_ON_NO_MEM(ptr, msg_no_mem)  if(ptr == NULL) \
                                        {\
                                            fprintf(stderr, msg_no_mem);\
                                            return;\
                                        }

#define RETURN_VAL_ON_NO_MEM(ptr, msg_no_mem, retval)  if(ptr == NULL) \
                                        {\
                                            fprintf(stderr, msg_no_mem);\
                                            return retval;\
                                        }

struct node
{
    void * data;
    struct node * next;
};

node_t * create_node(size_t data_size)
{
    node_t * tmp = malloc(sizeof(node_t));
    tmp->next = NULL;

    EXIT_ON_NO_MEM(tmp, "couldn't allocate memory for node!");

    tmp->data = malloc(data_size * sizeof(char));

    EXIT_ON_NO_MEM(tmp, "couldn't allocate memory for data!");

    return tmp;
}

void delete_node(node_t *node)
{

    RETURN_ON_NO_MEM(node, "pointer directed to null");
    
    RETURN_ON_NO_MEM(node->data, "no data to free");

    free(node->data);

    memset(node, 0, sizeof(node_t));

    free(node);
}

void append_node(node_t **parent, node_t *child)
{
    node_t *curr_node = *parent;

    if(*parent == NULL)
    {
        *parent = child;
        return;
    }

    while (curr_node->next != NULL)
        curr_node = curr_node->next;
    
    curr_node->next = child;

}

void prepend_node(node_t **parent, node_t *child)
{
    child->next = *parent;

    *parent = child;
}

void insert_node(node_t **parent, node_t *child, size_t index)
{
    
    node_t *curr = *parent;

    if(index == 0)
    {
        prepend_node(parent, child);

        return;
    }

    while (index--)
    {
        curr = curr->next;

        RETURN_ON_NO_MEM(curr, "index out of range!\n");
    }

    child->next = curr->next;

    curr->next = child;
    
}

void remove_node_by_index(node_t **parent, size_t index)
{

    node_t * curr = *parent;
    node_t * prev = NULL;

    while(index--)
    {
        RETURN_ON_NO_MEM(curr, "index out of range!\n");

        prev = curr;
        curr = curr->next;
    }

    if(prev != NULL)
        prev->next = curr->next;
    else
        *parent = curr->next;

    delete_node(curr);
}

void pop_node(node_t **parent)
{
    node_t * curr = *parent;
    node_t * prev = NULL;

    if(curr == NULL)
        RETURN_ON_NO_MEM(curr, "No data is allocated on this pointer!\n");

    while(curr->next != NULL)
    {
        RETURN_ON_NO_MEM(curr, "index out of range!\n");

        prev = curr;
        curr = curr->next;
    }

    if(prev)
        prev->next = NULL;
    else
        *parent = NULL;

    delete_node(curr);
}

void set_node_data(node_t *node, const void * data, size_t data_size)
{
    RETURN_ON_NO_MEM(node, "Node pointer can't be null!\n");
    
    RETURN_ON_NO_MEM(data, "Data pointer can't be null!\n");

    memcpy(node->data, data, data_size);
}


void copy_node_data(node_t *node, void * dest, size_t data_size)
{
    RETURN_ON_NO_MEM(node, "Node pointer can't be null!\n");

    RETURN_ON_NO_MEM(dest, "Destination pointer can't be null!\n");

    memcpy(dest, node->data, data_size);
}

node_t * get_node_by_index(node_t *parent, uint32_t index)
{
    while (index--)
    {
        RETURN_VAL_ON_NO_MEM(parent, "index is out of range!\n", NULL)

        parent = parent->next;
    }
    
    return parent;
}

const void * get_node_data(node_t *node)
{
    return node->data;
}

node_t * get_next_node(node_t *node)
{
    return node->next;
}

uint32_t get_node_list_length(node_t *head)
{
    uint32_t index = 0;

    RETURN_VAL_ON_NO_MEM(head, "Head pointer g't be Null", 0);

    while (head != NULL)
    {
        index++;

        head = head->next;
    }
    
    return index;
}