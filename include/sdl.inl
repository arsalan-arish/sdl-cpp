#include <types.h>
#include <string_view>
#include <SDL3/SDL.h>

namespace sdl {

namespace _util {

    constexpr u32 parse_init_flag(std::string_view flag) {
        if (flag == "audio")    return SDL_INIT_AUDIO;
        if (flag == "video")    return SDL_INIT_VIDEO;
        if (flag == "haptic")   return SDL_INIT_HAPTIC;
        if (flag == "gamepad")  return SDL_INIT_GAMEPAD;
        if (flag == "joystick") return SDL_INIT_JOYSTICK;
        if (flag == "events")   return SDL_INIT_EVENTS;
        if (flag == "sensor")   return SDL_INIT_SENSOR;
        if (flag == "camera")   return SDL_INIT_CAMERA;

        throw std::invalid_argument("Unknown flag name provided!");
    }

    // CHECK SINGLE FLAG: Returns true if the mask contains the specified flag
    [[nodiscard]] constexpr bool has_init_flag(u32 mask, std::string_view flag) {
        return (mask & parse_init_flag(flag)) != 0;
    }

    // CHECK ALL FLAGS: Returns true only if the mask contains EVERY specified flag
    template<typename... Args>
    [[nodiscard]] constexpr bool has_all_init_flags(u32 mask, Args... flags) {
        return ((mask & parse_init_flag(flags)) && ...);
    }

    // CHECK ANY FLAGS: Returns true if the mask contains AT LEAST ONE of the flags
    template<typename... Args>
    [[nodiscard]] constexpr bool has_any_init_flags(u32 mask, Args... flags) {
        return ((mask & parse_init_flag(flags)) || ...);
    }

    // REMOVE FLAGS: Strips out the specified string flags from an existing mask
    template<typename... Args>
    [[nodiscard]] constexpr u32 remove_init_flags(u32 mask, Args... flags) {
        return mask & ~(parse_init_flag(flags) | ...);
    }

    // TOGGLE FLAGS: Flips the state of the specified string flags
    template<typename... Args>
    [[nodiscard]] constexpr u32 toggle_init_flags(u32 mask, Args... flags) {
        return mask ^ (parse_init_flag(flags) | ...);
    }
} // namespace util

template<typename... Args>
constexpr u32 init_flags(Args... args) {
    return (_util::parse_init_flag(args) | ...);
}

} // namespace sdl