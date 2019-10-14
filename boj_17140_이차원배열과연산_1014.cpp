#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair < int, int > pii;
vector <pii> vc;
int r,c,k,mp[101][101];
void input(){
    cin >> r >> c >> k;
    for(int i=0; i<101; i++)
        for(int j=0; j<101; j++)
            mp[i][j]=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> mp[i][j];
        }
    }
}
void rinit(int ridx){
    for(int i=0; i<100; i++)
        mp[ridx][i]=0;
}
void cinit(int cidx){
    for(int i=0; i<100; i++)
        mp[i][cidx]=0;
}
void rfunc(){
    vc.clear();
    for(int ridx=0; ridx<100; ridx++){
        for(int cidx=0; cidx<100; cidx++){
            if(mp[ridx][cidx]==0) continue;
            int vcs=vc.size();
            int f=0;
            int val=mp[ridx][cidx];
            for(int i=0; i<vcs; i++){
                if(vc[i].second==val){
                    vc[i].first++;
                    f=1;
                }
            }
            if(f==0) vc.push_back({1,val});
        }
        rinit(ridx);
        sort(vc.begin(),vc.end());
        int vcs2=vc.size();
        int vci=0;
        for(int i=0; i<vcs2*2; i++){
            mp[ridx][i]=vc[vci].second;
            i++;
            mp[ridx][i]=vc[vci].first;
            vci++;
        }
        vc.clear();
    }
}

void cfunc(){
    vc.clear();
    for(int cidx=0; cidx<100; cidx++){
        for(int ridx=0; ridx<100; ridx++){
            if(mp[ridx][cidx]==0) continue;
            int vcs=vc.size();
            int f=0;
            int val=mp[ridx][cidx];
            for(int i=0; i<vcs; i++){
                if(vc[i].second==val){
                    vc[i].first++;
                    f=1;
                }
            }
            if(f==0) vc.push_back({1,val});
        }
        cinit(cidx);
        sort(vc.begin(),vc.end());
        int vcs2=vc.size();
        int vci=0;
        for(int i=0; i<vcs2*2; i++){
            mp[i][cidx]=vc[vci].second;
            i++;
            mp[i][cidx]=vc[vci].first;
            vci++;
        }
        vc.clear();
    }
}
int ck(){
    int rs=0,cs=0;
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(mp[i][j]!=0){
                if(j>cs) cs=j;
            }
            if(mp[i][j]!=0){
                if(i>rs) rs=i;
            }
        }
    }
    if(rs>=cs) return 1;
    return 0;
}
int main(){
    input();
    for(int i=0; i<=100; i++){
        if(mp[r-1][c-1]==k){
            cout << i << endl;
            return 0;
        }
        if(ck()==1)
            rfunc();
        else
            cfunc();
    }
    cout << "-1\n";
}

