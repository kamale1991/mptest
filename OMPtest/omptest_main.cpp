#include <iostream>
#include "include/OMPtest.h"


int main() {
    std::cout << "omptest_main" << std::endl;
    MPtest::omp_check();    
}