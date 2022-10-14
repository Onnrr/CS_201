/**
Mehmet Onur Uysal
22002609
*/

#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

int algorithm1(int arr1Size, int arr2Size, int*& arr1, int*& arr2);
int* createRandomArray(int arrSize, int minValue, int maxValue);
int binarySearch(int arr[], int low, int high, int x);
int algorithm2(int N,int M,int*& arr1,int*&arr2);
int algorithm3(int N, int M, int*& arr1, int*& arr2);
int findMax(int*& arr, int arrSize);
int* createUniqueArray(int arrSize, int minValue, int maxValue);

int main() {
    const int N = 80000000;
    const int M = 10000;
    const int MIN = 0;
    const int MAX = 1000000000;

    int* arr1 = createRandomArray(N,MIN,MAX);
    int* arr2 = createUniqueArray(M,MIN,MAX);
    sort(arr1, arr1+(N-1));

    double duration;
    clock_t startTime = clock();

    algorithm1(N,M,arr1,arr2);


    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution  for algorithm took " << duration << " milliseconds." << endl;

    delete[] arr1;
    delete[] arr2;
}

int algorithm1(int N, int M, int*& arr1, int*& arr2) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (arr1[j] == arr2[i]) {
                break;
            }
            if (j == N) {
                return 0;
            }
        }
    }
    return 1;
}

int algorithm2(int arr1Size, int arr2Size, int*& arr1, int*& arr2) {
    for (int i = 0; i < arr2Size; i++) {
        if(binarySearch(arr1, 0, arr1Size-1, arr2[i]) == -1) {
            return 0;
        }
    }
    return 1;
}

int binarySearch(int* arr, int low, int high, int x) {
    if (high >= low) {
        int mid = (low + high) / 2;

        if ((mid == 0 || x > arr[mid - 1]) && (arr[mid] == x)) {
            return mid;
        }

        else if (x > arr[mid]) {
            return binarySearch(arr, (mid + 1), high, x);
        }

        else {
            return binarySearch(arr, low, (mid - 1), x);
        }

    }
    return -1;
}

void changeValues(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int* createRandomArray(int arrSize, int minValue, int maxValue) {

    srand((unsigned) time(NULL));

    int* newArray = new int[arrSize];

    for (int i = 0; i < arrSize; i++) {
        newArray[i] = minValue + (rand() % maxValue);
    }
    return newArray;
}

int* createUniqueArray(int arrSize, int minValue, int maxValue) {
    int* newArray = new int[arrSize];

    for (int i = 0; i < arrSize; i++) {
        newArray[i] = i+1;
    }
    return newArray;
}

int algorithm3(int N, int M, int*& arr1, int*& arr2) {
    int maxValue = findMax(arr1,N);
    int frequencyTable[maxValue] = {0};

    for (int i = 0; i < maxValue; i++) {
        frequencyTable[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        frequencyTable[arr1[i]]++;
    }

    for (int i = 0; i < M; i++) {
        if (frequencyTable[arr2[i]] > 0 && arr2[i] < maxValue) {
            frequencyTable[arr2[i]]--;
        }
        else {
            return 0;
        }
    }
    return 1;
}

int findMax(int*& arr, int arrSize) {
    int maxValue = arr[0];
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}





