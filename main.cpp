#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void printVisualization(const vector<int>& arr, int currentIndex = -1) {
    for (int i = 0; i < arr.size(); i++) {
        if (i == currentIndex) {
            cout << "[" << arr[i] << "] ";
        } else {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        printVisualization(arr, n - i - 1);
        this_thread::sleep_for(chrono::milliseconds(100));

        if (!swapped) {
            break;
        }
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
        printVisualization(arr, i);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
        printVisualization(arr, i);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++) {
        rightArray[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
        printVisualization(arr);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
        printVisualization(arr);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original array: ";
    printArray(arr);

    cout << "\nBubble Sort:" << endl;
    bubbleSort(arr);
    cout << "\nSorted array: ";
    printArray(arr);

    // Reset the array
    arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "\nSelection Sort:" << endl;
    selectionSort(arr);
    cout << "\nSorted array: ";
    printArray(arr);

    // Reset the array
    arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "\nInsertion Sort:" << endl;
    insertionSort(arr);
    cout << "\nSorted array: ";
    printArray(arr);

    // Reset the array
    arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "\nMerge Sort:" << endl;
    mergeSort(arr, 0, arr.size() - 1);
    cout << "\nSorted array: ";
    printArray(arr);

    // Reset the array
    arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "\nQuick Sort:" << endl;
    quickSort(arr, 0, arr.size() - 1);
    cout << "\nSorted array: ";
    printArray(arr);

    return 0;
}
