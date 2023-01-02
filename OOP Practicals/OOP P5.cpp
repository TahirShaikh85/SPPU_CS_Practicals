#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T* arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      swap(arr[i], arr[minIndex]);
    }
  }
}

int main() {
  // Sort an array of integers
  int arr1[] = {5, 2, 4, 3, 1};
  int size1 = sizeof(arr1) / sizeof(int);

  selectionSort(arr1, size1);

  cout << "Sorted array of integers: ";
  for (int i = 0; i < size1; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;

  // Sort an array of floats
  float arr2[] = {5.5, 2.2, 4.4, 3.3, 1.1};
  int size2 = sizeof(arr2) / sizeof(float);

  selectionSort(arr2, size2);

  cout << "Sorted array of floats: ";
  for (int i = 0; i < size2; i++) {
    cout << arr2[i] << " ";
  }
  cout << endl;

  return 0;
}

