#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int i = 0;
    int res = 0;
    int ires = 1;
    for(;;){
        ++i;
        ires += 4 * (i-1);
        res+=ires;
        if(n<res)
            break;
    }
    printf("%d",i-1);
    return 0;
}
