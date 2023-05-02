#include <iostream>
#include <fstream>
#include <algorithm>
#include <mpi.h>
#include "Sort.h"
using namespace std;

int main(int argc, char* argv[]) {
    int size, rank;
    double start_time, end_time, total_time;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int n;
    long* data = NULL;

    if (rank == 0) {
        ifstream infile("test8.txt");
        if (!infile.is_open()) {
            cerr << "Error opening input file" << endl;
            MPI_Abort(MPI_COMM_WORLD, 1);
        }


        infile >> n;

        if (n <= 0) {
            cerr << "Invalid input size" << endl;
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        data = new long[n];

        for (int i = 0; i < n; i++) {
            infile >> data[i];
        }

        infile.close();
        start_time = MPI_Wtime();
    }

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int chunk_size = n / size;
    long* chunk = new long[chunk_size];

    MPI_Scatter(data, chunk_size, MPI_LONG, chunk, chunk_size, MPI_LONG, 0, MPI_COMM_WORLD);

    quick_sort(chunk, 0, chunk_size - 1);

    MPI_Gather(chunk, chunk_size, MPI_LONG, data, chunk_size, MPI_LONG, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        quick_sort(data, 0, n - 1);
        end_time = MPI_Wtime();
        total_time = end_time - start_time;


        cout << "Time taken for sort process: " << total_time << " secods" << endl;
        cout << "Sorted vector: " << endl;
        for (int i = 0; i < n; i++) {
            cout << data[i] << " ";
        }


        delete[] data;
    }

    delete[] chunk;

    MPI_Finalize();
    return 0;
}
