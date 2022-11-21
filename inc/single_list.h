/**
 * @file single_list.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SINGLE_LIST_H 
#define SINGLE_LIST_H 

#include <stdio.h>
#include <stdint.h>

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

typedef struct node node_t;

/**
 * @brief Create a node object
 * 
 * @param ptr 
 * @param data_size size of the data object
 */
node_t * create_node(size_t data_size);

/**
 * @brief append a node to the end of the list
 * 
 * @param parent 
 * @param child 
 */
void append_node(node_t **parent, node_t *child);

/**
 * @brief prepend a node to parent
 * 
 * @param parent 
 * @param child 
 */
void prepend_node(node_t **parent, node_t *child);

/**
 * @brief add a node to the node list by index
 * 
 * @param parent pointer to the head note of the list
 * @param child node to be added
 * @param index index to be placed in
 */
void insert_node(node_t **parent, node_t *child, size_t index);

/**
 * @brief remove a node from the list
 * 
 * @param parent pointer to the head note of the list
 * @param child 
 */
void remove_node(node_t **parent, node_t *child);

/**
 * @brief remove a note by index
 * 
 * @param parent pointer to the head node of the list
 * @param index index of node to be removed
 */
void * remove_node_by_index(node_t **parent, size_t index, size_t data_size);

/**
 * @brief delete a node with it's data
 * 
 * @param node 
 */
void * delete_node(node_t *node, size_t data_size);

/**
 * @brief pop de last 
 * 
 * @param parent 
 */
void * pop_node(node_t **parent, size_t data_size);

/**
 * @brief Set the node data object
 * 
 * @param node 
 * @param data 
 * @param data_size 
 */
void set_node_data(node_t *node, const void * data, size_t data_size);

/**
 * @brief Get the node data object
 * 
 * @param node 
 * @param dest 
 * @param data_size 
 */
void copy_node_data(node_t *node, void * dest, size_t data_size);

/**
 * @brief Get the node data object
 * 
 * @param node 
 * @return const void* 
 */
const void * get_node_data(node_t *node);

/**
 * @brief Get the node object by index
 * 
 * @param parent head of the node list
 * @param index index to get
 * @return node_t node on index
 */
node_t * get_node_by_index(node_t *parent, uint32_t index);

/**
 * @brief Get the next node object
 * 
 * @param parent 
 * @return node_t* 
 */
node_t * get_next_node(node_t *parent);

/**
 * @brief Set the next node
 * 
 * @param node 
 * @param next_node 
 */
void set_next_node(node_t *node, node_t *next_node);

/**
 * @brief Get the node list length
 * 
 * @param head first node in list
 * @return uint32_t length of nodes
 */
uint32_t get_node_list_length(node_t *head);

#endif