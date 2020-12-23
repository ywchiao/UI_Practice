
#ifndef __OUTSIDE_H__
#define __OUTSIDE_H__

#include <map>
#include <string>

#include "SDL.h"

#include "sprite_sheet.h"

class Outside {
    public:
        Outside(SDL_Renderer *);
        ~Outside();

    public:
        void barn(SDL_Renderer *, SDL_Rect *);
        void barn_back(SDL_Renderer *, SDL_Rect *);
        void booth(SDL_Renderer *, SDL_Rect *);
        void dirt(SDL_Renderer *, SDL_Rect *);
        void fence_h_16(SDL_Renderer *, SDL_Rect *);
        void fence_h_24(SDL_Renderer *, SDL_Rect *);
        void fence_v_16(SDL_Renderer *, SDL_Rect *);
        void fence_v_24(SDL_Renderer *, SDL_Rect *);
        void fountain(SDL_Renderer *, SDL_Rect *);
        void flower(SDL_Renderer *, SDL_Rect *);
        void grass(SDL_Renderer *, SDL_Rect *);
        void stump(SDL_Renderer *, SDL_Rect *);
        void timber(SDL_Renderer *, SDL_Rect *);
        void tree(SDL_Renderer *, SDL_Rect *);
        void water(SDL_Renderer *, SDL_Rect *);

        void tile(std::string const&, SDL_Renderer *, SDL_Rect *);

    private:
        void tile_(SDL_Renderer *, SDL_Rect *, SDL_Rect *);

    private:
        SpriteSheet sheet_;

        std::map<
            std::string, void (Outside::*)(SDL_Renderer *, SDL_Rect *)
        > table_;
};

#endif

// outside.h
