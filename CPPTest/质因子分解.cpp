#include <bits/stdc++.h>
using namespace std;
vector<int>primes,result;
const int maxn = 100000;
bool f[maxn+1];//f[i]��ʾi�Ƿ�Ϊ����

int m;
void prime(){
    memset(f, true, sizeof(f));//�������е�����������
    f[0] = f[1] = false;//0 1 ��������
    for(int i = 2; i <= m; i++){
        if(f[i]){
            primes.push_back(i);
        }
        for(int j = 0; j < primes.size() && primes[j]*i <= m; j++){
                f[primes[j]*i] = false;
        }
    }
}
bool isPrime(int n){//ֻ��6�ı���������������п�����������2��3����
    if(n == 2 || n == 3)return 1;
    if(n%6!=1 && n % 6 != 5)return 0;//����6�ı��������һ����������
    int temp = sqrt(n);
    for(int i = 5; i <= temp; i+=6){
        if(n%i==0 || n%(i+2) == 0)return 0;
    }
    return 1;
}
void print(vector<int> v){
    for(auto i : v)cout << i << " ";
    cout << endl;
}
int main(){
    int n;
    cin>>n;
    if(isPrime(n)){
        cout << n << endl;
        return 0;
    }
    m = sqrt(n);
    prime();
   // print(primes);
    while(n!=1){
        for(int i : primes){
            if(n % i == 0){
                result.push_back(i);
                n /= i;
                break;
            }
        }
        if(isPrime(n)){
            result.push_back(n);
            break;
        }
        //cout << n << endl;
    }
    for(int i = 0; i < result.size()-1; i++)cout << result[i] << "*";
    cout << *result.rbegin()<<endl;

}
