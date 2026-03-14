//合并两个有序表
#include "SqList.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>
void merge(SqList<T>& S1,SqList<T>& S2,SqList<T>& S3){
    int len1=S1.length;
    int len2=S2.length;

    int i=0,j=0;
    while(i<len1 && j<len2){
        if(S1.data[i]<S2.data[j]){
            S3.add(S1.data[i]);
            i++;
        }
        else{
            S3.add(S2.data[j]);
            j++;
        }
    }

    while(i<len1){
        S3.add(S1.data[i]);
        i++;
    }

    while(j<len2){
        S3.add(S2.data[j]);
        j++;
    }
}