#include <iostream>
#include<list>
#include<algorithm>
using namespace std;
int n;
int a[100000+1];
void mergeSort(int * a, int left, int right){
    int len = right - left;
    if(len >=3 ){
        int middle = left + len/2;
        mergeSort(a,left,middle);
        mergeSort(a,middle,right);
        int b[len];
        int t = 0;
        int i = left,j = middle;
        while(i < middle && j < right){
            if(a[i] < a[j]){
                b[t++] = a[i++];
            }else{
                b[t++] = a[j++];
            }
        }
        if(i == middle){
           while( j < right){
                b[t++] = a[j++];
            }
        }
        else if(j == right){
             while( i<middle){
                b[t++] = a[i++];
            }
        }
        t=0;
        for(int k = left; k < right; k++){
            a[k] = b[t++];

        }
    }
    else if( len == 2){
        if(a[left] > a[right - 1]){
                swap(a[left],a[right-1]);
        }
    }
}
int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    mergeSort(a,0,n);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}
