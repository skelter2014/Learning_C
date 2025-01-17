cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Dealer)

# Add the executable
add_executable(dealer dealer.c deck.c hand.c card.c)

# Include directories
target_include_directories(dealer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Instructions:
# 1. To generate the build files, run `cmake -S . -B build` from the terminal.
# 2. To build the project, run `cmake --build build`.
# 3. The executable will be located in the `build` directory.
# 4. To clean the build files, you can simply delete the `build` directory.
# Note: Run the build commands from the root directory of the project.
# To build in verbose mode, use the command `cmake --build build --verbose`.



