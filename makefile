default:
	mpicc hw1.c -o hw1
	mpirun -np 4 --mca mpi_cuda_support 0 hw1 100000

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
	qsub -I -l select=1:ncpus=16:mpiprocs=16,walltime=0:10:00
	module add gcc/5.3.0 openmpi/1.8.1
