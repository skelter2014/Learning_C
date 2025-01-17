cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Chap23_UsingFileInputAndOutput)

# Add executable target
add_executable(sortNames
    sortNames.c
    nameList.c
    # ...add other source files as needed...
)

# Include directories
target_include_directories(sortNames PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Copy .data files to the build directory
file(GLOB DATA_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.data")
foreach(DATA_FILE ${DATA_FILES})
    configure_file(${DATA_FILE} ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
endforeach()
