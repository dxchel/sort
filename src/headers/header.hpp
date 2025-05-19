#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <thread>
#include <sys/wait.h>
#include <sys/types.h>

class Sorter{
	public:
		template <typename T>
		static void bubble(T *arr, int s);
		template <typename T>
		static void merge(T *arr, int s, bool f = true);
		template <typename T>
		static void quick(T *arr, int s, bool f = true);
};

template <typename T>
void printer(T *a, int s);
