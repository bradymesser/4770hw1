#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <time.h>

int main (int argc, char * argv[]) {
  int i, count;
  double x, y;
  int samples;
  double pi;
  int rank, numtasks;

  int id, numprocs;
  int ierr = MPI_Init(&argc, &argv);
  ierr = MPI_Comm_rank(MPI_COMM_WORLD, &id);
  ierr = MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  printf("ID %d\nnumprocs %d", id, numprocs);
  samples = atoi(argv[1]);

  count = 0;
  for (i = 0; i < samples; i++) {
    x = (double) rand() / RAND_MAX;
    y = (double) rand() / RAND_MAX;

    if (x*x + y*y <= 1) {
      count++;
    }
  }

  pi = 4.0 * (double)count/(double)samples;
  printf("Count = %d, Samples = %d, Estimate of pi = %7.5f\n", count, samples, pi);
  ierr = MPI_Finalize();
  return 0;
}
