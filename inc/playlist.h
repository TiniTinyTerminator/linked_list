/**
 * @file playlist.h
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

typedef struct node playlist_item_t;

typedef struct song_info
{
    char * title;
    char * artist;
} song_info_t;

// done
song_info_t create_song_info(char * song, char * artist);
// done
void clean_song_info(song_info_t * info);
// done
void print_song_info(const song_info_t * song_info);
// done
playlist_item_t *create_playlist_item();
// done
void print_playlist(playlist_item_t *playlist);
// done
void print_playlist_item(playlist_item_t *playlist);
// done
void append_playlist_item(playlist_item_t **playlist, char * song, char * artist);
// done
void prepend_playlist_item(playlist_item_t **playlist, char * song, char * artist);
// done
void insert_playlist_item(playlist_item_t **playlist, uint32_t index, char * song, char * artist);
// done
playlist_item_t * get_playlist_item_by_index(playlist_item_t *playlist, uint32_t index);
// done
playlist_item_t * get_playlist_item_song(playlist_item_t *playlist, char * song_name);
// done
const song_info_t * get_playlist_item_data(playlist_item_t *playlist);
// done
void copy_playlist_item_data(playlist_item_t *playlist_item, song_info_t *dest);
// done
void set_playlist_item_data(playlist_item_t *playlist, song_info_t *src);
// done
void play_next(playlist_item_t **playlist);
// onde
void pop_playlist(playlist_item_t **playlist);

void remove_playlist_item_by_index(playlist_item_t **playlist, uint32_t index);

void remove_playlist_item_by_song_name(playlist_item_t **playlist, char * song_name);

void remvoe_playlist_item_by_artist_name(playlist_item_t **playlist, char * artist_name);