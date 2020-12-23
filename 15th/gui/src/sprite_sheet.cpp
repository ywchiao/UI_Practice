
#include "SDL_image.h"

#include "sprite_sheet.h"

// 函數 (方法) 的實作 (implementations)

/**
 *  SpriteSheet constructor.  Initialize the TrueType font (ttf) used.
 *
 *  @param const& string: the font name.
 *  @return none.
 *  @since  0.1.0
 **/
SpriteSheet::SpriteSheet(
    SDL_Renderer *const renderer, std::string const& fname
) {
    SDL_Surface *image = nullptr;

    image = IMG_Load(fname.c_str());

    if (image == nullptr) {
        SDL_Log(SDL_GetError());
    } // fi

    texture_ = SDL_CreateTextureFromSurface(renderer, image);

    SDL_FreeSurface(image);
} // SpriteSheet::SpriteSheet()

/**
 *  SpriteSheet destructor.
 *
 *  @param none.
 *  @return none.
 *  @since  0.1.0
 **/
SpriteSheet::~SpriteSheet() {
    SDL_DestroyTexture(texture_);
} // SpriteSheet::~SpriteSheet()

void SpriteSheet::dimension(int &width, int &height) {
    SDL_QueryTexture(texture_, nullptr, nullptr, &width, &height);
} // SpriteSheet::dimension()

/**
 *  Render, Create and Return a sprite_sheeture of the passed-in string.
 *
 *  @param SDL_Renderer *: The Renderer.
 *  @param const& string: The string to be rendered.
 *  @return none.
 *  @since  0.1.0
 **/
void SpriteSheet::tile(
    SDL_Renderer *const renderer, SDL_Rect const *src, SDL_Rect const *dst
) {
    SDL_RenderCopy(renderer, texture_, src, dst);
} // SpriteSheet::get_sprite_sheet

// sprite_sheet.cpp
