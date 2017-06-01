#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    char ar[32]={0};
    while(ar[0] != '#'){
        char c=0;
        int i=0,p=0,cnt = 0;
        while(ar[i]!='\0') ar[i++] = 0;
        while(c != '\n'){
            scanf("%c", &c);
            ar[p++] = c;
        }
        
        for(int k=0; k<p-2; k++){
            if(ar[k] == '1') cnt++;
            printf("%d",ar[k] - '0');
        }
        if(ar[p-2] == 'e' && cnt % 2 == 0){
            printf("0");
        }else if(ar[p-2] == 'e' && cnt % 2 == 1){
            printf("1");
        }else if(ar[p-2] == 'o' && cnt % 2 == 0){
            printf("1");
        }else if(ar[p-2] == 'o' && cnt % 2 == 1){
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
