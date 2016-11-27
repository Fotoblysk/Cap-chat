#cmake_minimum_required(VERSION 3.6)
#project(Cap-chat_core)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#set(SOURCE_FILES main.cpp)
#add_executable(Cap-chat ${SOURCE_FILES})

#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)


# Enable debug symbols by default
# must be done before project() statement
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif ()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project(Cap-chat_core)

# Set version information in a config.h file
#set(VauxGame_VERSION_MAJOR 1)
#set(VauxGame_VERSION_MINOR 0)
#configure_file(
  #      "config.h.in"
 #       "${PROJECT_BINARY_DIR}/config.h"
#)
include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
set(EXECUTABLE_NAME "Cap-chat_core")
add_library(${EXECUTABLE_NAME} CapChat.cpp CapChat.h)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif ()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${Cap-chat_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Cap-chat_VERSION_MINOR}")
include(CPack)
