#include <iostream>
#include <fstream>
#include <chrono>

using namespace std; 

/*
* se vor genera 6 teste astfel: 
* - primul fisier de test va contine 10 elemente, nr intregi, cuprinse intre 1 si 100 --fout << rand() % 100 + 1 << " ";
* - urmatorul fisier va contine 50 de elemente cuprinse intre 1 si 1000 --fout << rand() % 1000 + 1 << " ";
* - cel de-al treilea fisier va contine 100 de elemente cuprinse intre 1 si 10000 --fout << rand() % 10000 + 1 << " ";
* - al patrulea fisier va contine 150 elemente cuprinse intre 1 si 100000 --fout << rand() % 100000 + 1 << " ";
* - al cincilea fisier contine 200 de elemente cuprinse intre 1 si 1000000 --fout << rand() % 1000000 + 1 << " ";
* - iar, al saselea fisier va contine 10000 de elemente cuprinse intre 1 si 1000000 --fout << rand() % 1000000 + 1 << " ";
*/

void test_generator();


void load_test(long number[], int *dim);

void interchange_values(long* address_1, long* address_2);

void display_sorted_vector(long vector[], int start, int stop);