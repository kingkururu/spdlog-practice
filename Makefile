# Define compiler and flags
CXX = c++
CXXFLAGS = -std=c++17 -I/opt/homebrew/opt/spdlog/include -I/opt/homebrew/opt/fmt/include
LDFLAGS = -L/opt/homebrew/opt/spdlog/lib -L/opt/homebrew/opt/fmt/lib -lspdlog -lfmt

# Define the target executable
TARGET = log

# Define the source files
SRCS = log.cpp logging.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

# Compile the source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
