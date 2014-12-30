#include "sdl_sys.h"

bool SS_init(SdlSystem *ss, size_t win_width, size_t win_height, const char *win_title)
{
    ss->screen = NULL;

    /* Before calling other SDL functions, you should SDL_Init first */
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        /* SDL_GetError get the information of last SDL Error, return a
         * null terminated string */
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return FALSE;
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
    ss->screen = SDL_SetVideoMode(win_width, win_height, 0, SDL_HWSURFACE|SDL_DOUBLEBUF);

    if (ss->screen == NULL) {
        printf("Unable to set video mode: %s\n", SDL_GetError());
        return FALSE;
    }

    SDL_WM_SetCaption(win_title, NULL);
    return TRUE;
}

SDL_Surface * SS_load_pic(const char *path)
{
    SDL_Surface *temp = IMG_Load(path);
    if(temp == NULL){
        return NULL;
    }

    SDL_Surface *surface = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    return surface;
}

void SS_set_colorkey(SDL_Surface *surface, Uint32 color)
{
    SDL_SetColorKey(surface, SDL_SRCCOLORKEY|SDL_RLEACCEL, color);
}

void SS_draw(SdlSystem *ss, SDL_Surface *src_surface, SDL_Rect *src_rect, SDL_Rect *dest_rect)
{
    SDL_BlitSurface(src_surface, src_rect, ss->screen, dest_rect);
}

void SS_update_screen(SdlSystem *ss)
{
    SDL_Flip(ss->screen);
}
