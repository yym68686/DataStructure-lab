#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
int inde = 1, num[55555], n, arr[55555], w = 7, mergearr[55555];
clock_t starttime, endtime;
string temp;

void InsertSort(int a[], int n){
    for (int i = 1; i < n; i++){
        int k, tmp = a[i];
        for (k = i - 1; k >= 0; k--) if (a[k] < a[i]) break;
        for (int j = i - 1; j >= k + 1; j--) a[j + 1] = a[j];
        a[k + 1] = tmp;
    }
}

void ShellSort(int a[], int n){
    int j;
    for (int gap = n >> 1; gap; gap >>= 1){
        for (int i = gap; i < n; i++){
            int temp = a[i];
            for (j = i - gap; j >= 0 && a[j] > temp; j -= gap) a[j + gap] = a[j];
            a[j + gap] = temp;
        }
    }
}

void BubbleSort(int a[], int n){
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n - i - 1; j++)
        if (a[j] > a[j + 1]){
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
}

void QuickSort(int a[], int left, int right) {
    if (a == NULL || left >= right) return;
    int i = left;
    int j = right;
    int key = a[i];
    while (i < j) {
        while (i < j && a[j] >= key)
            j--;
        a[i] = a[j];
        while (i < j && a[i] <= key)
            i++;
        a[j] = a[i];
    }
    a[i] = key;
    QuickSort(a, left, i - 1);
    QuickSort(a, i + 1, right);
}

void SelectSort(int a[], int n){
    for(int i = 0; i < n; i++){
        int minn = 0x3f3f3f3f, index;
        for (int j = i; j < n; j++)
            if (a[j] < minn) {
                index = j;
                minn = a[j];
            }
        a[index] = a[i], a[i] = minn;
    }
}

void max_heapify(int arr[], int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && arr[son] < arr[son + 1])
            son++;
        if (arr[dad] > arr[son])
            return;
        else {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void HeapSort(int arr[], int len) {
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

void mergesort(int a[], int s, int mid, int e, int b[])
{
    int i = s, j = mid+1, q = s, m = mid;
    while (i <= m && j <= e)
    {
        if (a[i] < a[j])
            b[q++] = a[i++];
        else
            b[q++] = a[j++];
    }
    while (i <= m)
        b[q++] = a[i++];
    while (j <= e)
        b[q++] = a[j++];
    for (int i = s; i <= e;a[i]=b[i],i++);
}

void merge(int a[], int s, int e, int b[])
{
    if (s < e)
    {
        int mid = s + (e - s) / 2;
        merge(a, s, mid, b);
        merge(a, mid + 1, e, b);
        mergesort(a, s, mid, e, b);
    }
}

int main(){
    cout << setw(2 * w + 4) << "Insert" << setw(w + 1) << "Shell" << setw(w + 1) << "Bubble" << setw(w + 1) << "Select" << setw(w + 1) << "Heap" << setw(w + 1) << "Merge" << setw(w + 1) << "Insert" << setw(w + 1) << "Insert" << endl;
    while (inde != 11){
        n = 0;
        fstream ReadFile(to_string(inde) + "Sample");
        cout << setw(2) << to_string(inde++) << "Sample: ";
        while(getline(ReadFile, temp)) num[n++] = stoi(temp);
        ReadFile.close();

        for (int i = 0; i < n; i++) arr[i] = num[i];
        starttime = clock();
        InsertSort(arr, n);
        endtime = clock();
        cout << setw(w) << fixed << setprecision(3) << double(endtime - starttime) / CLOCKS_PER_SEC << "s";

        for (int i = 0; i < n; i++) arr[i] = num[i];
        starttime = clock();
        ShellSort(arr, n);
        endtime = clock();
        cout << setw(w) << fixed << setprecision(3) << double(endtime - starttime) / CLOCKS_PER_SEC << "s";

        for (int i = 0; i < n; i++) arr[i] = num[i];
        starttime = clock();
        BubbleSort(arr, n);
        endtime = clock();
        cout << setw(w) << fixed << setprecision(3) << double(endtime - starttime) / CLOCKS_PER_SEC << "s";

        // for (int i = 0; i < n; i++) arr[i] = num[i];
        // starttime = clock();
        // QuickSort(arr, 0, n - 1);
        // endtime = clock();
        // cout << setw(w) << fixed << setprecision(3) << double(endtime - starttime) / CLOCKS_PER_SEC << "s";

        for (int i = 0; i < n; i++) arr[i] = num[i];
        starttime = clock();
        SelectSort(arr, n);
        endtime = clock();
        cout << setw(w) << fixed << setprecision(3) << double(endtime - starttime) / CLOCKS_PER_SEC << "s";

        for (int i = 0; i < n; i++) arr[i] = num[i];
        starttime = clock();
        HeapSort(arr, n);
        endtime = clock();
        cout << setw(w) << fixed << setprecision(3) << double(endtime - starttime) / CLOCKS_PER_SEC << "s";

        for (int i = 0; i < n; i++) arr[i] = num[i];
        starttime = clock();
        merge(arr, 0, n - 1, mergearr);
        endtime = clock();
        cout << setw(w) << fixed << setprecision(3) << double(endtime - starttime) / CLOCKS_PER_SEC << "s" << endl;

        ofstream out("Sample");
        for (int i = 0; i < n; i++)
            out << mergearr[i] << endl;
        out.close();
    }
}