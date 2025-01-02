#include <iomanip>
#include <iostream>
#include <random>
#include <chrono>
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using namespace std::chrono;

/**
 * I.S. a dan b adalah variabel yang bertipe int.
 * F.S. a dan b ditukar nilainya.
 */
void swap(int &a, int &b);

/**
 * I.S. arr berisi array int, dan n adalah ukuran array.
 * F.S. elemen array arr diurutkan secara berurutan dengan algoritma pengurutan secara iteratif.
 */
void selectionSortIterative(int arr[], int n);

/**
 * I.S. arr berisi array int, dan n adalah ukuran array.
 * F.S. elemen array arr diurutkan secara berurutan dengan algoritma pengurutan secara rekursif.
 */
void selectionSortRecursive(int arr[], int n);

/**
 * I.S. arr berisi array int kosong, dan n adalah ukuran array.
 * F.S. arr akan berisi array int yang dihasilkan dari generasi random.
 */
void generateRandomArray(int arr[], int n);

/**
 * I.S. -
 * F.S. mengukur waktu pemrosesan algoritma pengurutan secara iteratif dan algoritma pengurutan secara rekursif.
 */
void measurePerformance();