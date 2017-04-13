#include <stdio.h>
int t,n,
a[100005],chk[100005],st[100005],cnt;

int dfs(int x, int cnt, int sat){
    if(chk[x] != 0){
        //체크된 노드일때
        if(sat != st[x]) return 0;
        //도착점하고 이 노드의 출발지로 저장된 값이 같지 않으면 0리턴
        else return cnt-chk[x];
        //도착점하고 이 노드의 출발지가 같을때 더해진 cnt에서 사이클의 노드수를 뺌
    }
    chk[x] = cnt; st[x] = sat;
    //체크배열에 dfs를 타고 들어가는 노드의 수를 더해주고
    //노드의 출발지를 저장
    return dfs(a[x],cnt+1,sat);
    //노드를 하나 타고 들어가니 +1 하며, 출발지를 계속 가지고 재귀
}

int main(){
    int i,j;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        cnt = 0;
        scanf("%d",&n);
        for(j=1; j<=n; j++){
            scanf("%d", &a[j]);
            chk[j] = st[j] = 0;
        }
        for(j=1; j<=n; j++){
            if(chk[j]==0) cnt+=dfs(j,1,j);
            //체크된 노드가 아니면 dfs 시작하고 cnt에 추가함
        }
        printf("%d\n", n-cnt);
    }
}
