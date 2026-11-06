// 判断子序列
// 双指针+贪心思想：对于 s 中的每个字符，始终选择 t 中最靠左且尚未使用的匹配位置，因为越早匹配当前字符，就能给后面的字符留下越多的位置
#include <iostream>
#include <vector>
using namespace std;

bool isSubsequence(string s, string t) {
    int n1=s.length(),n2=t.length();

    int p1=0,p2=0;

    while(p1<n1 && p2<n2){
        if(s[p1]==t[p2]){
            p1++;
            p2++;
        }else{
            p2++;
        }
    }

    return p1==n1;
}