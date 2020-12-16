
#include "text.h"

// 函數 (方法) 的實作 (implementations)

/**
 *  Text constructor.  Initialize the TrueType font (ttf) used.
 *
 *  @param const& string: the font name.
 *  @return none.
 *  @since  0.1.0
 **/
Text::Text(std::string const& font): font_{ nullptr } {
    font_ = TTF_OpenFont(font.c_str(), 48);

    if (font_ == nullptr) {
        SDL_Log(SDL_GetError());
    } // fi

    TTF_SetFontStyle(font_, TTF_STYLE_NORMAL);
    TTF_SetFontOutline(font_, 0);
    TTF_SetFontKerning(font_, 1);
    TTF_SetFontHinting(font_, TTF_HINTING_NORMAL);
} // Text::Text()

/**
 *  Text destructor.
 *
 *  @param none.
 *  @return none.
 *  @since  0.1.0
 **/
Text::~Text() {
    for (auto& text : text_) {  // free All texture created.
        SDL_DestroyTexture(text.second);
    } // od

    TTF_CloseFont(font_);
} // Text::~Text()

/**
 *  Render, Create and Return a texture of the passed-in string.
 *
 *  @param SDL_Renderer *: The Renderer.
 *  @param const& string: The string to be rendered.
 *  @return none.
 *  @since  0.1.0
 **/
SDL_Texture *Text::get_text(SDL_Renderer *renderer, std::string const& text) {
    SDL_Color color = { 0xff, 0xff, 0xff, 0x0 };

    SDL_Texture *texture = nullptr;

    auto it { text_.find(text) };

    if (it != std::end(text_)) {
        texture = it->second;
    }
    else {
        SDL_Surface *surface = nullptr;

        surface = TTF_RenderUTF8_Solid(font_, text.c_str(), color);

        texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_FreeSurface(surface);

        text_[text] = texture;
    }

    return texture;
} // Text::get_text

// text.cpp
