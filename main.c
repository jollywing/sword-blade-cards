/* usage: gcc -o game main.c `sdl-config --cflags --libs` */
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "sdl_sys.h"

int main(int argc, char *argv[])
{
    SdlSystem ss;

    if(SS_init(&ss, 800, 600, "Card Heroes") == FALSE){
        printf("SDL system init failed!\n");
        exit(1);
    }


    SDL_Rect enemy_fig_rect = {330, 5, 107, 139};
    SDL_Rect player_fig_rect = {330, 447, 107, 139};

    SDL_Surface *swordman_surface = SS_load_pic("sword-man.png");
    SS_draw(&ss, swordman_surface, NULL, &enemy_fig_rect);

    SDL_Surface *blademan_surface = SS_load_pic("blade-man.png");
    SS_draw(&ss, blademan_surface, NULL, &player_fig_rect);

    SDL_Surface *panel_surface = SS_load_pic("card-panel.png");
    SS_draw(&ss, panel_surface, NULL, NULL);

    SDL_Surface *action_point_surface = SS_load_pic("action-point.png");
    SS_set_colorkey(action_point_surface, 0);

    SDL_Rect ball_src_rect = {0, 0, 25, 25};
    int i;
    SDL_Rect ball_dest_rect = {10, 85, 25, 25};
    for(i = 0; i < 12; i ++){
        SS_draw(&ss, action_point_surface, &ball_src_rect, &ball_dest_rect);
        ball_dest_rect.x += 25;
    }

    ball_src_rect.x = 25;
    ball_dest_rect.x = 12;
    ball_dest_rect.y = 489;
    /* 13, 489 */
    for(i = 0; i < 12; i ++){
        SS_draw(&ss, action_point_surface, &ball_src_rect, &ball_dest_rect);
        ball_dest_rect.x += 25;
    }
    
    SS_update_screen(&ss);

    SDL_Surface *card_surface = SS_load_pic("card.png");
    SS_set_colorkey(card_surface, 0);

    bool running;
    SDL_Event event;
    /* To pause the program */
    while(running){
        SDL_PollEvent(&event);
        switch(event.type){
        case SDL_QUIT:
            running = FALSE;
        }

        SDL_Delay(100);
    }
    return 0;
}
