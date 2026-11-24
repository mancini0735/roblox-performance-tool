// main.cpp — entry point. Wires config and subsystems together.

#include "robloxperformancetool/settings.h"
#include "robloxperformancetool/tweaks.h"
#include "robloxperformancetool/profiles.h"
#include "robloxperformancetool/monitor.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    robloxperformancetool::Settings settings = robloxperformancetool::Settings::load_default();
    robloxperformancetool::Tweaks tweaks(settings.store_path);
    robloxperformancetool::Profiles profiles(settings.store_path);
    robloxperformancetool::Monitor monitor(settings.store_path);
    std::fprintf(stderr, "[roblox-performance-tool] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
