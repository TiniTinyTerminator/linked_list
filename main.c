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

#include "playlist.h"

int main(int argc, char const *argv[])
{
    time_t t;

    srand(time(&t));

    playlist_item_t * playlist = create_playlist_item();
    
    song_info_t first = create_song_info("cuff it", "Beyonce");

    change_song_info(&first, "put a ringo on it", "Beyonce");

    set_playlist_item_data(playlist, &first);

    first = create_song_info("hello", "adele");

    append_playlist_item(&playlist, &first);

    first = create_song_info("PRAY", "Kendrick lamar");
    prepend_playlist_item(&playlist, &first);
    first = create_song_info("WIN", "Jay Rock");

    insert_playlist_item(&playlist, 1, &first);
    
    playlist_item_t * third = get_playlist_item_by_index(playlist, 3);

    print_playlist_item(third);

    print_playlist(playlist);

    while (playlist != NULL)
    {
        pop_playlist(&playlist);
    }
    

    return 0;
}
