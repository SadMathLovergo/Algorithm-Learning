#pragma once
template <typename T>
void __merge(T arr[], int L, int mid, int R) {
	T* aux = new T[R - L + 1];
	for (int i = L; i <= R; i++)
		aux[i - L] = arr[i];
	int i = L, j = mid + 1;
	for (int k = L; k <= R; k++) {
		if (i > mid) {
			arr[k] = aux[j - L];
			j++;
		}
		else if (j > R) {
			arr[k] = aux[i - L];
			i++;
		}
		else if (aux[i - L] < aux[j - L]) {
			arr[k] = aux[i - L];
			i++;
		}
		else {
			arr[k] = aux[j - L];
			j++;
		}
	}
	delete[] aux;
}

template <typename T>
void __mergeSort(T arr[], int L, int R) {
	if (R - L <= 15) {
		insertSort(arr, L, R);
		return;
	}
	int mid = (L + R) / 2;
	__mergeSort(arr, L, mid);
	__mergeSort(arr, mid + 1, R);
	if (arr[mid] > arr[mid + 1])
		__merge(arr, L, mid, R);
}

template <typename T>
void mergeSort(T arr[], int n) {
	__mergeSort(arr, 0, n - 1);
}

template <typename T>
void mergeSortBottomUp(T arr[], int n) {
	for (int size = 1; size <= n; size += size)
		for (int i = 0; i+size < n; i += size + size)
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
}

template <typename T>
void __mergeInversion(T arr[], int L, int mid, int R, int& inversionNum) {
	if (L == R)
		return;
	if ((R - L) == 1)
	{
		if (arr[L] > arr[R])
		{
			swap(arr[L], arr[R]);
			inversionNum++;
		}
		return;
	}
	T* aux = new T[R - L + 1];
	for (int i = 0; i <= (R - L); i++)
		aux[i] = arr[i+L];
	int i = 0, j = mid - L + 1, k = L;
	for (; k <= R; k++)
	{
		if (i <= (mid-L) && j <= (R-L))
		{
			if (aux[i] > aux[j]) {
				arr[k] = aux[j++];
			}
			else if (aux[i] < aux[j])
			{
				inversionNum += j - (mid - L + 1);
				arr[k] = aux[i++];
			}
			else
			{
				arr[k++] = aux[i++];
				arr[k] = aux[j++];
			}
		}
		else if(i > (mid-L) && j <= (R-L))
		{
			arr[k] = aux[j++];
		}
		else if (i <= (mid-L) && j > (R-L)) {
			arr[k] = aux[i++];
		}
	}
	delete[] aux;
}

template <typename T>
void __mergeSortInversion(T arr[], int L, int R, int &inversionNum) {
	if (R-L <= 1)
	{
		int mid = (L + R) / 2;
		__mergeInversion(arr, L, mid, R, inversionNum);
		return;
	}
	int mid = (L + R) / 2;
	__mergeSortInversion(arr, L, mid, inversionNum);
	__mergeSortInversion(arr, mid + 1, R, inversionNum);
	__mergeInversion(arr, L, mid, R, inversionNum);
}

template <typename T>
void mergeSortInversion(T arr[], int n ,int& inversionNum) {
	__mergeSortInversion(arr, 0, n - 1, inversionNum);
}
