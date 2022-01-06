#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <vector>
using namespace std;
int inde = 1, n, w = 7, arr[55555], num[55555], mergearr[55555];
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

void QuickSort(int num[], int left, int right) {
    if (num == NULL || left >= right) return;
    int i = left;
    int j = right;
    int key = arr[i];
    while (i < j) {
        while (i < j && num[j] >= key)
            j--;
        num[i] = num[j];
        while (i < j && num[i] <= key)
            i++;
        num[j] = num[i];
    }
    num[i] = key;
    QuickSort(num, left, i - 1);
    QuickSort(num, i + 1, right);
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

int maxbit(int data[], int n) //辅助函数，求数据的最大位数
{
    int maxData = data[0];              ///< 最大数
    /// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
    for (int i = 1; i < n; ++i)
    {
        if (maxData < data[i])
            maxData = data[i];
    }
    int d = 1;
    int p = 10;
    while (maxData >= p)
    {
        maxData /= 10;
        ++d;
    }
    return d;
}
void RadixSort(int data[], int n) //基数排序
{
    int d = maxbit(data, n);
    int *tmp = new int[n];
    int *count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //进行d次排序
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for(j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete []tmp;
    delete []count;
}

int main(){
    cout << setw(2 * w + 4) << "Insert" << setw(w + 1) << "Shell" << setw(w + 1) << "Bubble" << setw(w + 1) << "Select" << setw(w + 1) << "Heap" << setw(w + 1) << "Merge" << setw(w + 1) << "Radix" << endl;
    while (inde != 11){
        n = 0;
        fstream ReadFile(to_string(inde) + "Sample");
        cout << setw(2) << to_string(inde) << "Sample: ";
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
        cout << setw(w) << fixed << setprecision(3) << double(endtime - starttime) / CLOCKS_PER_SEC << "s";

        for (int i = 0; i < n; i++) arr[i] = num[i];
        starttime = clock();
        RadixSort(arr, n);
        endtime = clock();
        cout << setw(w) << fixed << setprecision(3) << double(endtime - starttime) / CLOCKS_PER_SEC << "s" << endl;

        // for (int i = 0; i < n; i++) arr[i] = num[i];
        // starttime = clock();
        // QuickSort(arr, 0, n - 1);
        // endtime = clock();
        // cout << setw(w) << fixed << setprecision(3) << double(endtime - starttime) / CLOCKS_PER_SEC << "s" << endl;

        inde++;
    }
}