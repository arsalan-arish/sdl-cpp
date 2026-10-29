#pragma once
#include <sdl.inl>

#include <SDL3/SDL.h>
#include <types.h>

namespace sdl {

/*
    Call this utility function with flags as strings 
*/
template<typename... Args>
constexpr u32 init_flags(Args... args);


class SDL
{
    SDL(u32 flags);
    ~SDL();
};


} // namespace sdl