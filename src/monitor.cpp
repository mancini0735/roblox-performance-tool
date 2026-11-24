// monitor.cpp — part of roblox-performance-tool.

#include "robloxperformancetool/monitor.h"

#include <cstdio>

namespace robloxperformancetool {

Monitor::Monitor(const std::string& config_path)
    : config_path_(config_path) {}

void Monitor::configure(const std::string& key, const std::string& value) {
    if (key == "verbose") verbose_ = (value == "true");
}

bool Monitor::run() {
    if (verbose_) std::fprintf(stderr, "[roblox-performance-tool] monitor: run\n");
    // core logic lives here
    return true;
}

}  // namespace robloxperformancetool
