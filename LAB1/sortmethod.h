#ifndef SORT_H
#define SORT_H

#include <iostream>

void bubble_sort(int arr[],int n) {

    for (int i = 0;i < n - 1;i++) {
        for ( int j = 0;j < n - i - 1;j++) {
            if ( arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void insertion_sort(int arr[],int n) {

    for (int i = 1;i < n;i++) {
        int key = arr[i];
        int j = i-1;

        while ( j >=0 and arr[j] > key) {
            arr[j+1] = arr[j];     
            j--;
        }
        arr[j+1] = key;
    }

}


void selection_sort(int arr[],int n) {

    for (int i = 0;i < n - 1;i++) {
        int index = i;
        int j = i + 1;
        for (j;j < n;j++) {
            if ( arr[j] < arr[index]) {
                index = j;
            }
        }
        int temp2 = arr[i];
        arr[i] = arr[index];
        arr[index] = temp2;
    }
}

#endif
