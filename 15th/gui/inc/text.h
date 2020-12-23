
#ifndef __TEXT_H__
#define __TEXT_H__

#include <map>
#include <string>

#include "SDL.h"
#include "SDL_ttf.h"

class Text {
    public:
        Text(const std::string&);
        ~Text();

    public:
        SDL_Texture *get_text(SDL_Renderer *, std::string const&);

    private:
        TTF_Font *font_;

        std::map<std::string const, SDL_Texture *> text_;
};

#endif

// text.h
