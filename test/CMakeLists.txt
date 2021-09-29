cmake_minimum_required(VERSION 3.15)

project(Tests)

enable_testing()

find_package(GTest REQUIRED)

find_package(ZLIB)

set(G_TEST "${PROJECT_NAME}-google-test")

if(GTest_FOUND)

    file(GLOB G_TEST_SOURCES
        Gtest_*.cpp
    )

    add_executable(
        ${G_TEST}
        ${G_TEST_SOURCES}
        )


    target_link_libraries(
        ${G_TEST} 
        ${GTEST_LIBRARIES}
        ${GTEST_MAIN_LIBRARIES}
        pthread
        ZLIB::ZLIB
        )
    add_test(
        NAME ${G_TEST}
        COMMAND ${G_TEST}
        )
endif()