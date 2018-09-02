/*
author : Ji Ailing
email:jal@webturing.com
language: C++
*/
#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        stack<int>s;
        char ch;
        cin>>ch;
        if(ch == 'P'){
            int x;
            cin>>x;
            s.push(x);
        }
        else if(ch == 'O'){
            if(!s.empty())s.pop();
        }
        else if(ch == 'A'){
            if(s.empty()){
                cout<<"E"<<endl;
            }
            else cout<<s.top()<<endl;
        }
        cout<<endl;
    }
}
