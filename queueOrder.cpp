#include <stdio.h>
struct mQue{
    int no;
    int mOrder;
};

int main(){
    int t,i,m,n,s = 0;
    scanf("%d",&t);
    struct mQue marr[101];
    while(t--){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d",&marr[i].mOrder);
        }
        for(i=0;i<n;i++)
            marr[i].no=i;
        s = 0;
        while(1){
            for(i=1;i<n;i++)
                if(marr[0].mOrder<marr[i].mOrder)break;
            if(i!=n)
            {
                marr[n].no=marr[0].no;
                marr[n].mOrder=marr[0].mOrder;
            }else{
                s++;
                n--;
                if(marr[0].no == m)
                    break;
            }
            for(i=0;i<n;i++)
            {
                marr[i].no=marr[i+1].no;
                marr[i].mOrder=marr[i+1].mOrder;
            }
        }
        printf("%d\n",s);
    }
}
