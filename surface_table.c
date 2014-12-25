
#include <SDL.h>
#include <string.h>

#define SURFACE_TABLE_SIZE 20
#define PIC_NAME_MAX_LEN 32

typedef struct {
    SDL_Surface *surface;
    char pic_name[PIC_NAME_MAX_LEN];
} SurfaceEntry;

static SurfaceEntry surface_table[SURFACE_TABLE_SIZE];

SDL_Surface * ST_get_surface(int index) {
    assert(0 <= index && index < SURFACE_TABLE_SIZE);
    if(surface_table[index].surface == NULL){
        
    }
    return surface_table[index].surface;
};

void ST_add_surface(int index, const SDL_Surface *surface,
        const char * pic_name){
    assert(0 <= index && index < SURFACE_TABLE_SIZE);
    surface_table[index].surface = surface;
    strncpy(surface_table[index].pic_name, pic_name, PIC_NAME_MAX_LEN);
}

void ST_init(char* [] pic_names, size_t count){
    /* for each picname */
    /* add to ST_table from 0 */
    int i = 0;
    for(; i < count; i++){
        surface_table[i].surface = NULL;
        strncpy(surface_table[i].pic_name, pic_names[i],
                PIC_NAME_MAX_LEN);
    }
}
