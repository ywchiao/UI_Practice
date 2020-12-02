
#include <iostream>

#include <SDL.h>

int main(int argc, char *argv[]) {
    SDL_Window* window = nullptr;
    SDL_Surface* surface = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout  << "SDL Error: " <<  SDL_GetError() << std::endl;
    }
    else {
        window = SDL_CreateWindow(
            "Hello SDL", 100, 100, 600, 400, SDL_WINDOW_SHOWN
        );

        if (!window) {
            std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
        }
        else {
            surface = SDL_GetWindowSurface(window);

            SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0xff, 0xff, 0xff));

            SDL_UpdateWindowSurface(window);

            SDL_Delay(2000);
        }
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}

// main.cpp
