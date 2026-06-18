#include <iostream>
#include <algorithm>
#include <cstdlib>
#include<chrono>
using namespace std;
using namespace chrono;

void bubble(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertion(int arr[], int n)
{
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quick(int arr[], int left, int right)
{
    if(left >= right){
        return;
    }
    int pivot = arr[right];
    int i = left - 1;
    for(int j = left; j < right; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    int pi = i + 1;
    
    quick(arr, left, pi - 1);
    quick(arr, pi + 1, right);
}


int main()
{
    int n;
    cout << "How many grades do you have? ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 101;
    }
    //bubble time
    auto start = steady_clock::now();
    bubble(arr, n);
    auto endd = steady_clock::now();
    auto time = duration_cast<microseconds>(endd - start).count();
    cout << "Bubble sort time : " << time << " ms. " << endl;
    cout << "-------------------------------------------------" << endl;
    //insertion time
    auto start2 = steady_clock::now();
    insertion(arr, n);
    auto endd2= steady_clock::now();
    auto time2 = duration_cast<microseconds>(endd2 - start2).count();
    cout << "Insertion sort time : " << time2 << " ms. " << endl;
    cout << "--------------------------------------------------" << endl;
    //quick time
    auto start3 = steady_clock::now();
    quick(arr, 0, n - 1);
    auto endd3 = steady_clock::now();
    auto time3 = duration_cast<microseconds>(endd3 - start3).count();
    cout << "Quick sort time : " << time3 << " ms. " << endl;


    return 0;
}
