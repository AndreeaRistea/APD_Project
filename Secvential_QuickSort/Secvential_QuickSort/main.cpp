#include "Utils.h"
#include "Sort.h"

int main()
{
	long vector[1001];
	int dim ;
	
	//test_generator6();

	load_test(vector, &dim);
	cout << dim << endl;
	auto start = chrono::steady_clock::now();
	quick_sort(vector, 0, dim - 1);
	auto end = chrono::steady_clock::now();
	display_sorted_vector(vector, 0, dim - 1);
	cout << endl;
	cout << "Time for sort process: "<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
	return 0;
}