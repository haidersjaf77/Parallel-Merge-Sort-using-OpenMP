#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>
#include <chrono>

using namespace std;

void merge(vector<int>& array, int left, int mid, int right) {  
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++) 
        leftArray[i] = array[left + i];

    for (int j = 0; j < n2; j++) 
        rightArray[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) { 
        if (leftArray[i] <= rightArray[j]) { 
            array[k] = leftArray[i];
            i++;
        } else { 
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) { 
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) { 
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void parallelMergeSort(vector<int>& array, int left, int right) {  
    if (left < right) { 
        int mid = left + (right - left) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            parallelMergeSort(array, left, mid);

            #pragma omp section
            parallelMergeSort(array, mid + 1, right);
        }

        merge(array, left, mid, right);
    }
}

void generateRandomArray(vector<int>& array, int size) {  
    srand(time(0));
    for (int i = 0; i < size; i++) { 
        array[i] = rand() % 100;  
    }
}

int main() {  
    int arraySize;
    cout << "Enter the number of elements to sort: ";
    cin >> arraySize;

    vector<int> array(arraySize);
    generateRandomArray(array, arraySize);

    cout << "Original Array: ";
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    auto start = chrono::high_resolution_clock::now();
    parallelMergeSort(array, 0, arraySize - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Sorted Array: ";
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Execution Time: " << duration.count() << " seconds" << endl;  

    return 0;
}
