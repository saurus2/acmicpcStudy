#include <cstdio>
int main(){
    long long sum=0,num=0;
    char c;
    while((c=getchar())!=-1){
        switch(c){
            case '\n':
                continue;
            case ',' :
                sum += num;
                num = 0;
                break;
            default :
                num *= 10;
                num += c - '0';
                break;
        }
    }
    printf("%lld",sum + num);
}
