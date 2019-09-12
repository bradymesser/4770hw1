default:
	mpicc hw1.c -o hw1
	./hw1 5

gcc:
	gcc hw1.c -o hw1
	./hw1 5

clean:
	rm hw1
