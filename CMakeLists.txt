cmake_minimum_required(VERSION 2.8.4)
project(Cap-chat)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCE_FILES main.cpp)
add_executable(Cap-chat ${SOURCE_FILES})

include_directories(Cap-chat_core)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Cap-chat ${SFML_LIBRARIES})
endif ()

add_subdirectory(Cap-chat_core)
add_subdirectory(Cap-chat_tests)

target_link_libraries(Cap-chat Cap-chat_core -lpthread -lm)

# Test code
include(CTest)
enable_testing()
add_test(unit ${PROJECT_BINARY_DIR}/unit_tests)

# Copy the Resources to binary directory
set(ResourceDir "${CMAKE_SOURCE_DIR}/resources")
set(ResourceOutDir "${CMAKE_BINARY_DIR}/resources")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${ResourceDir} ${ResourceOutDir})

if (SFML_FOUND AND ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(SFML_BIN "${SFML_INCLUDE_DIR}/../bin")
    set(BIN_OUTPUT "${CMAKE_BINARY_DIR}")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${SFML_BIN} ${BIN_OUTPUT})
endif()