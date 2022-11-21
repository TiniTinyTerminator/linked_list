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
// tested
song_info_t create_song_info(char * song, char * artist);
// done
// tested
void change_song_info(song_info_t *info, char * song, char * artist);
// done
// tested
void clean_song_info(song_info_t * info);
// done
// tested
void print_song_info(const song_info_t * song_info);
// done
// tested
playlist_item_t *create_playlist_item();
// done
// tested
void print_playlist(playlist_item_t *playlist);
// done
// tested
void print_playlist_item(playlist_item_t *playlist);
// done
// tested
void append_playlist_item(playlist_item_t **playlist, song_info_t * info);
// done
// tested
void prepend_playlist_item(playlist_item_t **playlist, song_info_t * info);
// done
// tested
void insert_playlist_item(playlist_item_t **playlist, uint32_t index, song_info_t * info);
// done
// tested
playlist_item_t * get_playlist_item_by_index(playlist_item_t *playlist, uint32_t index);
// done
playlist_item_t * get_playlist_item_by_song(playlist_item_t *playlist, char * song_name);
// done
playlist_item_t * get_playlist_item_by_artist(playlist_item_t *playlist, char * song_name);
// done
// tested
const song_info_t * get_playlist_item_data(playlist_item_t *playlist);
// done
// tested
void copy_playlist_item_data(playlist_item_t *playlist_item, song_info_t *dest);
// done
// tested
void set_playlist_item_data(playlist_item_t *playlist, const song_info_t *src);
// done
// tested
void play_next(playlist_item_t **playlist);
// done
// tested
void pop_playlist(playlist_item_t **playlist);
// done
// tested
void remove_playlist_item_by_index(playlist_item_t **playlist, uint32_t index);
// done
// tested
void remove_playlist_item_by_song_name(playlist_item_t **playlist, char * song_name);
// done
// tested
void remove_playlist_item_by_artist_name(playlist_item_t **playlist, char * artist_name);
// done 
// tested
void flush_playlist(playlist_item_t **playlist);