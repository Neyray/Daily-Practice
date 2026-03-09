#pragma once
#ifndef ARRAY1_H
#define ARRAY1_H

#include <iostream>
using namespace std;

template<typename T>
class Array {
private:
    T* alist;
    int size;
public:
    Array(int n = 10);
    ~Array();
    void insertSort();
    void selectSort();
    void bubbleSort();
    int seqSearch(T key);
    void display();
    void setElement(int index, T value);
};

template<typename T>
Array<T>::Array(int n) : size(n) {
    alist = new T[size];
}

template<typename T>
Array<T>::~Array() {
    delete[] alist;
}

template<typename T>
void Array<T>::setElement(int index, T value) {
    if (index >= 0 && index < size) {
        alist[index] = value;
    }
}

template<typename T>
void Array<T>::display() {
    for (int i = 0; i < size; i++) {
        cout << alist[i] << " ";
    }
    cout << endl;
}

template<typename T>
void Array<T>::insertSort() {
    for (int i = 1; i < size; i++) {
        T key = alist[i];
        int j = i - 1;
        while (j >= 0 && alist[j] > key) {
            alist[j + 1] = alist[j];
            j--;
        }
        alist[j + 1] = key;
    }
}

template<typename T>
void Array<T>::selectSort() {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (alist[j] < alist[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(alist[i], alist[minIndex]);
        }
    }
}

template<typename T>
void Array<T>::bubbleSort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (alist[j] > alist[j + 1]) {
                swap(alist[j], alist[j + 1]);
            }
        }
    }
}

template<typename T>
int Array<T>::seqSearch(T key) {
    for (int i = 0; i < size; i++) {
        if (alist[i] == key) {
            return i;
        }
    }
    return -1;
}

#endif