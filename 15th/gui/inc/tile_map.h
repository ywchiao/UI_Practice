
#ifndef __TILE_MAP_H__
#define __TILE_MAP_H__

#include <map>
#include <string>

#include "SDL.h"

std::map<std::string, SDL_Rect> tile_map = {
    { "barn", { 96, 0, 80, 80 } },
    { "barn-back", { 176, 0, 80, 80 } },
    { "booth", { 288, 350, 80, 96 } },
    { "fountain", { 352, 144, 48, 48 } },
    { "flower", { 48, 176, 16, 16 } },
    { "grass", { 0, 0, 16, 16 } },
    { "tree", { 80, 256, 32, 32 } },
};


#endif
