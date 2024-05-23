#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to generate random array
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000;  // Generate random numbers between 0 to 999
    }
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to find minimum value in the array
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find maximum value in the array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Selection sort function
void selectionSort(int arr[], int size, bool ascending) {
    clock_t start = clock();
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if ((ascending && arr[j] < arr[minIndex]) || (!ascending && arr[j] > arr[minIndex])) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC * 1000;
    cout << "Time taken for Selection Sort: " << duration << " milliseconds" << endl;
}

// Merge sort functions
void merge(int arr[], int low, int mid, int high, bool ascending) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1], right[n2];
    for (int i = 0; i < n1; ++i)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; ++j)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if ((ascending && left[i] <= right[j]) || (!ascending && left[i] >= right[j])) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int low, int high, bool ascending) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid, ascending);
        mergeSort(arr, mid + 1, high, ascending);
        merge(arr, low, mid, high, ascending);
    }
}

// Quick sort functions
int partition(int arr[], int low, int high, bool ascending) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if ((ascending && arr[j] < pivot) || (!ascending && arr[j] > pivot)) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, bool ascending) {
    if (low < high) {
        int pi = partition(arr, low, high, ascending);
        quickSort(arr, low, pi - 1, ascending);
        quickSort(arr, pi + 1, high, ascending);
    }
}

// Heap sort functions
void heapify(int arr[], int n, int i, bool ascending) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && ((ascending && arr[left] > arr[largest]) || (!ascending && arr[left] < arr[largest])))
        largest = left;

    if (right < n && ((ascending && arr[right] > arr[largest]) || (!ascending && arr[right] < arr[largest])))
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, ascending);
    }
}

void heapSort(int arr[], int n, bool ascending) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i, ascending);

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, ascending);
    }
}

int main() {
    const int SIZE = 100;
    int arr[SIZE];
    bool ascending;

    // Generate random array
    generateRandomArray(arr, SIZE);

    int choice;
    cout << "Main Menu:" << endl;
    cout << "1. Display all in one" << endl;
    cout << "2. Individually sort" << endl;
    cout << "3. Find minimum" << endl;
    cout << "4. Find maximum" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: // Display all in one
            cout << "Enter the sorting order (1. Ascending, 2. Descending): ";
            cin >> choice;
            ascending = (choice == 1) ? true : false;

            // Selection sort
            selectionSort(arr, SIZE, ascending);

            // Merge sort
            mergeSort(arr, 0, SIZE - 1, ascending);

            // Quick sort
            quickSort(arr, 0, SIZE - 1, ascending);

            // Heap sort
            heapSort(arr, SIZE, ascending);

            // Display sorted array
            cout << "Sorted array:" << endl;
            displayArray(arr, SIZE);
            break;
        case 2: // Individually sort
            cout << "Sub Menu:" << endl;
            cout << "1. Selection Sort" << endl;
            cout << "2. Merge Sort" << endl;
            cout << "3. Quick Sort" << endl;
            cout << "4. Heap Sort" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            cout << "Enter the sorting order (1. Ascending, 2. Descending): ";
            cin >> choice;
            ascending = (choice == 1) ? true : false;

            switch (choice) {
                case 1: // Selection sort
                    selectionSort(arr, SIZE, ascending);
                    break;
                case 2: // Merge sort
                    mergeSort(arr, 0, SIZE - 1, ascending);
                    break;
                case 3: // Quick sort
                    quickSort(arr, 0, SIZE - 1, ascending);
                    break;
                case 4: // Heap sort
                    heapSort(arr, SIZE, ascending);
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
            // Display sorted array
            cout << "Sorted array:" << endl;
            displayArray(arr, SIZE);
            break;
        case 3: // Find minimum
            {
                clock_t startMin = clock();
                int minVal = findMin(arr, SIZE);
                clock_t endMin = clock();
                cout << "Minimum value: " << minVal << endl;
                cout << "Time taken to find minimum: " << double(endMin - startMin) / CLOCKS_PER_SEC * 1000 << " milliseconds" << endl;
            }
            break;
        case 4: // Find maximum
            {
                clock_t startMax = clock();
                int maxVal = findMax(arr, SIZE);
                clock_t endMax = clock();
                cout << "Maximum value: " << maxVal << endl;
                cout << "Time taken to find maximum: " << double(endMax - startMax) / CLOCKS_PER_SEC * 1000 << " milliseconds" << endl;
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
