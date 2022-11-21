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
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#include "single_list.h"

#define FIB_BASE "0-1-"
#define FIB_CALC_START 2
struct fib_entry {

    int sequence_length;

    char *sequence;

};

typedef struct fib_entry fib_entry_t;

const fib_entry_t create_fib_entry(uint32_t sequence_length);

node_t * create_fib_list_entry(uint32_t sequence_length);

void remove_fib_list_entry(node_t **head, uint32_t sequence_length);

void print_sequence(const fib_entry_t *entry);

void print_all_sequences(node_t *head);

void append_fib_list_entry(node_t **head, uint32_t sequence_length);

void set_fib_list_entry(node_t *node, fib_entry_t *data);

const fib_entry_t * get_fib_list_data(node_t *node);

int main(int argc, char const *argv[])
{
    node_t *head = create_fib_list_entry(3);

    for (uint32_t i = 5; i < 12; i++)
    {

        append_fib_list_entry(&head, i);

    }

    remove_fib_list_entry(&head, 3);
    remove_fib_list_entry(&head, 8);

    print_all_sequences(head);

    while (head)
    {
        fib_entry_t * data = pop_node(&head, sizeof(fib_entry_t));

        free(data->sequence);

        free(data);
    }
    
    return 0;
}

const fib_entry_t create_fib_entry(uint32_t sequence_length)
{
    fib_entry_t entry = {};

    entry.sequence_length = sequence_length;

    if (sequence_length <= 1)
    {
        fprintf(stderr, "Can't have a sequence of 1 or lower\n\r");
        return entry;
    }
    else if (sequence_length == 2)
    {
        entry.sequence = calloc(4, sizeof(char));
        memcpy(entry.sequence, FIB_BASE, 3);

        return entry;
    }
    else if (sequence_length > 2)
    {
        char *number_digits = calloc((sequence_length - FIB_CALC_START), sizeof(char));
        uint64_t *number = calloc((sequence_length - FIB_CALC_START), sizeof(uint64_t));

        RETURN_VAL_ON_NO_MEM(number_digits, "error, couldn't allocate memory!\n\r", entry);
        RETURN_VAL_ON_NO_MEM(number, "error, couldn't allocate memory!\n\r", entry);

        // starting values of fibonacci sequence
        uint64_t a = 0, b = 1;

        // taking taking the dashes in the string into account plus the terminator value \0
        uint32_t s_len = sequence_length + 2;

        // calculate the fibonacci sequence plus the length of the number
        for (uint32_t i = 0; i < (sequence_length - FIB_CALC_START); i++)
        {
            number[i] = a + b;

            number_digits[i] = (char)(floor(log10(number[i])) + 1);

            s_len += number_digits[i];

            a = b;
            b = number[i];
        }

        // allocate necessary memory
        entry.sequence = calloc(s_len, sizeof(char));

        RETURN_VAL_ON_NO_MEM(entry.sequence, "error, couldn't allocate memory!\n\r", entry);

        // copy initial string of fibonacci sequence
        memcpy(entry.sequence, FIB_BASE, 4);

        char *seq = entry.sequence + 4;

        for (uint32_t i = 0; i < (sequence_length - FIB_CALC_START); i++)
        {

#ifdef __linux
            sprintf(seq, "%llu", number[i]);
#elif __WIN32
            sprintf(seq, "%I64u", number[i]);
#endif
            uint32_t n_len = number_digits[i];

            seq += n_len;

            if (i < (sequence_length - FIB_CALC_START - 1))
                *seq = '-';

            seq++;

            // free(tmp);
        }

        free(number);
        free(number_digits);
    }

    return entry;
}

node_t * create_fib_list_entry(uint32_t sequence_length)
{
    fib_entry_t entry = create_fib_entry(sequence_length);

    node_t *node = create_node(sizeof(fib_entry_t));
    
    set_fib_list_entry(node, &entry);
    
    return node;
}

void set_fib_list_entry(node_t *node, fib_entry_t *data)
{
    set_node_data(node, data, sizeof(fib_entry_t));
}

const fib_entry_t * get_fib_list_data(node_t *node)
{
    return get_node_data(node);
}

void append_fib_list_entry(node_t **head, uint32_t sequence_length)
{
    node_t *node = create_fib_list_entry(sequence_length);

    append_node(head, node);
}

void remove_fib_list_entry(node_t **head, uint32_t sequence_length)
{
    node_t *curr = *head;
    node_t *prev = NULL;

    while (curr)
    {
        const fib_entry_t *data = get_node_data(curr);

        if(data->sequence_length == sequence_length)
        {
            if(prev)
                set_next_node(prev, get_next_node(curr));
            else
                *head = get_next_node(curr);

            fib_entry_t *tmp = delete_node(curr, sizeof(fib_entry_t));

            free(tmp->sequence);
            free(tmp);

            return;
        }
        else
        {
            prev = curr;
            curr = get_next_node(curr);
        }
    }
    
}

void print_sequence(const fib_entry_t *entry)
{
    printf("sequence length: %d\t sequence: %s\n\r", entry->sequence_length, entry->sequence);
}

void print_all_sequences(node_t *head)
{
    while (head)
    {
        const fib_entry_t * data = get_fib_list_data(head);
        print_sequence(data);

        head = get_next_node(head);
    }
    
}