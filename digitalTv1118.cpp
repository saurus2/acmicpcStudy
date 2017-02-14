#include <stdio.h>
#include <string.h>
void swap(char *a,char *b){
    char t[11];
    strcpy(t,a);
    strcpy(a,b);
    strcpy(b,t);
}
int main(){
    int t = 0;
    int i = 0;
    int cnt,cnt1,cnt2;
    cnt = 0; cnt1 = 0; cnt2 = 0;
    char ch[101][11]={0,};
    scanf("%d", &t);
    while(t--){
        scanf("%s",ch[i++]);
    }
    i = 0;
    for(;;i++){
        if(strcmp(ch[i],"KBS1") == 0)
            break;
        printf("1");
    }
    for(;i>0;--i){
        swap(ch[i],ch[i-1]);
        printf("4");
    }
    i=0;
    for(;;i++){
        if(strcmp(ch[i],"KBS2")==0)
            break;
        printf("1");
    }
    for(;i>1;i--){
        swap(ch[i],ch[i-1]);
        printf("4");
    }
    return 0;
}
