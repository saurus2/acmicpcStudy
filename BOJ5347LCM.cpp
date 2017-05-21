#include <stdio.h>
void func();
int main(){
    func();
    return 0;
}
void func(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        int tmp=1,a1,b1;
        if(a>b) {a1=a,b1=b;}//a,b의 크기에 따라 교환해 줌
        else {a1=b; b1=a;}
        while(tmp!=0){//최소 공약수 구하기
            tmp = a1%b1;
            a1 = b1;//최소 공약수
            b1 = tmp;
        }
        printf("%d\n",a*b/a1);//최대 공배수 구하기
    }
}
