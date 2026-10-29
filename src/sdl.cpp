#include <SDL3/SDL.h>
#include <sdl.hpp>
#include <_sdl.hpp>
#include <types.h>

#include <format>

using std::runtime_error;
using std::format;

namespace sdl {


SDL::SDL(u32 flags)
{
    if (!SDL_Init(flags)) {
        throw runtime_error(format("SDL Failed to Initialize: {}", SDL_GetError()));
    }
}

SDL::~SDL()
{
    if (SDL_WasInit(0)) SDL_Quit();
}



} // namespace sdl