#pragma once
#include <sdl.inl>

#include <SDL3/SDL.h>
#include <types.h>
#include <string>

using std::string;


namespace sdl {

/*
    Call this utility function with flags as strings 
*/
template<typename... Args>
constexpr u32 init_flags(Args... args);

struct appMetadata {
    string name, version, identifier, creator, copyright, url, type;
};

class SDL
{
public:
    appMetadata metadata;

    SDL(u32 flags, appMetadata metadata);
    ~SDL();
};


} // namespace sdl