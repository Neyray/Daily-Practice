//删除掉顺序表中所有值为x的元素
#include "SqList.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


//使用两个指针，第一个指针遍历，第二个指针写入新的数据，后面的数据不用管了，直接改变顺序表大小
template <typename T>
void deletex1(SqList<T>& S,int x){
    int len=S.length;

    int k=0;
    for(int i=0;i<len;++i){
        if(S.data[i]!=x){
            S.data[k]=S.data[i];
            k++;
        }
    }
    S.length=k;
}


//能否使用直接删除呢？
template <typename T>
void deletex2(SqList<T>& S,int x){
    int len=S.length;
    int i=0;
    while(i<len){
        if(S.data[i]==x){
            S.deleteElem(i);
            len--;
        }
        //不能直接写i++！
        //因为可能添上来的数也是x，那么就漏掉了！
        //所以只有在不是x的时候，执行i++
        else{
            i++;
        }
    }
}