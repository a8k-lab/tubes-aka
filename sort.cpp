#include "sort.h"

void swap(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void selectionSortIterative(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void selectionSortRecursive(int arr[], int n) {
    if (n == 1) {
        return;
    }
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    swap(arr[0], arr[minIndex]);
    selectionSortRecursive(arr + 1, n - 1);
}

void generateRandomArray(int arr[], int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);
    
    for(int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }
}

void measurePerformance() {
    // Ukuran input yang berbeda untuk pengujian
    int sizes[] = {1000, 5000, 10000, 20000, 30000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    
    cout << setw(10) << "Size" << setw(20) << "Iterative (ms)" 
        << setw(20) << "Recursive (ms)" << endl;
    cout << string(50, '-') << endl;
    
    for(int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int* arr1 = new int[n];
        int* arr2 = new int[n];
        
        // Generate array yang sama untuk kedua algoritma
        generateRandomArray(arr1, n);
        for(int j = 0; j < n; j++) arr2[j] = arr1[j];
        
        // Ukur waktu untuk versi iteratif
        auto start = high_resolution_clock::now();
        selectionSortIterative(arr1, n);
        auto end = high_resolution_clock::now();
        auto iterativeTime = duration_cast<milliseconds>(end - start).count();
        
        // Ukur waktu untuk versi rekursif
        start = high_resolution_clock::now();
        selectionSortRecursive(arr2, n);
        end = high_resolution_clock::now();
        auto recursiveTime = duration_cast<milliseconds>(end - start).count();
        
        // Tampilkan hasil
        cout << setw(10) << n 
            << setw(20) << iterativeTime 
            << setw(20) << recursiveTime << endl;
        
        delete[] arr1;
        delete[] arr2;
    }
}
