#include<algorithm>
#include<cstdio>
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < n; i++){
        printf("Insert element[%d]:\n",i + 1);
        printf("  Init:");
        if(i == 0){
            printf("%d\n",a[i]);
            printf("  Final:%d\n",a[i]);
        }
        else{
            //sort(a,a+i);
            for(int j = 0; j < i; j++){
                printf("%d ",a[j]);
            }
            printf("%d\n",a[i]);
            int tmp = a[i];
            int j;
            for(j = i-1; j >= 0; j--){
                if( tmp < a[j]){
                    printf("  Move back:");
                    a[j + 1] = a[j];
                    for(int k = 0; k < i; k++){
                        printf("%d ",a[k]);
                    }
                    printf("%d\n",a[i]);
                }
                else{
                    a[j+1] = tmp;
                    printf("  Final:");
                    for(int k = 0; k  < i; k++){
                        printf("%d ",a[k]);
                    }
                    printf("%d\n",a[i]);
                    break;
                }
            }
            if(j < 0){
                printf("  Final:");
                a[j+1] = tmp;
                for(int k = 0; k  < i; k++){
                        printf("%d ",a[k]);
                }
                printf("%d\n",a[i]);
            }
        }
    }
}
