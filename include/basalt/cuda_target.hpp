#pragma once

#include <string>

// The build's one compute capability, set by CMake from CMAKE_CUDA_ARCHITECTURES (89 or 86).
#ifndef BASALT_CC_MAJOR
#define BASALT_CC_MAJOR 8
#endif
#ifndef BASALT_CC_MINOR
#define BASALT_CC_MINOR 9
#endif

namespace basalt::cuda_target {

inline constexpr int major = BASALT_CC_MAJOR;
inline constexpr int minor = BASALT_CC_MINOR;

constexpr bool supports(int device_major, int device_minor) {
    return device_major == major && device_minor == minor;
}

// "sm_89" or "sm_86", and "8.9" or "8.6", for messages
inline std::string sm_name() { return "sm_" + std::to_string(major) + std::to_string(minor); }
inline std::string cc_name() { return std::to_string(major) + "." + std::to_string(minor); }

}  // namespace basalt::cuda_target
