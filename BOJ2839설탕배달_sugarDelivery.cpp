#include <cstdio>
int main(){
    int n;
    scanf("%d",&n);
    if(n%5 == 0){
        printf("%d",n/5);
        return 0;
    }
    else{
        int ret = n, cnt = 1;
        while(ret>0){
            ret = n - cnt * 3;
            //3을 배수로 계속 빼면서 5로 나눠지면 출력
            if(ret % 5 == 0)
            {
                printf("%d",ret/5 + cnt);
                return 0;
            }else if(ret == 3){
                printf("%d",n/3);
                return 0;
            }
            cnt++;
        }
    }
    printf("-1");
}
