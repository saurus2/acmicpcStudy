#include <iostream>
#include <algorithm>
using namespace std;
int d[1111][33][3];
int jadu[1111][3];
int main(){
    int t,w;
    cin >> t >> w;
    int tmp;
    for(int i=1; i<=t; ++i){
        cin >> tmp;
        jadu[i][tmp] = 1;
        //자두 2-배열에 몇초에 자두가 떨어지는지 저장
    }
    d[1][0][1] = jadu[1][1];
    d[1][1][2] = jadu[1][2];
    //순서대로 시간, 이동횟수, 자두나무 번호
    //처음 시작이 1, 자두 1초에 1저장
    //2에서 받으면 이동+1, 자두 1초에 2저장
    int res = 0;
    
    for(int i=2; i<=t; ++i){//2초부터 시작
        for(int j=0; j<=w; ++j){
            //이동 한계까지 반복
            d[i][j][1] = max(d[i-1][j][1], d[i-1][j-1][2]) + jadu[i][1];
            d[i][j][2] = max(d[i-1][j][2], d[i-1][j-1][1]) + jadu[i][2];
            //1번 나무에서 받는다면 1초에서 1번에서 받은것과, 1초에서 2번에서 이동해서 받은 자두 비교
            //2번 나무에서 받으면 1초 2번, 1초 1번 비교해서 큰거에 자두 합산
            res = max(res, d[i][j][1]);
            res = max(res, d[i][j][2]);
            //이동 한계마다 하나씩 max를 확인해줘야함
            //이동 안한것, 한것 모두 max가 될 수 있어서.
        }
    }
    cout << res;
    return 0;
}
