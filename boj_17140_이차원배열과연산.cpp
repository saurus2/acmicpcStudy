#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair < int, int > pii;
vector < pii > vc;
int r,c,k,rmax,cmax,tm,answer;
int mp[100][100],numCnt[101][101];
void pf(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout << mp[i][j] << " ";
        }
        cout <<endl;
    }
    cout << endl;
}
void initCnt(){
    for(int i=0; i<101; i++)
        for(int j=0; j<101; j++)
            numCnt[i][j]=0;
}
void initMp(){
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
            mp[i][j]=0;
}
void input(){
    cin >> r >> c >> k;
    r--;
    c--;
    initMp();
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            cin >> mp[i][j];
}
int maxVal(int ck){
    int idx=0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(ck==0){//r
                if(mp[j][i]!=0)
                    if(idx<j){
                        idx=j;
                    }
            }else{//c
                if(mp[i][j]!=0)
                    if(idx<j){
                        idx=j;
                    }
            }
        }
    }
    return idx;
}
void ckMp(int ck){
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(ck==0){//r
                if(mp[j][i]!=0){
                    numCnt[mp[j][i]][i]++;
                }
            }else{
                if(mp[i][j]!=0){
                    numCnt[i][mp[i][j]]++;
                }
            }
        }
    }
}
void cpFunc(int ck){
    initMp();
    for(int i=0; i<100; i++){
        for(int j=1; j<=100; j++){
            if(ck==0){//r
                if(numCnt[j][i]!=0){
                    vc.push_back({numCnt[j][i],j});
                }
            }else{
                if(numCnt[i][j]!=0){
                    vc.push_back({numCnt[i][j],j});
                }
            }
        }
        sort(vc.begin(),vc.end());
        int vcSize=(int)vc.size();
        int tmpIdx=0;
        for(int j=0; j<vcSize; j++){
            if(ck==0){//r
                mp[tmpIdx][i]=vc[j].second;
                mp[tmpIdx+1][i]=vc[j].first;
                tmpIdx+=2;
            }else{
                mp[i][tmpIdx]=vc[j].second;
                mp[i][tmpIdx+1]=vc[j].first;
                tmpIdx+=2;
            }
        }
        vc.clear();
    }
    initCnt();
}
int func(){
    if(mp[r][c]==k)
        return 0;
    while(1){
        tm++;
        rmax=maxVal(0);
        cmax=maxVal(1);
        if(rmax>=cmax){
            ckMp(1);
            cpFunc(1);
        }else{
            ckMp(0);
            cpFunc(0);
        }
//        cout << "time : " << tm << endl;
//        pf();
        if(mp[r][c]==k)
            return tm;
        if(tm>100)
            return -1;
    }
}

int main(){
    input();
    answer = func();
    cout << answer << endl;
    return 0;
}

