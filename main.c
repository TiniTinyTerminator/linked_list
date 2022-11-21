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

node_t * create_fib_list_entry();

void set_fib_list_entry(node_t *node, fib_entry_t *data);

const fib_entry_t * get_fib_list_data(node_t *node);

int main(int argc, char const *argv[])
{
    node_t *head = NULL;

    for (uint32_t i = 5; i < 1000; i++)
    {
        fib_entry_t entry = create_fib_entry(i);

        node_t *node = create_fib_list_entry();

        set_fib_list_entry(node, &entry);

        append_node(&head, node);

        printf("%s\n\r", entry.sequence);
    }
    
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

    // RETURN_VAL_ON_NO_MEM(entry, "error, couldn't allocate memory!\n\r", NULL);

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

node_t * create_fib_list_entry()
{
    node_t *node = create_node(sizeof(fib_entry_t));
    
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

