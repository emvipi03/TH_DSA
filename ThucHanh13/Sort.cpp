#include <bits/stdc++.h>
#define maxn  100
using namespace std;

void print(vector<int> &vt) 
{ 
    for(int i = 0; i < vt.size(); i++) {
        cout << vt[i] << " "; 
	} cout << endl;
} 

void selectionSort(vector<int> &vt) {
	int n = vt.size();
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if (vt[i] > vt[j]) {
                swap(vt[i], vt[j]);
            }
        }
    }
}

void insertionSort(vector<int> &vt) {
	int n = vt.size();
	for (int i = 1; i < n; i++) {
		int tmp = vt[i];
		int index = i;
		while (index > 0 && vt[index - 1] > tmp) {
			vt[index] = vt[index - 1];
			index --;
		}
		vt[index] = tmp;
	}
}

void bubbleSort(vector<int> &vt) {
	int n = vt.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (vt[j] > vt[j+1]) {
				swap(vt[j], vt[j+1]);
			}
		}
	}
}

void merge(vector<int> &vt, int start, int mid, int end) {
	vector<int> vt1(vt.begin() + start, vt.begin() + mid + 1);
	vector<int> vt2(vt.begin() + mid + 1, vt.begin() + end + 1);
	int index1 = 0, index2 = 0;
	int index = start;
	while (index < vt1.size() && index2 <vt2.size()) {
		if (vt1[index1] < vt2[index2]) {
			vt[index] = vt1[index1];
			index1++;
		} else {
			vt[index] = vt2[index2];
			index2++;
		}
		index++;
	}
	while(index1 < vt1.size()) {
		vt[index] = vt1[index1];
		index++;
		index1++;
	}
	while(index2 < vt2.size()) {
		vt[index] = vt2[index2]; 
		index++;
		index2++;
	}
}

void mergeSort(vector<int> &vt, int start, int end) {
	if (start >= end) {
		return;
	}
	int mid = (start + end - 1) / 2;
	mergeSort(vt, start, mid);
	mergeSort(vt, mid + 1, end);
	merge(vt, start, mid, end);
	
}

int partition(vector<int> &vt, int low, int high) {
	int pivot = vt[high];
	int left = low;
	int right = high - 1;
	while (true) {
		while(left <= right && vt[left] < pivot) left++;
        while(right >= left && vt[right] > pivot) right--;
        if (left >= right) break;
        swap(vt[left], vt[right]);
        left++;
        right--;
	}
	swap(vt[left], vt[high]);
    return left;	
}

void quickSort(vector<int> &vt, int low, int high) {
	if (low < high) {
		int pivot = partition(vt, low,high);
		quickSort(vt, low, pivot - 1);
		quickSort(vt, pivot, high);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    //int vt[maxn];
    vector<int> vt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vt.push_back(x);
    }
    quickSort(vt, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << vt[i] << ' ';
    }
    
}
