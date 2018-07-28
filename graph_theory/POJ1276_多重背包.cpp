//
// Created by jal on 18-7-28.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;
/**
 * 本题是一个多重背包
 * 可以转换成01背包
 * @return
 */
int main(){
    ifstream cin("input.txt");
    int N;
    int cash;
    while(cin>> cash >> N){
        vector<int>v(1,0);//存放一个空值放在0位。
        for(int i = 1; i <= N; i++){
            int n, w;
            cin >> n >> w;
            int k = 1;
            while(k < n){//按照二进制分解n，转换为01背包

                v.push_back(k*w);
                n = n - k;
                k = k * 2;

            }
            if (n != 0)
                v.push_back(n * w);
        }
        N = v.size()-1;
        vector<int>dp(cash+1,0);
        for(int i = 1; i <= N; i++){
            for(int j = cash; j >= v[i]; j--){
                dp[j] = max(dp[j], dp[j-v[i]] + v[i]);//01背包
            }
        }
        cout << dp[cash]<<endl;
    }
}