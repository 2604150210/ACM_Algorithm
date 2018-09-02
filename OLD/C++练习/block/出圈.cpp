#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
struct Node{
    int val;
    Node*next;
};
int main(){
    int n,m;
    while(cin>>n>>m){
        Node a[n];
        for(int i = 0; i < n-1; i++){
            a[i].val=i+1;
            a[i].next = &a[i+1];
        }
        a[n-1].val = n;
        a[n-1].next = &a[0];
        Node* p=&a[0];
        while(p->next!=p){
            Node*temp = p;
            int i=0;
            while(i<m-2){
                temp = temp->next;
                i++;
            }
            temp->next = temp->next->next;
            p=temp->next;
        }
        cout << p->val<<endl;
        }
}


