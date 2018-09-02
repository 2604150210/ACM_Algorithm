#include <bits/stdc++.h>
using namespace std;
int n;
int a[200][200];
int temp[200];
int getSubMatrixMaxSum(int a[200][200]){
    int result = 0x80000000;
    for(int i = 0; i < n; i++){
        //for(int r = 0; r < n; r++)temp[r] = 0;
        memset(temp,0,sizeof(temp));
        for(int j = i; j < n; j++){
            int cur = 0;
            for(int k = 0; k < n; k++){
                temp[k] += a[j][k];
                cur += temp[k];
                if(cur > result)result = cur;
                if(cur < 0)cur = 0;
            }
        }
    }
    return result;
}
int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
        }
    }
    int maxSum = getSubMatrixMaxSum(a);
    cout<<maxSum<<endl;
}
/*
4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
*/
