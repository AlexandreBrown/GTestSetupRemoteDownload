cmake_minimum_required(VERSION 3.5)
project(GTestSetup)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main/MyClass.cpp
        src/main/MyClass.h
)

add_executable(GTestSetup src/main/main.cpp ${SOURCE_FILES})

# Testing flags
option(BUILD_TESTING "build unit tests" ON)

if(BUILD_TESTING)

    include(ExternalProject) # Allows us to include external projects via github URL instead of downloading the repo manually

    #GTest
    ExternalProject_add(gtest-target
            GIT_REPOSITORY "https://github.com/google/googletest"
            CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/extern"
            UPDATE_COMMAND ""
            )
    include_directories(${CMAKE_CURRENT_BINARY_DIR}/extern/include)
    link_directories(${CMAKE_CURRENT_BINARY_DIR}/extern/lib)

    # Not mandatory but nice tool
    enable_testing() #Enables CTest which can run all our tests via command-line (use command : "make" in /build to apply changes made to code then run "make test")

    add_subdirectory(src/test)
endif()