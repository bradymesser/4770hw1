default:
	mpicc hw1.c -o hw1
	mpirun -np 4 --mca mpi_cuda_support 0 hw1 12

gcc:
	gcc hw1.c -o hw1
	./hw1 5

clean:
	rm hw1

git:
	git add .
	git commit -m "MAKE GIT"
	git push

init:
	qsub -I -l select=1:ncpus=8:mpiprocs=8:interconnect=1g,walltime=1:00:00
	module add gcc/5.3.0 openmpi/1.8.1
