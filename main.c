/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "single_list.h"

int main(int argc, char const *argv[])
{
    time_t t;

    srand(time(&t));

    node_t *head = create_node(sizeof(int));

    uint32_t n = rand();

    set_node_data(head, &n, sizeof(int));

    for(uint32_t i = 0; i < 1000; i++)
    {
        node_t *tmp = create_node(sizeof(uint32_t));

        n = rand();

        set_node_data(tmp, &n, sizeof(int));

        printf("%d\n\r", get_node_list_length(head));

        insert_node(&head, tmp, rand() % get_node_list_length(head));
    }

    node_t *curr = head;

    while (curr != NULL)
    {
        const uint32_t *tmp = get_node_data(curr);

        printf("%d\n\r", *tmp);

        curr = get_next_node(curr);
    }
    
    while (head != NULL)
    {
        remove_node_by_index(&head, rand() % get_node_list_length(head));
    }
    

    return 0;
}
