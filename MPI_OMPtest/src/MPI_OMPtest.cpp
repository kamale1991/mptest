#include "../include/MPI_OMPtest.h"
#include <omp.h>

namespace MPtest {
    void mpi_omp_check() {
        int i;
        #pragma omp parallel for private(i)
        for (i = 0; i < 16; i++) {
            printf("i=%d thread num = %d\n", i, omp_get_thread_num());
        }
    }
}