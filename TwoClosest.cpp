//Find the two closest float numbers in an array
//Solution using QuickSort Algorithm
#include "pch.h"
#include <iostream>
using namespace std;

int partition(float arr[], int low, int high)
{
	//Selects the first element as pivot
	float pivot = arr[low];

	int count = 0;
	for (int i = low + 1; i <= high; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = low + count;
	swap(arr[pivotIndex], arr[low]);

	// Sorting left and right parts of the pivot element
	int i = low, j = high;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}
	return pivotIndex;
}

void quickSort(float arr[], int low, int high)
{
	if (low < high) {
		int p = partition(arr, low, high);
		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1, high);
	}
}

int main()
{
	float data[] = { 7.2f, -10.0f, 13.2f, 8.0f, 4.8f, -7.2f, -12.3f, -3.7f, 3.5f, -9.6f, 6.5f, -1.7f, -6.2f, 7.4f };
	auto arr_size = sizeof(data) / sizeof(data[0]);

	quickSort(data, 0, arr_size - 1);
	
	float subtract_result = abs(data[0] - data[1]);
	float closest_value1;
	float closest_value2;
	for (auto i = 2; i < arr_size - 1; i++) {
		if (abs(data[i] - data[i + 1]) < subtract_result)
		{
			subtract_result = abs(data[i] - data[i + 1]);
			closest_value1 = data[i];
			closest_value2 = data[i + 1];
		}
	}
	cout << "Two Closest: " << endl << closest_value1 << " " << closest_value2;
	
	return 0;
}
