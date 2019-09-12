default:
	mpicc hw1.c -o hw1
	mpirun -np 4 hw1 5

gcc:
	gcc hw1.c -o hw1
	./hw1 5

clean:
	rm hw1

git:
	git add .
	git commit -m "MAKE GIT"
	git push
