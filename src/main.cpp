<<<<<<< HEAD
/*
 * Main program for testing common structures in C++.
 *
 * Made by David Xchel Morales Hurtado
 */
#include "headers/test_structures.hpp"

int main(int argc, char **argv){
    // Run tests
    //test_LinkedList();
    exit(test_Tree());
}

=======
#include "headers/header.hpp"

int main(int argc, char** argv){
	srand(clock());
	int s;
	if(argc == 1) s = rand()%100000 + 1;
	else s = atoi(argv[1]);
	int a[s],b[s],c[s];
	std::thread *th[3];
	for(int i=0; i < s; i++){
		a[i] = rand()%10000;
		b[i] = a[i];
		c[i] = a[i];
	}
	printf("Elements: %d\n", s);

	printf("Creating two lambda function that run parallel and count from fifty\n");
	auto *L0 = +[]{
			printf("Started the lambda function number one!\n");
			for(int i=50;i!=0;i--) printf("1: %d\n", 50-i);
			printf("Finished the lambda function number one!\n");
			return;
		};
	auto *L1 = +[]{
			printf("Started the lambda function number two!\n");
			for(int i=50;i!=0;i--) printf("2: %d\n", 50-i);
			printf("Finished the lambda function number two!\n");
			return;
		};
	decltype(L0) L[2];
	L[0] = L0;
	L[1] = L1;

	printf("Running both lambda functions with thread\n");
	clock_t clk = clock();
	th[0] = new std::thread(L[0]);
	th[1] = new std::thread(L[1]);
	for(int i=0;i<2;i++) th[i]->join();
	printf("Finished both lambda threaded functions in %ldus\n\n\n", clock()-clk);

	clk = clock();
	printf("Running both lambda functions with fork\n");
	if (fork() == 0){
		L[0]();
		return 0;
	}
	if (fork() == 0){
		L[1]();
		return 0;
	}
	wait(nullptr);
	printf("Finished both lambda forked functions in %ldus\n\n\n", clock()-clk);

	printf("Running sorting functions\n");
	th[0] = new std::thread([&a, s]{
		printf("Bubble sort started!!\n");
		Sorter::bubble(a, s);
	});
	//printer(b, s);

	//printer(a, s);
	th[1] = new std::thread([&b, s]{
		printf(" Merge sort started!!\n");
		Sorter::merge(b, s);
	});
	//printer(a, s);

	//Merge sorting with threads is slow and causes a lot of trouble with big numbers

	//printer(c, s);
	th[2] = new std::thread([&c, s]{
		printf(" Quick sort started!!\n");
		Sorter::quick(c, s);
	});
	//printer(c, s);

	for(int i=0;i<3;i++) th[i]->join();
	printf("Program finished!!!\n");
	return 0;
}
>>>>>>> 41cb4fe (Initialized repo as this project is too old and not a repo)
