#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
int inde = 1, num[55555], n, arr[55555], w = 7;
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

// void QuickSort(int a[], int left, int right) {
//     if (a == NULL || left >= right) return;
//     int i = left;
//     int j = right;
//     int temp = a[i];
//     while (i < j) {
//         while (i < j && a[j] >= temp) j--;
//         a[i] = a[j];
//         while (i < j && a[i] <= temp) i++;
//         a[j] = a[i];
//     }
//     a[i] = temp;
//     QuickSort(a, left, i - 1);
//     QuickSort(a, i + 1, right);
// }

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

int main(){
    cout << setw(2 * w + 4) << "Insert" << setw(w + 1) << "Shell" << setw(w + 1) << "Bubble" << setw(w + 1) << "Select" << setw(w + 1) << "Heap" << setw(w + 1) << "Insert" << setw(w + 1) << "Insert" << setw(w + 1) << "Insert" << endl;
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
        cout << setw(w) << fixed << setprecision(3) << double(endtime - starttime) / CLOCKS_PER_SEC << "s" << endl;

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


        ReadFile.open("Sample");
        for (int i = 0; i < n; i++)
            ReadFile << arr[i] << endl;
        ReadFile.close();
    }
}