/**
 * @file playlist.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "playlist.h"

#include "single_list.h"

#include <stdlib.h>
#include <string.h>

playlist_item_t * create_playlist_item()
{
    node_t * new_node = create_node(sizeof(song_info_t));

    return new_node;
}

song_info_t create_song_info(char * song, char * artist)
{
    song_info_t data = {
        calloc(strlen(song) + 1, sizeof(char)),
        calloc(strlen(artist) + 1, sizeof(char))
    };

    strcpy(data.title, song);
    strcpy(data.artist, artist);

    return data;
}

void change_song_info(song_info_t *info, char * song, char * artist)
{
    clean_song_info(info);
            
    info->title = calloc(strlen(song) + 1, sizeof(char));
    info->artist = calloc(strlen(artist) + 1, sizeof(char));

    strcpy(info->title, song);
    stpcpy(info->artist, artist);
}

void clean_song_info(song_info_t * info)
{
    free(info->artist);
    free(info->title);
}

void copy_song_info(song_info_t * src, song_info_t * dest)
{
    dest->title = calloc(strlen(src->title) + 1, sizeof(char));
    dest->artist = calloc(strlen(src->artist) + 1, sizeof(char));

    strcpy(dest->title, src->title);
    strcpy(dest->artist, dest->artist);
}

void append_playlist_item(playlist_item_t **playlist, song_info_t * info)
{
    playlist_item_t * node = create_playlist_item();

    // song_info_t data = create_song_info(song, artist);

    set_node_data(node, info, sizeof(song_info_t));

    append_node(playlist, node);
}

void prepend_playlist_item(playlist_item_t **playlist, song_info_t * info)
{
    playlist_item_t * item = create_playlist_item();

    // song_info_t data = create_song_info(song, artist);

    set_node_data(item, info, sizeof(song_info_t));

    prepend_node(playlist, item);
}

void insert_playlist_item(playlist_item_t **playlist, uint32_t index, song_info_t * info)
{
    playlist_item_t * item = create_playlist_item();

    // song_info_t data = create_song_info(song, artist);

    set_node_data(item, info, sizeof(song_info_t));

    insert_node(playlist, item, index);
}

playlist_item_t * get_playlist_item_by_index(playlist_item_t *playlist, uint32_t index)
{
    return get_node_by_index(playlist, index);
}

playlist_item_t * get_playlist_item_by_song(playlist_item_t *playlist, char * song_name)
{

    while (playlist != NULL)
    {
        const song_info_t * data = get_node_data(playlist);

        if(strcmp(data->title, song_name) == 0)
            break;

        playlist = get_next_node(playlist);

        // RETURN_VAL_ON_NO_MEM(playlist, "reached end of list\n", NULL);
    }
    
    return playlist;
}

playlist_item_t * get_playlist_item_by_artist(playlist_item_t *playlist, char * artist_name)
{

    while (playlist != NULL)
    {
        const song_info_t * data = get_node_data(playlist);

        if(strcmp(data->artist, artist_name) == 0)
            break;

        playlist = get_next_node(playlist);

        // RETURN_VAL_ON_NO_MEM(playlist, "reached end of list\n", NULL);
    }
    
    return playlist;
}

const song_info_t * get_playlist_item_data(playlist_item_t *playlist)
{
    return get_node_data(playlist);
}

void copy_playlist_item_data(playlist_item_t *playlist_item, song_info_t *dest)
{
    copy_node_data(playlist_item, dest, sizeof(song_info_t));
}

void set_playlist_item_data(playlist_item_t *playlist_item, const song_info_t *src)
{
    set_node_data(playlist_item, src, sizeof(song_info_t));
}

void play_next(playlist_item_t **playlist)
{
    playlist_item_t * next = get_next_node(*playlist);
    song_info_t * data = delete_node(*playlist, sizeof(song_info_t));

    print_song_info(data);

    clean_song_info(data);

    free(data);

    *playlist = next;
}

void print_song_info(const song_info_t * song_info)
{
    printf("\"%s\" by %s\n\r", song_info->title, song_info->artist);
}

void print_playlist(playlist_item_t *playlist)
{
    while(playlist != NULL)
    {
        print_playlist_item(playlist);

        playlist = get_next_node(playlist);
    }
}

void print_playlist_item(playlist_item_t *playlist)
{
    const song_info_t * data = get_node_data(playlist);

    print_song_info(data);
}

void pop_playlist(playlist_item_t **playlist)
{
    song_info_t *data = pop_node(playlist, sizeof(song_info_t));

    clean_song_info(data);

    free(data);
}


void remove_playlist_item_by_index(playlist_item_t **playlist, uint32_t index)
{
    song_info_t *data = remove_node_by_index(playlist, index, sizeof(song_info_t));

    clean_song_info(data);
    
    free(data);
}

void remove_playlist_item_by_song_name(playlist_item_t **playlist, char * song_name)
{
    playlist_item_t *item = *playlist;
    playlist_item_t *prev = NULL;

    while (item != NULL)
    {
        const song_info_t * data = get_node_data(item);

        if(strcmp(data->title, song_name) == 0)
            break;

        prev = item;
        item = get_next_node(item);

        // RETURN_VAL_ON_NO_MEM(playlist, "reached end of list\n", NULL);
    }

    if(item == *playlist)
        *playlist = get_next_node(*playlist);
    if(prev)
        set_next_node(prev, get_next_node(item));

    song_info_t *data = delete_node(item, sizeof(song_info_t));

    clean_song_info(data);

    free(data);
}


void remove_playlist_item_by_artist_name(playlist_item_t **playlist, char * artist_name)
{
    playlist_item_t *item = *playlist;
    playlist_item_t *prev = NULL;

    while (item != NULL)
    {
        const song_info_t * data = get_node_data(item);

        if(strcmp(data->artist, artist_name) == 0)
            break;

        prev = item;
        item = get_next_node(item);

        // RETURN_VAL_ON_NO_MEM(playlist, "reached end of list\n", NULL);
    }

    if(item == *playlist)
        *playlist = get_next_node(*playlist);
    if(prev)
        set_next_node(prev, get_next_node(item));

    song_info_t *data = delete_node(item, sizeof(song_info_t));

    clean_song_info(data);

    free(data);
}