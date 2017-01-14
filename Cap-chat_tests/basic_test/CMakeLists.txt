project(Cap-chat_tests)

set(gtest_sdir ../lib/googletest/googletest)
include_directories(${gtest_sdir}/include ${gtest_sdir})
add_executable(runBasicGameTest basic_check.cpp)
target_link_libraries(runBasicGameTest gtest gtest_main)
target_link_libraries(runBasicGameTest Cap-chat_core)

