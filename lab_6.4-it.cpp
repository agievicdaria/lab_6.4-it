#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void findMinMaxIndices(int array[], int n, int& minIndex, int& maxIndex) {
    minIndex = 0;
    maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
}

int calculateProduct(int array[], int startIndex, int endIndex) {
    int product = 1;
    for (int i = startIndex; i < endIndex; ++i) {
        product *= array[i];
    }
    return product;
}

void inputArray(int*& array, int n) {
    array = new int[n];
    cout << "Введіть елементи масиву:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
}

int calculateStartIndex(int minIndex, int maxIndex) {
    return (minIndex < maxIndex) ? (minIndex + 1) : (maxIndex + 1);
}

int calculateEndIndex(int minIndex, int maxIndex) {
    return (minIndex > maxIndex) ? minIndex : maxIndex;
}

void printArray(int array[], int n) {
    cout << "Масив: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void sortEvenElements(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        if (array[i] % 2 == 0) {
            for (int j = i + 1; j < size; ++j) {
                if (array[j] % 2 == 0 && array[j] < array[i]) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
}

int main() {
    int n;
    cout << "Введіть кількість елементів у масиві: ";
    cin >> n;

    int *array = new int[n];

    inputArray(array, n);

    int minIndex, maxIndex;
    findMinMaxIndices(array, n, minIndex, maxIndex);

    int startIndex = calculateStartIndex(minIndex, maxIndex);
    int endIndex = calculateEndIndex(minIndex, maxIndex);

    int product = calculateProduct(array, startIndex, endIndex);

    printArray(array, n);    

    sortEvenElements(array, n);
    cout << "Масив після впорядкування парних елементів за зростанням: ";
    printArray(array, n);

    cout << "Добуток елементів між максимальним та мінімальним елементами: " << product << endl;

    delete[] array;

    return 0;
}