#include "../include/MPtest.h"
#include <mpi.h>

namespace MPtest {
    void mp_check() {
        int rank, size, name_len;
        char name[MPI_MAX_PROCESSOR_NAME];
        int *argc;
        char **argv;
        MPI_Init(argc, &argv);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Get_processor_name(name, &name_len);
        printf("Hello, I'm process %d of %d on %s\n", rank, size, name);
        MPI_Finalize();        
    }
}