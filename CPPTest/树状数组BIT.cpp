#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int>a;
vector<int>bit;
void build(){
    for(int i = 1; i <= a.size(); i++){
        int k = i;
        while(k <= a.size()){
            bit[k] += a[i - 1];
            k += k & -k;
        }
    }
}

void update(int i, int val){
    int d = val - a[i];
    int k = i + 1;
    while(k <= a.size()){
        bit[k] += d;
        k += k & -k;
    }
    a[i] = val;
}

int getSum(int i, int j){
    int k = i;
    int result1 = 0,result2 = 0;
    while(k > 0){
        result1 += bit[k];
        k -= k & -k;
    }
    k = j+1;
    while(k > 0){
        result2 += bit[k];
        k -= k & -k;
    }
    return result2 - result1;

}
int main(){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d",&x);
        a.push_back(x);
    }

    for(int i = 0; i <= a.size(); i++){
        bit.push_back(0);
    }

    build();


    //update(1,2);
    for(int i = 0; i < m; i++){
        int x,y;
        string str;
        cin>>str;
        scanf("%d %d",&x,&y);
        if(str=="ADD"){
            update(x - 1, a[x-1]+y);
        }if(str=="QUERY")
        printf("%d\n",getSum(x-1,y-1));
    }
}
