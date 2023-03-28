#include "Utils.h"

void test_generator() {
	ofstream fout ("test9.txt");
	srand((unsigned)time(NULL));
	fout << 50000 << endl;
	for (int i = 0; i < 50000; i++) {
		fout << rand() % 1000000 + 1 << " ";
	}
	fout.close();
}


void load_test(long number[], int *dim) {
	int iterator = 0;
	ifstream fin("test9.txt");
	fin >> *dim;
	while (fin >> number[iterator]) {
		iterator ++;
	}
}

void interchange_values(long* address_1, long* address_2) {
	long aux;

	aux = *address_1;
	*address_1 = *address_2;
	*address_2 = aux;
}

void display_sorted_vector(long vector[], int start, int stop) {
	int iterator = 0;

	cout << "Sorted vector: ";
	for (iterator = start; iterator < stop; iterator++) {
		cout<< vector[iterator] <<" ";
	}
}