#include<iostream>
using namespace std;
#define max(a,b) a>b?a:b
int main()
{
    int n, i, j, dp[101], x[101], max_len;
   cin>>n;
        for (i = 0; i < n; i++)
            cin >> x[i];

        dp[0] = 1;//��ʾ��x[0]Ϊ���������ұߵĳ���λ1
        for (i = 1; i < n; i++)
        {
            dp[i] = 1;//��ʼ��ÿ�������СֵΪ1
            for (j = 0; j < i; j++)
            {
                if (x[i]>=x[j] && dp[j] + 1>dp[i])//��0-i����ɨ��,���ұ߽�С�ڵ�ǰ���Žⳤ����ȵĽ��Ż����Ž�
                    dp[i] = dp[j] + 1;//�����������������Ԫ����ͬ  x[i]>=x[j]&&dp[j]+1>dp[i];
            }
        }
        for (i = max_len = 0; i < n; i++)
            max_len = max(max_len, dp[i]);//�ȵ���������г���
       if(max_len >=30)cout<<"yes"<<endl;
       else cout<<"no"<<endl;

    return 0;
}
