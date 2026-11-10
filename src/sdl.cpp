#include <SDL3/SDL.h>
#include <sdl.hpp>
#include <types.h>

#include <format>
#include <string>

using std::runtime_error;
using std::format;
using std::string;

namespace sdl {


SDL::SDL(u32 flags, appMetadata metadata = {}) : metadata(metadata)
{
    if (!SDL_Init(flags)) {
        throw runtime_error(format("SDL Failed to Initialize: {}", SDL_GetError()));
    }

    SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_NAME_STRING,
                               metadata.name.c_str());

    SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_VERSION_STRING, 
                               metadata.version.c_str());

    SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_CREATOR_STRING,
                               metadata.creator.c_str());

    SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_TYPE_STRING,
                               metadata.type.c_str());

    SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_COPYRIGHT_STRING,
                               metadata.copyright.c_str());

    SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_IDENTIFIER_STRING,
                               metadata.identifier.c_str());

    SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_URL_STRING,
                               metadata.url.c_str());

}

SDL::~SDL()
{
    if (SDL_WasInit(0)) SDL_Quit();
}



} // namespace sdl