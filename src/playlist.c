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
    song_info_t data = {};

    data.title = calloc(strlen(song) + 1, sizeof(char));
    data.artist = calloc(strlen(artist) + 1, sizeof(char));

    strcpy(data.title, song);
    strcpy(data.artist, artist);

    return data;
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

void append_playlist_item(playlist_item_t **playlist, char * song, char * artist)
{
    playlist_item_t * node = create_playlist_item();

    song_info_t data = create_song_info(song, artist);

    set_node_data(node, &data, sizeof(song_info_t));

    append_node(playlist, node);
}

void prepend_playlist_item(playlist_item_t **playlist, char * song, char * artist)
{
    playlist_item_t * item = create_playlist_item();

    song_info_t data = create_song_info(song, artist);

    set_node_data(item, &data, sizeof(song_info_t));

    prepend_node(playlist, item);
}

void insert_playlist_item(playlist_item_t **playlist, uint32_t index, char * song, char * artist)
{
    playlist_item_t * item = create_playlist_item();

    song_info_t data = create_song_info(song, artist);

    set_node_data(item, &data, sizeof(song_info_t));

    insert_node(playlist, item, index);
}

playlist_item_t * get_playlist_item_by_index(playlist_item_t *playlist, uint32_t index)
{
    return get_node_by_index(playlist, index);
}

playlist_item_t * get_playlist_item_song(playlist_item_t *playlist, char * song_name)
{

    while (1)
    {
        const song_info_t * data = get_node_data(playlist);

        if(strcmp(data->title, song_name) != 0)
            break;

        playlist = get_next_node(playlist);

        RETURN_VAL_ON_NO_MEM(playlist, "reached end of list\n", NULL);
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

void set_playlist_item_data(playlist_item_t *playlist_item, song_info_t *src)
{
    set_node_data(playlist_item, src, sizeof(song_info_t));
}

void play_next(playlist_item_t **playlist)
{
    playlist_item_t * next = get_next_node(*playlist);
    song_info_t * info = delete_node(*playlist, sizeof(song_info_t));

    print_song_info(info);

    clean_song_info(info);

    *playlist = next;
}

void print_song_info(const song_info_t * song_info)
{
    printf("%s by %s\n\r", song_info->title, song_info->artist);
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
    const song_info_t * info = get_node_data(playlist);

    print_song_info(info);
}

void pop_playlist(playlist_item_t **playlist)
{
    clean_song_info(pop_node(playlist, sizeof(song_info_t)));
}