#include <stdio.h>
int main(){
    int sum = 0;
    char c;
    while((c = getchar()) && c != EOF){
        if(c == '\n') sum++;
    }
    printf("%d",sum);
    return 0;
}
