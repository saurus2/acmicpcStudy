#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int ans=0;
void func(int ar[],int n,int m);
int binary(int ar[],int be,int mid,int v);
int main(){
    int n=0,m=0,ar[15001]={0};
    scanf("%d",&n);
    scanf("%d",&m);
    func(ar,n,m);
    return 0;
}
void func(int ar[],int n,int m){
    int tmp=0;
    for(int i=0; i<n; i++){
        scanf("%d",&tmp);
        ar[i]=tmp;
    }
    sort(ar,ar+n);
    for(int i=0; i<n; i++){
        if(binary(ar,i+1,n,m-ar[i])==1) ans++;
    }
    printf("%d",ans);
}


int binary(int ar[], int be,int la,int v){
    if(be>la) return -1;
    int mid = (be+la)/2;
    if(ar[mid]==v) return 1;
    if(ar[mid] > v){
        return binary(ar,be,mid-1,v);
    }else{
        return binary(ar,mid+1,la,v);
    }
}
