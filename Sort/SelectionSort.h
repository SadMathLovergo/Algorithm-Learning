#pragma once
template <typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int j = minIndex; j < n; j++) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		swap(arr[i], arr[minIndex]);
	}
}
