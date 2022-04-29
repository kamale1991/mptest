cmake_minimum_required(VERSION 3.16.0)
project(mptest VERSION 0.1.0)
include(GoogleTest)
include(CTest)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)

# GoogleTest
find_package(GTest REQUIRED)

# OpenMP
# find_package(OpenMP)
#target_link_libraries(mptest PUBLIC OpenMP::OpenMP_CXX)

# MPI
find_package(MPI REQUIRED)
#

# add_subdirectoryでそれぞれのプロジェクトディレクトリを登録する
#file(GLOB dir_list LIST_DIRECTORIES true RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ./*)
#list(FILTER dir_list EXCLUDE REGEX "^(.gitignore|.vscode|.*.txt|.*.cpp|build|test)$")
#foreach(dir ${dir_list})       
#    message(${dir}) 
#    add_subdirectory(${dir})

#    file(GLOB srcs_tmp "${dir}/src/*.cpp")
#    list(APPEND srcs ${srcs_tmp})        
#endforeach()

# ディレクトリが少ないうちは一つ一つ登録することにした
add_subdirectory(FileIO)
file(GLOB srcs_fileio "FileIO/src/*.cpp")
add_subdirectory(MPtest)
file(GLOB srcs_mptest "MPtest/src/*.cpp")

## PROJECT_NAMEと同じ名前の実行体にmain.cppをリンクする
add_executable(${PROJECT_NAME} 
    ${srcs_fileio} 
    ${srcs_mptest}
    main.cpp
    )
target_link_libraries(${PROJECT_NAME} PUBLIC MPI::MPI_CXX)
enable_testing()