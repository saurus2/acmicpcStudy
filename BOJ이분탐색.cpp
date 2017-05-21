#include <stdio.h>
void binary_search(int ar[],int n);
void sort(int ar[],int n);
int main(){
    int ar[100001]={0};
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&ar[i]);
    }
    sort(ar,n);
    binary_search(ar, n);
    return 0;
}
void binary_search(int ar[],int n){
    int m=0,flag;
    scanf("%d",&m);
    for(int j=0; j<m; j++){
        flag=0;
        int key=0;
        scanf("%d",&key);
        int be=0,la=n-1,mid;
        while(be<=la){
            mid = (be+la)/2;
            if(ar[mid] == key){
                printf("1\n");
                flag = 1;
                break;
            }else if(ar[mid] < key) be = mid+1;
            else la = mid-1;
        }
        if(flag==0) printf("0\n");
    }
}
void sort(int ar[],int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            if(ar[j] > ar[j+1]){
                int tmp = ar[j+1];
                ar[j+1] = ar[j];
                ar[j] = tmp;
            }
        }
    }
}
