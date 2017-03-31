#include <iostream>
#include <map>
#include <vector>

typedef long long ll;
using namespace std;

int n,m,test;
map < pair<int,int>, int>result;
//도착지의 좌표와 값을 맵의 키와 값으로 저장
vector < pair<int, pair<int, int> > > vp;
//출발지의 값과 좌표를 백터에 저장
int mp[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0}};
//이동 방법을 저장
int mirror[1010][1010];
//반사될 거울을 저장할 2차원배열

bool isInBox(int h,int w){
    if(h<1 || h>n || w<1 || w>m) return false;
    //배열을 넘어 도착지에 들어가는 것을 확인 하는 함수
    return true;
}

int change(int t){
    //거울을 만났을때 진행방향을 바꿔줄 함수
    if(t == 0) return 1;
    if(t == 1) return 0;
    if(t == 2) return 3;
    if(t == 3) return 2;
    return 0;
}

int main(){
    int cnt = 1;
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> mirror[i][j];
            //거울 정보 입력
        }
    }
    
    for(int i=1; i<=n; i++){
        //왼쪽 세로줄 숫자 값 입력
        vp.push_back(make_pair(cnt, make_pair(i,0)));
        result[make_pair(i,0)] = cnt;
        cnt++;
    }
    
    for(int i=1; i<=m; i++){
        //아래 줄 숫자 값 입력
        vp.push_back(make_pair(cnt, make_pair(n+1,i)));
        result[make_pair(n+1, i)] = cnt;
        cnt++;
    }
    
    for(int i=n; i>0; i--){
        //오른쪽 세로줄 값 입력
        vp.push_back(make_pair(cnt, make_pair(i,m+1)));
        result[make_pair(i,m+1)] = cnt;
        cnt++;
    }
    
    for(int i=m; i>0; i--){
        //맨 위쪽 가로줄 값 입력
        vp.push_back(make_pair(cnt, make_pair(0,i)));
        result[make_pair(0,i)] = cnt;
        cnt++;
    }
    
    for(int i=0; i<vp.size(); i++){
        int h = vp[i].second.first;
        int w = vp[i].second.second;
        //시작할 세로 가로 입력
        int type = 3;
        //첫시작 방향 입력
        if(1 <= vp[i].first && vp[i].first <= n) type = 0;
        else if(n < vp[i].first && vp[i].first <= m + n) type = 1;
        else if(n + m < vp[i].first && vp[i].first <= 2*n + m) type =2;
        //맵에 저장된 출발지로 방향을 정함
        h += mp[type][0];
        w += mp[type][1];
        //한칸 움직이고
        while(isInBox(h,w)){
            //맵을 벗어나 도착지 값과 같다면 탈출
            if(mirror[h][w] == 1)
                type = change(type);
            // 거울이 있으면 방향에 따라 함수를 사용해 방향을 바꿈
            h += mp[type][0];
            w += mp[type][1];
            //계속해서 한칸씩 옮기며 확인함
        }
        //도착지의 숫자 값을 출력
        printf("%d ", result[make_pair(h,w)]);
    }
    
    
}
