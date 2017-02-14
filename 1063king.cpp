#include <stdio.h>
#include <string.h>
int main(){
    char king[5],dol[5],w[5];
    int n =0;
    scanf("%s %s %d",king,dol,&n);
    while(n--){
        int x=0,y=0;
        w[0]=0; w[1]=0;
        scanf("%s",w);
        if(w[0]=='R'){
            x++;
            if(w[1]=='T')
                y++;
            else if(w[1]=='B')
                y--;
        }else if(w[0]=='L'){
            x--;
            if(w[1]=='T')
                y++;
            else if(w[1]=='B')
                y--;
        }else if(w[0]=='T')
            y++;
        else if(w[0]=='B')
            y--;
        
        if(king[0]+x>'H'||king[0]+x<'A'||king[1]+y>'8'||king[1]+y<'1') continue;
        king[0]+=x; king[1]+=y;
        if(king[0]==dol[0] && king[1]==dol[1]){
            if(dol[0]+x>'H'||dol[0]+x<'A'||dol[1]+y>'8'||dol[1]+y<'1') {
                king[0]-=x; king[1]-=y;
                continue;
            }
            dol[0]+=x; dol[1]+=y;
        }
    }
    printf("%s\n",king);
    printf("%s",dol);
    return 0;
}
