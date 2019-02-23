#pragma once

#include "../Memory.h"
#include "../SDK/UserCmd.h"

namespace Misc {
    void bunnyHop(UserCmd*) noexcept;
    void skybox() noexcept;
    void inverseRagdollGravity() noexcept;
    void autoPistol(UserCmd*) noexcept;
    void revealRanks() noexcept;
    void animateClanTag(bool = false, const std::string_view = { }) noexcept;
    void spectatorList() noexcept;

    constexpr void removeCrouchCooldown(UserCmd* cmd) noexcept
    {
        if (config.misc.fastDuck)
            cmd->buttons |= UserCmd::IN_BULLRUSH;
    }

    constexpr void setClanTag(const std::string_view clanTag) noexcept
    {
        reinterpret_cast<void(__fastcall*)(const char*, const char*)>(memory.setClanTag)(clanTag.data(), clanTag.data());
    }
}
