#include <iostream>
#include <mpi.h>
#include "include/MPtest.h"


int main() {
    std::cout << "mptest_main" << std::endl;
    MPtest::mp_check();
}