#ifndef __SDL__SYS__H__
#define __SDL__SYS__H__
#include <SDL.h>
#include <SDL_image.h>
#include "util.h"

typedef struct {
    SDL_Surface *screen;
    
} SdlSystem;

bool SS_init(SdlSystem *ss, size_t win_width, size_t win_height, const char *win_title);

SDL_Surface * SS_load_pic(const char *path);
void SS_set_colorkey(SDL_Surface *surface, Uint32 color);
void SS_draw(SdlSystem *ss, SDL_Surface *src_surface, SDL_Rect *src_rect, SDL_Rect *dest_rect);
void SS_update_screen(SdlSystem *ss);

#endif
