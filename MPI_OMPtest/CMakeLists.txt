cmake_minimum_required(VERSION 3.16.0)
#get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(DIR_NAME MPI_OMPtest)
#string(REPLACE " " "_" ProjectID ${ProjectID})
set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -pedantic -lm -O3 -funroll-loops")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

file(GLOB_RECURSE srcs include/*.h src/*.cpp)
add_executable(${DIR_NAME} ${srcs} mpi_omptest_main.cpp)

# OpenMP
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${DIR_NAME} PUBLIC OpenMP::OpenMP_CXX)
endif()
# MPI
find_package(MPI REQUIRED)
target_link_libraries(${DIR_NAME} PUBLIC MPI::MPI_CXX)

# ./testのビルドへ進む
#add_subdirectory(test)

