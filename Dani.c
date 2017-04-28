#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {
  // Inisiasi Environment Awal
  MPI_Init(NULL, NULL);
  
  //Mencari Rank dan Size 
  int urutan_global;
  MPI_Comm_rank(MPI_COMM_WORLD,&urutan_global);
  int ukuran_global;
  MPI_Comm_size(MPI_COMM_WORLD,&ukuran_global);
  MPI_Request minta;
  // Menggunakan 2 Processor
  if (ukuran_global < 2) {
    fprintf(stderr, "Ukuran Global harus lebih besar dari 1 untuk  %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  int no;
  
  if (urutan_global == 0) {
    no= -1;
    MPI_Isend(&no, 1, MPI_INT, 1,0,MPI_COMM_WORLD,&minta);
  } else if (world_rank == 1) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 1 received number %d from process 0\n", number);
  }
  
  MPI_Finalize();	
}
