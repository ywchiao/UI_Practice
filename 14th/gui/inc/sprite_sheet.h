
#ifndef __SPRITE_SHEET_H__
#define __SPRITE_SHEET_H__

#include <string>

#include "SDL.h"

class SpriteSheet {
    public:
        SpriteSheet(SDL_Renderer *const, std::string const&);
        ~SpriteSheet();

    public:
        void tile(SDL_Renderer *const, SDL_Rect const *, SDL_Rect const *);
        void dimension(int &, int &);

    private:
        SDL_Texture *texture_;
};

#endif

// sprite_sheet.h
