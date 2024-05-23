#include <iostream>
#include <ctime>
#include <cstdlib>
// correct
using namespace std;

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Generate random array
    const int SIZE = 10000;
    int arr[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 10000;  // Generate random numbers between 0 to 9999
    }

    // Measure time before sorting
    clock_t start = clock();

    // Sort the array using quick sort
    quickSort(arr, 0, SIZE - 1);

    // Measure time after sorting
    clock_t end = clock();

    // Calculate the duration (time difference) in milliseconds
    double duration = double(end - start) / CLOCKS_PER_SEC * 1000;

    // Print the sorted array
    cout << "Sorted array:" << endl;
    for (int i = 0; i < 100; ++i) {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl; // Print newline after every 10 numbers
        }
    }
    cout << endl;

    // Print the time taken to sort
    cout << "Time taken to sort: " << duration << " milliseconds" << endl;
cout<<"It takes the above time";
    return 0;
}
