#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

int partition(int arr[], int l, int r) {
	int pivot = arr[r];
	int i = l - 1;
	
	for (int j = l; j < r; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	i++;
	swap(arr[i], arr[r]);
	return i;
}

void quickSort(int arr[], int l, int r) {
	if (l >= r) return;
	int p = partition(arr, l, r);
	quickSort(arr, l, p-1);
	quickSort(arr, p+1, r);
}

int main() {
	int a[1000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 1000;
	}
	quickSort(a, 0, n-1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
