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
#include "playlist.h"

#define MAX_STR_LEN 255

#define PLAY_NEXT 1
#define ADD_SONG 2
#define REMOVE_SONG 3
#define PRINT_LIST 4
#define EXIT_APP 5

void add_new_song(playlist_item_t **playlist);

void remove_song(playlist_item_t **playlist);

int main(int argc, char const *argv[])
{
    struct node * playlist = create_playlist_item();

    song_info_t info = create_song_info("New York","Jay-z, Alicia Keys");

    set_playlist_item_data(playlist, &info);

    info = create_song_info("because you move me","thinlicker");

    append_playlist_item(&playlist, &info);

    info = create_song_info("Finish line","Lissa");

    append_playlist_item(&playlist, &info);
    
    info = create_song_info("Last Moment","Patrick Aretz");

    append_playlist_item(&playlist, &info);

    info = create_song_info("Nobody","Does it matter");

    append_playlist_item(&playlist, &info);

    printf("welcome to the playlist creator :D\n\r");

    uint32_t options = 0;

    while(options != EXIT_APP) {
        options = 0;
        printf("please select one of the options below:\n \
        1) play next song\n \
        2) add song to list\n \
        3) remove song from playlist\n \
        4) show the playlist\n \
        5) exit the playlist creator\n");

        scanf(" %d", &options);

        // options = 2;

        switch (options)
        {
        case PLAY_NEXT:
            play_next(&playlist);
            break;
        case ADD_SONG:
            add_new_song(&playlist);
            break;
        case REMOVE_SONG:
            remove_song(&playlist);        
            break;
        case PRINT_LIST:
            print_playlist(playlist);
            break;
        default:
            break;
        }
    }

    flush_playlist(&playlist);

    return 0;
}

#define ADD_BY_INDEX 1
#define ADD_AT_START 2
#define ADD_AT_END 3
#define RETURN_TO_MENU -1

void add_new_song(playlist_item_t **playlist)
{

    char option = 0;

    while (1)
    {
        printf("\nplease select one of the options below:\n \
    1) add at specific index\n \
    2) add at the end of the playlist\n \
    3) add at the start of the playlist\n \
    4) cancel and return to menu\n");

        scanf("%d", &option);
        fflush(stdin);
        if(option == 4) break;
        
        char song_name[MAX_STR_LEN] = "";
        char song_artist[MAX_STR_LEN] = "";

        printf("name of the song: ");
        scanf(" %[^\n]",song_name);
        fflush(stdin);

        printf("name of the artist: ");
        scanf(" %[^\n]",song_artist);
        
        song_info_t info = create_song_info(song_name, song_artist);

        switch (option)
        {
        case ADD_BY_INDEX:
            get_index:

            uint32_t playlist_len = get_node_list_length(*playlist);

            printf("give the index you would like to add the song to [1 to %d]:\t", playlist_len + 1);

            uint32_t index = 0;

            scanf("%d", &index);

            if(index < 1 || index > (playlist_len + 1))
                goto get_index;
            
            if(index == (playlist_len + 1))
                append_playlist_item(playlist, &info);
            else
                insert_playlist_item(playlist, index - 1, &info);
            break;
        case ADD_AT_START:
            prepend_playlist_item(playlist, &info);
            break;
        case ADD_AT_END:
            append_playlist_item(playlist, &info);
            break;
        default:
            break;
        }
    }
    

}

void remove_song(playlist_item_t **playlist)
{

    char option = 0;

    while (1)
    {
        printf("please select one of the options below:\n \
    1) remove at specific index\n \
    2) remove by song name\n \
    3) remove by artist name\n \
    4) cancel and return to menu\n");

        scanf("%d", &option);
        
        if(option == 4) break;
        
        char song_name[MAX_STR_LEN] = "";
        char song_artist[MAX_STR_LEN] = "";

        switch (option)
        {
        case ADD_BY_INDEX:
            get_index:

            uint32_t playlist_len = get_node_list_length(*playlist);

            printf("give the index from the song to be removed [1 to %d]:\t", playlist_len);

            uint32_t index = 0;

            scanf("%d", &index);

            if(index < 1 || index > playlist_len)
                goto get_index;
            
            remove_playlist_item_by_index(playlist, index - 1);
            break;
        case ADD_AT_START:
            printf("name of the song: ");
            scanf(" %[^\n]", song_name);

            remove_playlist_item_by_song_name(playlist, song_name);
            break;
        case ADD_AT_END:
            printf("name of the artist: ");
            scanf(" %[^\n]", song_artist);        

            remove_playlist_item_by_artist_name(playlist, song_artist);
            break;
        default:
            break;
        }
    }
}
