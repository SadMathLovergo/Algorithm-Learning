#pragma once
template <typename T>
int __partition(T arr[], int L, int R) {
	swap(arr[L], arr[rand() % (R - L + 1) + L]);
	T v = arr[L];
	int j = L;
	for (int i = L + 1; i <= R; i++) {
		if (arr[i] < v) {
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	swap(arr[L], arr[j]);
	return j;
}

template <typename T>
void __quickSort(T arr[], int L, int R) {
	if (R - L <= 15) {
		insertSort(arr, L, R);
		return;
	}
	int p = __partition(arr, L, R);
	__quickSort(arr, L, p-1);
	__quickSort(arr, p + 1, R);
}

template <typename T>
void quickSort(T arr[], int n) {
	srand(time(NULL));
	__quickSort(arr, 0, n - 1);
}

template <typename T>
int __partition2(T arr[], int L, int R) {
	swap(arr[L], arr[rand() % (R - L + 1) + L]);
	T v = arr[L];
	int i = L + 1, j = R;
	while (true)
	{
		while (i <= R && arr[i] < v) i++;
		while (j >= L + 1 && arr[j] > v) j--;
		if (i > j)
			break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	swap(arr[L], arr[j]);
	return j;
}

template <typename T>
void __quickSort2(T arr[], int L, int R) {
	if (R - L <= 15) {
		insertSort(arr, L, R);
		return;
	}
	int p = __partition2(arr, L, R);
	__quickSort2(arr, L, p - 1);
	__quickSort2(arr, p + 1, R);
}

template <typename T>
void quickSort2(T arr[], int n) {
	srand(time(NULL));
	__quickSort2(arr, 0, n - 1);
}

template <typename T>
void __quickSort3Ways(T arr[], int L, int R) {
	if (R - L <= 15) {
		insertSort(arr, L, R);
		return;
	}
	swap(arr[L], arr[rand() % (R - L + 1) + L]);
	T v = arr[L];
	int i = L + 1;
	int gt = R + 1;
	int lt = L;
	while (i < gt) {
		if (arr[i] < v) {
			swap(arr[i], arr[++lt]);
			i++;
		}
		else if(arr[i] > v)
		{
			swap(arr[i], arr[--gt]);
		}
		else
		{
			i++;
		}
	}
	swap(arr[L], arr[lt--]);
	__quickSort3Ways(arr, L, lt);
	__quickSort3Ways(arr, gt, R);
}

template <typename T>
void quickSort3Ways(T arr[], int n) {
	srand(time(NULL));
	__quickSort3Ways(arr, 0, n - 1);
}
