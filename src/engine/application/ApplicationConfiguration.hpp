//
// Created by Ray_1024 on 22.06.2025.
//

#ifndef APPLICATIONCONFIGURATION_HPP
#define APPLICATIONCONFIGURATION_HPP

#include <string_view>
#include <cinttypes>

#include "engine/utils/codegeneration/GetterSetter.hpp"

namespace endora {
    class ApplicationConfiguration {
    public:
        ApplicationConfiguration() = default;

        GETSET_FIELD(std::string_view, title, Title)
        GETSET_FIELD(bool, fullscreen, Fullscreen)
        GETSET_FIELD(uint32_t, width, Width)
        GETSET_FIELD(uint32_t, height, Height)
        GETSET_FIELD(uint32_t, fps, Fps);
        GETSET_FIELD(bool, vSync, VSync);

    public:
        ~ApplicationConfiguration() = default;
    };
} // endora

#endif //APPLICATIONCONFIGURATION_HPP
