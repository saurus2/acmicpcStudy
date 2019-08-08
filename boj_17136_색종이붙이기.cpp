#include <iostream>
#include <algorithm>
using namespace std;
int mp[11][11],ck[11][11],pCnt[6],total,ans=100000000;
void init(){
    for(int i=0; i<11; i++){
        for(int j=0; j<11; j++){
            mp[i][j]=ck[i][j]=0;
        }
    }
    for(int i=0; i<6; i++)
        pCnt[i]=5;
    total=0;
}
void input(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> mp[i][j];
            if(mp[i][j]==1) total++;
            ck[i][j]=0;
        }
    }
}
int st(int n,int y, int x){
    int f=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mp[y+i][x+j]==1 && ck[y+i][x+j]==0){
                f=0;
            }else{
                f=1;
            }
            if(f==1) break;
        }
        if(f==1) break;
    }
    if(f==0){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ck[y+i][x+j]=n;
            }
        }
        return 1;
    }
    return 0;
}
void cl(int n,int y,int x){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ck[y+i][x+j]=0;
        }
    }
}
void pf(){
    cout << endl;
    for(int i=0; i<10; i++){
        cout << endl;
        for(int j=0; j<10; j++){
            cout << ck[i][j] << " ";
        }
    }
}
int cntCk(){
    int tmpTotal=0;
    for(int i=1; i<6; i++){
        if(pCnt[i]!=5)
            tmpTotal+=(i*i*(5-pCnt[i]));
    }
    return tmpTotal;
}
int cntP(){
    int tmp=0;
    for(int i=1; i<6; i++){
        if(pCnt[i]!=5){
            tmp+=(5-pCnt[i]);
        }
    }
    return tmp;
}
void dfs(int y){
    if(ans <= cntP()) return;
    int tmpCnt=cntCk();
    if(tmpCnt==total){
        ans=min(cntP(),ans);
        return;
    }
    for(int i=y; i<10; i++){
        for(int j=0; j<10; j++){
            if(ck[i][j]!=0) continue;
            if(mp[i][j]==0){
                ck[i][j]=-1;
                continue;
            }
            for(int l=5; l>=1; l--){
                if(i+l>10 || j+l>10)
                    continue;
                if(pCnt[l]==0) continue;
                if(st(l,i,j)==0) continue;
                pCnt[l]--;
                dfs(i);
                pCnt[l]++;
                cl(l,i,j);
            }
            if(mp[i][j]==1){
                cout << "Fail\n";
                pf();
                return;
            }else{
                cout << "Suss\n";
                pf();
            }
        }
    }
}
int main(){
    init();
    input();
    dfs(0);
    if(ans==100000000)
        cout << "-1" << endl;
    else
        cout << ans << endl;
}

