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

/**
 * @brief allocates memory for the song title and artist
 * 
 * @param song the name of the song
 * @param artist the name of the artist
 * @return song_info_t a struct with pointers to the song title and artist
 */
song_info_t create_song_info(char * song, char * artist);

/**
 * @brief edit the information of the song title and artist
 * 
 * @param info struct to be edited
 * @param song new song name
 * @param artist new song artist
 */
void change_song_info(song_info_t *info, char * song, char * artist);

/**
 * @brief free the allocated memory in the struct
 * 
 * @param info struct with pointers to memory to be freed
 */
void clean_song_info(song_info_t * info);

/**
 * @brief print the information of the song 
 * 
 * @param song_info information to be printed
 */
void print_song_info(const song_info_t * song_info);

/**
 * @brief Create a playlist item object
 * 
 * @return playlist_item_t* returns a pointer to allocated memory
 */
playlist_item_t *create_playlist_item();

/**
 * @brief print the complete playlist
 * 
 * @param playlist head of the playlist
 * 
 * @note can be used on child playlist item but will print from that position in the list
 */
void print_playlist(playlist_item_t *playlist);

/**
 * @brief print a single playlist item
 * 
 * @param item item to be printed 
 */
void print_playlist_item(playlist_item_t *item);

/**
 * @brief append an item to the playlist
 * 
 * @param playlist head of the playlist
 * @param info new song to be added
 */
void append_playlist_item(playlist_item_t **playlist, song_info_t * info);

/**
 * @brief prepend song to the playlist
 * 
 * @param playlist head of the playlist
 * @param info new song to be added
 */
void prepend_playlist_item(playlist_item_t **playlist, song_info_t * info);

/**
 * @brief insert a new song at a specific index in the playlist
 * 
 * @param playlist playlist to be inserted in
 * @param index index of the new song
 * @param info the new song to be added
 */
void insert_playlist_item(playlist_item_t **playlist, uint32_t index, song_info_t * info);

/**
 * @brief Get the playlist item by index 
 * 
 * @param playlist head of the playlist
 * @param index index to be picked
 * @return playlist_item_t* returns a pointer to the playlist item. if out of reach returns NULL
 */
playlist_item_t * get_playlist_item_by_index(playlist_item_t *playlist, uint32_t index);

/**
 * @brief Get the playlist item by song name
 * 
 * @param playlist head of the playlist
 * @param song_name song name to be picked
 * @return playlist_item_t* returns a pointer to the playlist item. if out of reach returns NULL
 */
playlist_item_t * get_playlist_item_by_song(playlist_item_t *playlist, char * song_name);

/**
 * @brief Get the playlist item by song name
 * 
 * @param playlist head of the playlist
 * @param artist_name artist name to be picked
 * @return playlist_item_t* returns a pointer to the playlist item. if out of reach returns NULL
 */
playlist_item_t * get_playlist_item_by_artist(playlist_item_t *playlist, char * artist_name);

/**
 * @brief Get the playlist item data object
 * 
 * @param playlist playlist item to get it from
 * @return const song_info_t* direct pointer to information held in the playlist item
 */
const song_info_t * get_playlist_item_data(playlist_item_t *playlist);

/**
 * @brief copy the information from the playlist item to the song info object
 * 
 * @param playlist_item playlist item to be copied from
 * @param dest destination for data
 */
void copy_playlist_item_data(playlist_item_t *playlist_item, song_info_t *dest);

/**
 * @brief Set the playlist item data object
 * 
 * @param playlist playlist item to be edited
 * @param src src for new information
 */
void set_playlist_item_data(playlist_item_t *playlist, const song_info_t *src);

/**
 * @brief play the next song
 * 
 * @param playlist head of the playlist
 */
void play_next(playlist_item_t **playlist);

/**
 * @brief delete the last item in the playlist
 * 
 * @param playlist head of the playlist
 */
void pop_playlist(playlist_item_t **playlist);

/**
 * @brief remove an item from the playlist by index
 * 
 * @param playlist head of the playlist
 * @param index index to be removed
 */
void remove_playlist_item_by_index(playlist_item_t **playlist, uint32_t index);

/**
 * @brief remove an item from the playlist by song name
 * 
 * @param playlist head of the playlist
 * @param song_name song to be removed
 * 
 * @note only removes the first match
 */
void remove_playlist_item_by_song_name(playlist_item_t **playlist, char * song_name);

/**
 * @brief remove an item from the playlist by song artist
 * 
 * @param playlist head of the playlist
 * @param song_name artist to be removed
 * 
 * @note only removes the first match
 */
void remove_playlist_item_by_artist_name(playlist_item_t **playlist, char * artist_name);

/**
 * @brief flush the whole playlist
 * 
 * @param playlist playlist to be flushed
 */
void flush_playlist(playlist_item_t **playlist);