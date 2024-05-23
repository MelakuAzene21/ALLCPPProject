

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

void selectionSort(int arr[], int n, bool ascending);
void mergeSort(int arr[], int low, int high, bool ascending);
void merge(int arr[], int low, int mid, int high, bool ascending);
void quickSort(int arr[], int low, int high, bool ascending);
int partition(int arr[], int low, int high, bool ascending);
void heapify(int arr[], int n, int i, bool ascending);
void heapSort(int arr[], int n, bool ascending);
void printArray(int arr[], int n);
int findMax(int arr[], int n);
int findMin(int arr[], int n);

int main() {

 const int m = 1000;
    int arr[m];
    for (int i = 0; i < m; ++i) {
        arr[i] = rand() % 10000;  // Generate random numbers between 0 to 9999
    }
    int choice;
    do {
        cout << "\nMain Menu\n";
        cout << "1. Selection Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Quick Sort\n";
        cout << "4. Heap Sort\n";
        cout << "5. Sort once by all methods\n";
        cout << "6. Find Maximum\n";
        cout << "7. Find Minimum\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        bool ascending;
        if (choice >= 1 && choice <= 5) {
            cout << "Sort in:\n1. Ascending\n2. Descending\nEnter your choice: ";
            int orderChoice;
            cin >> orderChoice;
            ascending = (orderChoice == 1);
        }

        clock_t  start, end;
        double cpu_time_used;
     int m=sizeof(arr)/sizeof(arr[0]);
        switch(choice) {
            case 1:
                start = clock();
                selectionSort(arr, m, ascending);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC*1000;
                cout << "Time taken for Selection Sort: " << cpu_time_used << " seconds\n";
                printArray(arr, m);
                break;
            case 2:
                start = clock();
                mergeSort(arr, 0, m- 1, ascending);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC*1000;
                cout << "Time taken for Merge Sort: " << cpu_time_used << " seconds\n";
                printArray(arr, m);
                break;
            case 3:
                start = clock();
                quickSort(arr, 0, m- 1, ascending);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC*1000;
                cout << "Time taken for Quick Sort: " << cpu_time_used << " seconds\n";
                printArray(arr, m);
                break;
            case 4:
                start = clock();
                heapSort(arr, m, ascending);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC*1000;
                cout << "Time taken for Heap Sort: " << cpu_time_used << " seconds\n";
                printArray(arr, m);
                break;
            case 5:
                start = clock();
                selectionSort(arr, m, ascending);
                end = clock();
                 printArray(arr, m);
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC*1000;
                cout << "Time taken for Selection Sort: " << cpu_time_used << " seconds\n";

                start = clock();
                mergeSort(arr, 0, m - 1, ascending);
                end = clock();
                 printArray(arr, m);
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC*1000;
                cout << "Time taken for Merge Sort: " << cpu_time_used << " seconds\n";

                start = clock();
                quickSort(arr, 0, m - 1, ascending);
                end = clock();
                 printArray(arr, m);
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC*1000;
                cout << "Time taken for Quick Sort: " << cpu_time_used << " seconds\n";

                start = clock();
                heapSort(arr, m, ascending);
                end = clock();
                 printArray(arr, m);
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC*1000;
                cout << "Time taken for Heap Sort: " << cpu_time_used << " seconds\n";
                break;
            case 6:
                start=clock();
                cout << "Maximum: " << findMax(arr, m) << endl;
                end=clock();
                 cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC*1000;
                  cout << "Time taken for to find MAXIMUM NUMBER: " << cpu_time_used << " seconds\n";
                break;
            case 7:
                start=clock();
                cout << "Minimum: " << findMin(arr, m) << endl;
                end=clock();
                 cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC*1000;
                  cout << "Time taken for to find MINIMUM NUMBER: " << cpu_time_used << " seconds\n";
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 8);

    return 0;
}

void selectionSort(int arr[], int n, bool ascending) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if ((ascending && arr[j] < arr[minIndex]) || (!ascending && arr[j] > arr[minIndex])) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

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

void printArray(int arr[], int n) {
    cout << "Sorted Array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int arr[], int n) {
    int min = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
