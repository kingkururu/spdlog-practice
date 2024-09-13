#include "log.hpp"
#include <spdlog/sinks/basic_file_sink.h>

void init_logging() {
    // Create a file sink that writes to "logs.txt"
    auto file_logger = spdlog::basic_logger_mt("file_logger", "logs.txt");
    // Set the logging level to error
    file_logger->set_level(spdlog::level::err);
}

void log_error(const std::string& message) {
    auto logger = spdlog::get("file_logger");
    if (logger) {
        logger->error(message);
    }
}
