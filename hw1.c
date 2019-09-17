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
  int sendCount = 1;
  int receiveCount = 1;
  int send_tag = 0;
  double startTime = 0;
  double endTime = 0;
  MPI_Status status;
  int id, numprocs;

  int ierr = MPI_Init(&argc, &argv);
  startTime = MPI_Wtime();

  ierr = MPI_Comm_rank(MPI_COMM_WORLD, &id);
  ierr = MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  samples = atoi(argv[1]);
  if (id == 0) {
    samples = samples / numprocs;
    for (int i = 1; i < numprocs; i++) {
      ierr = MPI_Send(&samples, sendCount, MPI_INT,i, send_tag, MPI_COMM_WORLD);
    }
  } else {
      ierr = MPI_Recv(&samples, receiveCount, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
  }
  count = 0;
  for (i = 0; i < samples; i++) {
    x = (double) rand() / RAND_MAX;
    y = (double) rand() / RAND_MAX;

    if (x*x + y*y <= 1) {
      count++;
    }
  }
  endTime = MPI_Wtime();
  int globalCount = 0;
  samples = samples * numprocs;
  ierr = MPI_Reduce(&count, &globalCount, numprocs, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  if (id == 0) {
    pi = 4.0 * (double)globalCount/(double)samples;
    printf("Count = %d, Samples = %d, Estimate of pi = %7.5f\n", globalCount, samples, pi);
    printf("Elapsed time = %f\n", endTime-startTime);
  }
  ierr = MPI_Finalize();
  return 0;
}
