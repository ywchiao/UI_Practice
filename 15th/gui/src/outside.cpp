
#include <functional>

#include "outside.h"

// 函數 (方法) 的實作 (implementations)

/**
 *  Outside constructor.  Initialize the first SDL window and its
 *  renderer.
 *
 *  @param none.
 *  @return none.
 *  @since  0.1.0
 **/
Outside::Outside(SDL_Renderer *renderer):
    sheet_{ renderer, "../resources/png/overworld.png" } {

    table_["barn"] = &Outside::barn;
    table_["barn_back"] = &Outside::barn_back;
    table_["booth"] = &Outside::booth;
    table_["dirt"] = &Outside::dirt;
    table_["fence_h_16"] = &Outside::fence_h_16;
    table_["fence_h_24"] = &Outside::fence_h_24;
    table_["fence_v_16"] = &Outside::fence_v_16;
    table_["fence_v_24"] = &Outside::fence_v_24;
    table_["flower"] = &Outside::flower;
    table_["fountain"] = &Outside::fountain;
    table_["grass"] = &Outside::grass;
    table_["stump"] = &Outside::stump;
    table_["timber"] = &Outside::timber;
    table_["tree"] = &Outside::tree;
    table_["water"] = &Outside::water;
} // Outside::Outside()

/**
 *  Outside destructor.
 *
 *  @param none.
 *  @return none.
 *  @since  0.1.0
 **/
Outside::~Outside() {
    // this is intended to be empty.
} // Outside::~Outside()

void Outside::tile(
    std::string const& tile, SDL_Renderer *renderer, SDL_Rect *dst
) {
    std::invoke(table_[tile], this, renderer, dst);
} // Outside::tile

/**
 *  Draw a barn at the specified position.
 *
 *  @param SDL_Renderer * : the renderer
 *  @param SDL_Rect *     : the place to draw.
 *  @return none.
 *  @since  0.1.0
 */
void Outside::barn(SDL_Renderer *renderer, SDL_Rect *dst) {
    static SDL_Rect tile = { 96, 0, 80, 80 };

    tile_(renderer, &tile, dst);
} // Outside::barn()

/**
 *  Draw a barn_back at the specified position.
 *
 *  @param SDL_Renderer * : the renderer
 *  @param SDL_Rect *     : the place to draw.
 *  @return none.
 *  @since  0.1.0
 */
void Outside::barn_back(SDL_Renderer *renderer, SDL_Rect *dst) {
    static SDL_Rect tile = { 176, 0, 80, 80 };

    tile_(renderer, &tile, dst);
} // Outside::barn_back()

/**
 *  Draw a booth at the specified position.
 *
 *  @param SDL_Renderer * : the renderer
 *  @param SDL_Rect *     : the place to draw.
 *  @return none.
 *  @since  0.1.0
 */
void Outside::booth(SDL_Renderer *renderer, SDL_Rect *dst) {
    static SDL_Rect tile = { 288, 350, 80, 96 };

    tile_(renderer, &tile, dst);
} // Outside::booth()

/**
 *  Draw a dirt at the specified position.
 *
 *  @param SDL_Renderer * : the renderer
 *  @param SDL_Rect *     : the place to draw.
 *  @return none.
 *  @since  0.1.0
 */
void Outside::dirt(SDL_Renderer *renderer, SDL_Rect *dst) {
    static SDL_Rect tile = { 0, 544, 32, 32 };

    tile_(renderer, &tile, dst);
} // Outside::dirt()

/**
 *  Draw a fence (crossing) at the specified position.
 *
 *  @param SDL_Renderer * : the renderer
 *  @param SDL_Rect *     : the place to draw.
 *  @return none.
 *  @since  0.1.0
 */
void Outside::fence_h_16(SDL_Renderer *renderer, SDL_Rect *dst) {
    static SDL_Rect tile = { 64, 272, 16, 16 };

    tile_(renderer, &tile, dst);
} // Outside::fence_c()

/**
 *  Draw a fence (horizontally) at the specified position.
 *
 *  @param SDL_Renderer * : the renderer
 *  @param SDL_Rect *     : the place to draw.
 *  @return none.
 *  @since  0.1.0
 */
void Outside::fence_h_24(SDL_Renderer *renderer, SDL_Rect *dst) {
    static SDL_Rect tile = { 0, 304, 32, 16 };

    tile_(renderer, &tile, dst);
} // Outside::fence_h()

/**
 *  Draw a fence (vertically) at the specified position.
 *
 *  @param SDL_Renderer * : the renderer
 *  @param SDL_Rect *     : the place to draw.
 *  @return none.
 *  @since  0.1.0
 */
void Outside::fence_v_16(SDL_Renderer *renderer, SDL_Rect *dst) {
    static SDL_Rect tile = { 64, 288, 16, 16 };

    tile_(renderer, &tile, dst);
} // Outside::fence_v_16()

/**
 *  Draw a fence (vertically) at the specified position.
 *
 *  @param SDL_Renderer * : the renderer
 *  @param SDL_Rect *     : the place to draw.
 *  @return none.
 *  @since  0.1.0
 */
void Outside::fence_v_24(SDL_Renderer *renderer, SDL_Rect *dst) {
    static SDL_Rect tile = { 0, 272, 16, 32 };

    tile_(renderer, &tile, dst);
} // Outside::fence_v_24()

/**
 *  Draw a flower at the specified position.
 *
 *  @param SDL_Renderer * : the renderer
 *  @param SDL_Rect *     : the place to draw.
 *  @return none.
 *  @since  0.1.0
 */
void Outside::flower(SDL_Renderer *renderer, SDL_Rect *dst) {
    static SDL_Rect tile = { 48, 176, 16, 16 };

    tile_(renderer, &tile, dst);
} // Outside::flower()

/**
 *  Draw a running fountain at the specified position.
 *
 *  @param SDL_Renderer * : the renderer
 *  @param SDL_Rect *     : the place to draw.
 *  @return none.
 *  @since  0.1.0
 */
void Outside::fountain(SDL_Renderer *renderer, SDL_Rect *dst) {
    static int i = 0;
    static SDL_Rect tiles[] = {
        { 352, 144, 48, 48 },
        { 400, 144, 48, 48 },
        { 448, 144, 48, 48 },
    };

    i = (i + 1) % (sizeof(tiles) / sizeof(SDL_Rect));

    SDL_Rect *src = &tiles[i];

    tile_(renderer, src, dst);
} // Outside::fountain()

/**
 *  Draw a grass at the specified position.
 *
 *  @param SDL_Renderer * : the renderer
 *  @param SDL_Rect *     : the place to draw.
 *  @return none.
 *  @since  0.1.0
 */
void Outside::grass(SDL_Renderer *renderer, SDL_Rect *dst) {
    static SDL_Rect tile = { 0, 144, 32, 32 };

    tile_(renderer, &tile, dst);
} // Outside::grass()

/**
 *  Draw a stump at the specified position.
 *
 *  @param SDL_Renderer * : the renderer
 *  @param SDL_Rect *     : the place to draw.
 *  @return none.
 *  @since  0.1.0
 */
void Outside::stump(SDL_Renderer *renderer, SDL_Rect *dst) {
    static SDL_Rect tile = { 496, 48, 32, 32 };

    tile_(renderer, &tile, dst);
} // Outside::stump()

/**
 *  Draw a timber at the specified position.
 *
 *  @param SDL_Renderer * : the renderer
 *  @param SDL_Rect *     : the place to draw.
 *  @return none.
 *  @since  0.1.0
 */
void Outside::timber(SDL_Renderer *renderer, SDL_Rect *dst) {
    static SDL_Rect tile = { 48, 80, 48, 16 };

    tile_(renderer, &tile, dst);
} // Outside::timber()

/**
 *  Draw a tree at the specified position.
 *
 *  @param SDL_Renderer * : the renderer
 *  @param SDL_Rect *     : the place to draw.
 *  @return none.
 *  @since  0.1.0
 */
void Outside::tree(SDL_Renderer *renderer, SDL_Rect *dst) {
    static SDL_Rect tile = { 80, 256, 32, 32 };

    tile_(renderer, &tile, dst);
} // Outside::tree()

/**
 *  Draw a tree at the specified position.
 *
 *  @param SDL_Renderer * : the renderer
 *  @param SDL_Rect *     : the place to draw.
 *  @return none.
 *  @since  0.1.0
 */
void Outside::water(SDL_Renderer *renderer, SDL_Rect *dst) {
    static SDL_Rect tile = { 48, 48, 32, 32 };

    tile_(renderer, &tile, dst);
} // Outside::water()

// ---*--- private functions ---*---

void Outside::tile_(SDL_Renderer *renderer, SDL_Rect *src, SDL_Rect *dst) {
    dst->w = src->w;
    dst->h = src->h;

    sheet_.tile(renderer, src, dst);
} // Outside::tile_()

// outside.cpp
