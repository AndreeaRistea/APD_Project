#include <iostream>
#include <omp.h>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void quicksort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

    #pragma omp parallel sections
            {
    #pragma omp section
                {
                    quicksort(arr, low, pi - 1);
                }
    #pragma omp section
                {
                    quicksort(arr, pi + 1, high);
                }
    #pragma omp section
            }
        }
    }

    int main() {

        ifstream inputFile("test8.txt");
        if (!inputFile.is_open()) {
            cout << "Nu s-a putut deschide fișierul de intrare." << endl;
            return 1;
        }

        int size;
        inputFile >> size; 

        vector<int> values(size);

        for (int i = 0; i < size; i++) {
            inputFile >> values[i];
        }

        inputFile.close();

        double start_time = omp_get_wtime();
        quicksort(values.data(), 0, values.size() - 1);
        double end_time = omp_get_wtime();
        cout << "Time for sort process: " << (end_time - start_time) * 1e6 << " microseconds" << endl;
        cout << "Array after sorting: ";
        for (int i = 0; i < values.size(); i++) {
            cout << values[i] << " ";
        }
       cout << endl;

        return 0;
    }
