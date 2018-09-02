
/******************01背包**************************/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
int max(int x, int y) {  //返回较大值
  return x > y ? x : y;
}

const int MAXW = 13000;  //最大重量
const int MAXN = 3450;   //最大数量

int c[MAXN];  //物品的存放要从下标1开始
int w[MAXN];  //物品的存放要从下标1开始
int dp[MAXW];
//不需要将背包装满，则将DP数组全部初始化为0
//要将背包装满，则初始化为DP[0]=0,DP[1]...DP[V]=-1(即非法状态)

int Packet(int n, int v) {

  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = v; j >= c[i]; j--)  //倒序
    {
      dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
    }
  }
  return dp[v];
}


int main(){
  int v,n;
  cin>>v>>n;
    for(int i=1;i<=n;i++){
      cin>>c[i]>>w[i];
    }
    cout<<Packet(n,v)<<endl;
    return 0;
}