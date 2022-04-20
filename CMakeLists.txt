cmake_minimum_required(VERSION 3.8)
INCLUDE(FindPkgConfig)
project(CleanCode)
add_executable(${PROJECT_NAME})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

# Enable many good warnings
#if (MSVC)
#    target_compile_options(${PROJECT_NAME} PRIVATE /WX /W4)
#else()
#    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion)
#endif()

# Set the folder where the executable is created
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

# ---Add p6---
add_subdirectory(p6)
target_link_libraries(${PROJECT_NAME} PRIVATE p6::p6)


# Add all the files
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS src/*)
target_sources(${PROJECT_NAME} PRIVATE ${MY_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE src)

add_subdirectory(lib)
target_link_libraries(${PROJECT_NAME} PUBLIC lib)
