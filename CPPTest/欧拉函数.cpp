#include <bits/stdc++.h>
using namespace std;
/*����ɸO(n)ʱ�临�Ӷ���ɸ��maxn��ŷ������ֵ*/
const int maxn = 32770;
int m[maxn],phi[maxn],p[maxn],pt;//m[i]��i����С��������p��������pt����������

int make()
{
    phi[1]=1;
    int N=maxn;
    int k;
    for(int i=2;i<N;i++)
    {
        if(!m[i])//i������
            p[pt++]=m[i]=i,phi[i]=i-1;
        for(int j=0;j<pt&&(k=p[j]*i)<N;j++)
        {
            m[k]=p[j];
            if(m[i]==p[j])//Ϊ�˱�֤�Ժ����������ɸ��Ҫbreak
            {
                phi[k]=phi[i]*p[j];
/*�����phi[k]��phi[i]����ġ�(p[i]-1)/p[i]��һ����m[i]==p[j]��ֻ��һ��p[j]���Ϳ��Ա�֤��(p[i]-1)/p[i]ǰ��Ҳһ����*/
                break;
            }
            else
                phi[k]=phi[i]*(p[j]-1);//���Ժ������ʣ�f(i*k)=f(i)*f(k)
        }
    }
}
int main(){
    make();
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        cout<<phi[n]<<endl;
    }
}
