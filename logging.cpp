#include "log.hpp"

int main() {
    init_logging();
    log_error("\tThis is an error message.");

    return 0;
}
