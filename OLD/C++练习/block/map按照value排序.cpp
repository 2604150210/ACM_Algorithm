#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>
#include <vector>
//将map的key和value组成一个新的结构PAIR，一个PAIR型的vector存储map中的所有内容，对vecor按照value值进行排序。按顺序输出key：
using namespace std;
bool com( const pair<char, int>& a, const pair<char,int>& b){
    return a.second > b.second;
}
int main(){
    char p[200];
    while(gets(p)){
        map<char,int>m;
        int len = strlen(p);
       // printf("%d\n",len);
        for(int i = 0; i < len; i++){
            if(p[i] <='Z' && p[i] >= 'A'){
                p[i] += 32;

            }
            m[p[i]] ++;
        }
        vector<pair<char,int> > v;
        for(map<char,int>::iterator it = m.begin();it!=m.end();it++){
            v.push_back(make_pair(it->first,it->second));
            //printf("%c %d  ",it->first,it->second);
        }
        sort(v.begin(),v.end(),com);
        for(vector<pair<char, int> >::iterator it = v.begin(); it != v.end(); it++){
            printf("%c",it->first);
        }
        printf("\n");
    }

}
