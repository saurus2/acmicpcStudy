#include <stdio.h>
int main(){
    char ar[101][101]={0};
    int n,op;
    scanf("%d",&n);
    getchar();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1c",&ar[i][j]);
        }
        getchar();
    }
    scanf("%d",&op);
    if(op == 1){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%c",ar[i][j]);
            }
            printf("\n");
        }
    }else if(op == 2){
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=0; j--){
                printf("%c",ar[i][j]);
            }
            printf("\n");
        }
    }else if(op == 3){
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                printf("%c",ar[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}


