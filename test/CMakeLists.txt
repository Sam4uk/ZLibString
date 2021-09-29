cmake_minimum_required(VERSION 3.15)

project(Tests)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
    # Specify the commit you depend on and update it regularly.
    #   URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(ZLIB)

set(G_TEST "${PROJECT_NAME}-google-test")

file(GLOB G_TEST_SOURCES
    Gtest_*.cpp
)

add_executable(
    ${G_TEST}
    ${G_TEST_SOURCES}
    )


target_link_libraries(
    ${G_TEST} 
    gtest_main
    pthread
    ZLIB::ZLIB
    )
add_test(
    NAME ${G_TEST}
    COMMAND ${G_TEST}
    )