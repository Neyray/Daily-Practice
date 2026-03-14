//给定基准x为第一个元素，将小于等于它的放前面，大于它的放后面
#include "SqList.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//只遍历一次，采用交换的方法
template <typename T>
void moveX1(SqList<T>& S){
    int pivot=S.data[0];

    int i=0;
    //不能让j从0开始遍历！
    //不然可能直接换掉基准值了！
    for(int j=1;j<S.length;++j){
        if(S.data[j]<=pivot){
            i++;
            swap(S.data[i],S.data[j]);
        }
    }
    //此时data[0]就是基准,从下标1到下标i都是<=pivot的
    //那么可以把i和data[0]交换
    swap(S.data[0],S.data[i]);
}

//使用两个指针分别从左到右和从右到左遍历
template <typename T>
void moveX2(SqList<T>& S){
    int pivot = S.data[0];
    int len = S.length;
    int i = 0, j = len - 1;

    while(i < j){
        // 必须先从右往左找 <= pivot 的元素！
        while(i < j && S.data[j] > pivot){
            j--;
        }
        // 再从左往右找 > pivot 的元素
        while(i < j && S.data[i] <= pivot){
            i++;
        }
        swap(S.data[i], S.data[j]);
    }
    swap(S.data[0], S.data[i]);
}