#include "headers/header.hpp"

//Array sorting with bubble sort algorithm
template <typename T>
void Sorter::bubble(T *arr, int s){
	clock_t clk = clock();
	static int x;

	//Function body
	//Iterates i through elements 0:end-1 and compares with elements i:end
	for(int i=0; i < s; i++){
		for(int j=i; j < s; j++){
			if(arr[j] < arr[i]){
				x = arr[i];
				arr[i] = arr[j];
				arr[j] = x;
			}
		}
	}
	double tme = (double)(clock() - clk) / CLOCKS_PER_SEC * 1000000;
	printf("Bubble sort finished after %.0fus!!\n", tme);
	return;
};

//Array sorting with merge sort algorithm
template <typename T>
void Sorter::merge(T *arr, int s, bool f){
	clock_t clk = clock();
	//Function Body
	//When there is one element, return
	if(s == 1) return;
	int s2 = (int)(s/2);

	//Get first ordered half
	merge(arr, s2, false);
	//Get second ordered half
	merge(arr+s2, s-s2, false);
	//Merge halves in order
	static T x;
    int st = s2;
	for(int i=0; i < s2 && s2 < s; i++){
		if(arr[s2]<arr[i]){
			x = arr[s2];
			arr[s2] = arr[i];
			arr[i] = x;
			s2++;
		}
	}

	if(f){
		double tme = (double)(clock() - clk) / CLOCKS_PER_SEC * 1000000;
		printf(" Merge sort finished after %.0fus!!\n", tme);
	}
	return;
};

//Array sorting with quick sort algorithm
//It's not quick :'(
template <typename T>
void Sorter::quick(T *arr, int s, bool f){
	clock_t clk = clock();
	//Function Body
	//If the array has 0 or 1 elements, it's sorted
	if(s <= 1) return;
	int ind = s-1;
	static int x;
	for(int i=0; i < s-1; i++){
		if(arr[ind]<arr[i]){
			x = arr[ind];
			arr[ind] = arr[i];
			arr[i] = x;
		}
	}
	quick(arr, ind, false);
	quick(arr+ind+1, s-ind-1, false);
	if(f){
		double tme = (double)(clock() - clk) / CLOCKS_PER_SEC * 1000000;
		printf(" Quick sort finished after %.0fus!!\n", tme);
	}
	return;
};

//Helper function that prints arrays
template <typename T>
void printer(T *a, int s){
	printf("[%.1f", (double)a[0]);
	for(int i=0;i < s;i++) printf(",%.1f", (double)a[i]);
	printf("]\n");
}

//Specializations
template void Sorter::bubble<int>(int *arr, int s);
template void Sorter::merge<int>(int *arr, int s, bool f);
template void Sorter::quick<int>(int *arr, int s, bool f);
template void printer<int>(int *a, int s);

template void Sorter::bubble<char>(char *arr, int s);
template void Sorter::merge<char>(char *arr, int s, bool f);
template void Sorter::quick<char>(char *arr, int s, bool f);
template void printer<char>(char *a, int s);

template void Sorter::bubble<float>(float *arr, int s);
template void Sorter::merge<float>(float *arr, int s, bool f);
template void Sorter::quick<float>(float *arr, int s, bool f);
template void printer<float>(float *a, int s);

template void Sorter::bubble<double>(double *arr, int s);
template void Sorter::merge<double>(double *arr, int s, bool f);
template void Sorter::quick<double>(double *arr, int s, bool f);
template void printer<double>(double *a, int s);
