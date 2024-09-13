#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h> 

int main() {
    // Create a console sink
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    // Create a file sink
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/my_log.txt", true);

    // Create a logger with multiple sinks
    spdlog::logger logger("multi_sink", {console_sink, file_sink});
    spdlog::set_default_logger(std::make_shared<spdlog::logger>(logger));

    // Set global log level
    spdlog::set_level(spdlog::level::debug);

    // Log messages
    spdlog::info("This message will go to both console and file.");
    spdlog::warn("This warning will go to both console and file.");
    spdlog::error("This error will go to both console and file.");

    return 0;
}
