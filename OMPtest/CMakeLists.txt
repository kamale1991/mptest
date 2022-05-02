cmake_minimum_required(VERSION 3.16.0)
#get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(DIR_NAME OMPtest)
#string(REPLACE " " "_" ProjectID ${ProjectID})

file(GLOB_RECURSE srcs include/*.h src/*.cpp)
add_executable(${DIR_NAME} ${srcs} omptest_main.cpp)
target_link_libraries(${DIR_NAME}     
    PUBLIC OpenMP::OpenMP_CXX
)

# ./testのビルドへ進む
#add_subdirectory(test)

