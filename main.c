/* usage: gcc -o game main.c `sdl-config --cflags --libs` */
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char *argv[])
{
    /* Before calling other SDL functions, you should SDL_Init first */
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        /* SDL_GetError get the information of last SDL Error, return a
         * null terminated string */
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    /* SDL_Quit will shut down SDL subsystems */
    atexit(SDL_Quit);

    /* SDL_Surface *SDL_SetVideoMode(int width, int height, int bpp, Uint32 flags); */
    /* bpp = bits per pixel. If bpp is 0, it is treated as the current
     * display bits per pixel. */
    /* SDL_SWSURFACE, Create the video surface in system memory */
    /* SDL_HWSURFACE, Create the video surface in video memory */
    /* SDL_DOUBLEBUF, Enable double buffering, you can use SDL_Flip to update screen */
    /* SDL_FULLSCREEN, full screen mode */
    /* return NULL on Setting Video Mode fail */
    SDL_Surface *screen = SDL_SetVideoMode(800, 600, 0, SDL_HWSURFACE|SDL_DOUBLEBUF);

    if (screen == NULL) {
        printf("Unable to set video mode: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_WM_SetCaption("Hello, Linux Game!", NULL);

    SDL_Surface *temp = IMG_Load("card-panel.png");
    SDL_Surface *panel_surface = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    SDL_SetColorKey(panel_surface, SDL_SRCCOLORKEY|SDL_RLEACCEL, 0);

    SDL_Rect enemy_fig_rect = {330, 5, 107, 139};
    SDL_Rect player_fig_rect = {330, 447, 107, 139};

    temp = IMG_Load("sword-man.png");
    SDL_Surface *swordman_surface = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    SDL_BlitSurface(swordman_surface, NULL, screen, &enemy_fig_rect);

    temp = IMG_Load("blade-man.png");
    SDL_Surface *blademan_surface = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    SDL_BlitSurface(blademan_surface, NULL, screen, &player_fig_rect);

    SDL_BlitSurface(panel_surface, NULL, screen, NULL);

    temp = IMG_Load("action-point.png");
    SDL_Surface *action_point_surface = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    SDL_SetColorKey(action_point_surface, SDL_SRCCOLORKEY|SDL_RLEACCEL, 0);

    SDL_Rect ball_src_rect = {0, 0, 25, 25};
    int i;
    SDL_Rect ball_dest_rect = {10, 85, 25, 25};
    for(i = 0; i < 12; i ++){
        SDL_BlitSurface(action_point_surface, &ball_src_rect, screen, &ball_dest_rect);
        ball_dest_rect.x += 25;
    }

    ball_src_rect.x = 25;
    ball_dest_rect.x = 12;
    ball_dest_rect.y = 489;
    /* 13, 489 */
    for(i = 0; i < 12; i ++){
        SDL_BlitSurface(action_point_surface, &ball_src_rect, screen, &ball_dest_rect);
        ball_dest_rect.x += 25;
    }
    
    SDL_Flip(screen);
    /* To pause the program */
    getchar();
    return 0;
}
