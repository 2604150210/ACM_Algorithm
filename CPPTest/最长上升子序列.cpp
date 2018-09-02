#include<iostream>
using namespace std;
#define max(a,b) a>b?a:b
int main()
{
    int n, i, j, dp[101], x[101], max_len;
   cin>>n;
        for (i = 0; i < n; i++)
            cin >> x[i];

        dp[0] = 1;//表示以x[0]为子序列最右边的长度位1
        for (i = 1; i < n; i++)
        {
            dp[i] = 1;//初始化每种情况最小值为1
            for (j = 0; j < i; j++)
            {
                if (x[i]>=x[j] && dp[j] + 1>dp[i])//从0-i进行扫描,查找边界小于当前最优解长度相等的解优化最优解
                    dp[i] = dp[j] + 1;//如果允许子序列相邻元素相同  x[i]>=x[j]&&dp[j]+1>dp[i];
            }
        }
        for (i = max_len = 0; i < n; i++)
            max_len = max(max_len, dp[i]);//等到最大子序列长度
       if(max_len >=30)cout<<"yes"<<endl;
       else cout<<"no"<<endl;

    return 0;
}
