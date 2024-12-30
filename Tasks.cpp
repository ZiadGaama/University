#include <iostream>
#include <limits.h>
#include <stdio.h> // for getchar()

using namespace std;

// Printing the array in order :

void Traverse(int arr[], int size) {
	cout << "Traversing array :" << endl;
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			cout << arr[i] << endl;
			break;
		}
		cout << arr[i] << ", ";
	}
	cout << endl;
}

// Printing the array in reversed order :

void Reverse(int arr[], int size) {
	cout << "Reversing array :" << endl;
	for (int i = size - 1; i >= 0; i--) {
		if (i == 0) {
			cout << arr[i] << endl;
			break;
		}
		cout << arr[i] << ", ";
	}
	cout << endl;
}

// Finding the smallest element in an array :


void find_min(int arr[], int size) {
	cout << "Finding minimum :" << endl;
	int min = INT_MAX;
	int index;
	for (int i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
			index = i;
		}
	}
	if (min != INT_MAX) cout << "The smallest element is " << min << ", found at index " << index << endl << endl;

}

// Finding the largest element in an array :

void find_max(int arr[], int size) {
	cout << "Finding maximum :" << endl;
	int max = 0;
	int index;
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
			index = i;
		}
	}
	if (max != INT_MAX) cout << "The largest element is " << max << ", found at index " << index << endl << endl;
}

// Linear Search :

void linearSearch(int arr[], int target, int size) {
	cout << "Finding " << target << " in the given array ( Sequential ) :" << endl;
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			cout << "Target ( " << target << " ) was found at index " << i << endl << endl;
			return;
		}
	}
	cout << "Target wasn't found in the given array." << endl << endl;
}

// Binary Search : 

void binarySearch(int arr[], int target, int size) { // Array given has to be sorted
	int left = 0, right = size - 1;
	cout << "Finding " << target << " in the given array ( Binary ) :" << endl;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target) {
			cout << "Target found at index " << mid << endl << endl;
			return;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << "Target not found in the given array" << endl << endl;
}

// Count Sort :

void countSort(int arr[], int size) {
	int maxVal = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
		}
	}

	int* count = new int[maxVal + 1]();

	for (int i = 0; i < size; i++) {
		count[arr[i]]++;
	}

	int index = 0;
	for (int i = 0; i <= maxVal; i++) {
		while (count[i] > 0) {
			arr[index++] = i;
			count[i]--;
		}
	}
	cout << "Sorting array using Count Sort : " << endl << "Array : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

// Selection Sort : 

void selectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
	cout << "Sorting array using Selection Sort : " << endl << "Array : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

// Insertion Sort :

void insertionSort(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	cout << "Sorting array using Insertion Sort : " << endl << "Array : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

// Calling the functions above

int main() {
	int unsorted_arr[] = { 3, 9, 1, 6, 2, 10 }; // Unsorted array
	int size_of_unsorted = sizeof(unsorted_arr) / sizeof(unsorted_arr[0]);

	int sorted_arr[] = { 1, 2, 5, 7, 10, 15 }; // So we can pass it to the Binary Search function
	int size_of_sorted = sizeof(sorted_arr) / sizeof(sorted_arr[0]);


	Traverse(unsorted_arr, size_of_unsorted);

	Reverse(unsorted_arr, size_of_unsorted);

	find_min(unsorted_arr, size_of_unsorted);

	find_max(unsorted_arr, size_of_unsorted);

	linearSearch(unsorted_arr, 9, size_of_unsorted);

	binarySearch(sorted_arr, 10, size_of_sorted);

	countSort(unsorted_arr, size_of_unsorted);

	selectionSort(unsorted_arr, size_of_unsorted);

	insertionSort(unsorted_arr, size_of_unsorted);

	getchar();


}