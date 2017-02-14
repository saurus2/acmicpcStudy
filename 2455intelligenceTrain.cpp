#include <stdio.h>
int main(){
    int a=0,b=0,max=-1,res=0;
    for(int i =0 ; i<4; i++){
        scanf("%d %d",&a,&b);
        res += b;
        res -= a;
        if(max<res)
            max = res;
    }
    printf("%d",max);
}
