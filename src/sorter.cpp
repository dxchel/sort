#include "headers/header.hpp"

//Array sorting with bubble sort algorithm
template <typename T>
void Sorter::bubble(T *arr, int s){
    clock_t clk = clock();
    T x;

    //Function body
    //Iterates i through elements 0:end-1 and compares with elements i:end
    for(int i=0; i < s; i++){
        for(int j=i+1; j < s; j++){
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
    //Function Body
    //When there is one element, return
    if(s == 1) return;
    int s2 = (int)(s/2);
    clock_t clk = clock();

    //Get first ordered half
    merge(arr, s2, false);
    //Get second ordered half
    merge(arr+s2, s-s2, false);
    //Merge halves in order
    T temp[s];
    int i=0, j=0;
    while(i+j < s){
        if(i==s2){
            temp[i+j] = arr[s2+j];
            j++;
        }else if(j==s-s2){
            temp[i+j] = arr[i];
            i++;
        }else if(arr[i]<arr[s2+j]){
            temp[i+j] = arr[i];
            i++;
        }else{
            temp[i+j] = arr[s2+j];
            j++;
        }
    }
    for(int i=0; i<s; i++) arr[i] = temp[i];

    if(f){
        double tme = (double)(clock() - clk) / CLOCKS_PER_SEC * 1000000;
        printf(" Merge sort finished after %.0fus!!\n", tme);
    }
    return;
};

//Array sorting with quick sort algorithm
template <typename T>
void Sorter::quick(T *arr, int s, bool f){
    clock_t clk = clock();
    //If the array has 0 or 1 elements, it's sorted
    if(s <= 1) return;
    int x, ind=0;
    for(int i=0; i < s-1; i++){
        if(arr[i]<arr[s-1]){
            x = arr[i];
            arr[i] = arr[ind];
            arr[ind] = x;
            ind++;
        }
    }
    x = arr[s-1];
    arr[s-1] = arr[ind];
    arr[ind] = x;
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
    for(int i=1;i < s;i++) printf(",%.1f", (double)a[i]);
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
