#include <iostream>
#include "include/MPI_OMPtest.h"


int main() {
    std::cout << "mpi_omptest_main" << std::endl;
    MPtest::mpi_omp_check();    
}