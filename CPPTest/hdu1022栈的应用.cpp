#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    int n;
    string str1,str2;
    while(cin>>n>>str1>>str2){
        stack<char>s;
        int flag[30];
        int k  = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            s.push(str1[i]);
            flag[k++] = 1;
            while(!s.empty() && s.top() == str2[j]){
                s.pop();
                j++;
                flag[k++] = 0;
            }
        }
        if(j == n){
            cout<<"Yes."<<endl;
            for(int i = 0; i < k ;i++){
                if(flag[i] ){
                    cout<<"in"<<endl;
                }
                else{
                    cout<<"out"<<endl;
                }
            }
        }else{
            cout<<"No."<<endl;
        }
        cout<<"FINISH"<<endl;
    }
}