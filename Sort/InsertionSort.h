#pragma once
template <typename T>
void insertSort(T arr[], int n) {
	for (int i = 1; i < n; i++) {
		T temp = arr[i];
		int j;
		for (j = i; j > 0 && arr[j - 1] > temp; j--)
			arr[j] = arr[j - 1];
		arr[j] = temp;
	}
}

template <typename T>
void insertSort(T arr[], int L, int R) {
	for (int i = L + 1; i <= R; i++) {
		T e = arr[i];
		int j;
		for (j = i; j > L&&arr[j - 1] > e; j--)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
	return;
}
