//
//  main.cpp
//  Algorithm_Study
//
//  Created by jihyeok choi on 2017. 12. 11..
//  Copyright © 2017년 jihyeok choi. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int T,N,K;
struct uni{
    int ck[9][9] = {0,};
    int kF = -1;
    int rMax = -1;
    int x,y;
    int val;
};
int mp[9][9]={0,};
int ansMax = -1;
int mtMax = -1;
queue <uni> que;
int dis[4][2] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};

int main(int argc, const char * argv[]) {
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> N >> K;
        ansMax = -1;
        mtMax = -1;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> mp[i][j];
                if(mp[i][j] > mtMax)
                    mtMax = mp[i][j];
            }
        }
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(mp[i][j] == mtMax){
                    int xt = 0;
                    int yt = 0;
                    xt = j;
                    yt = i;
                    uni temp;
                    for(int q=0; q<9; q++)
                        for(int h=0; h<9; h++)
                            temp.ck[q][h] = 0;
                    temp.x = xt;
                    temp.y = yt;
                    temp.ck[yt][xt] = 1;
                    temp.rMax = 1;
                    temp.kF = -1;
                    temp.val = mtMax;
                    que.push(temp);
                }
            }
        }
        
        while(!que.empty()){
            uni temp2 = que.front();
            que.pop();
            //음... 다시 ... 체크맵 추가해서 각각 넣을려면 매번 구조체 불러와서 체크하고 넣어줘야함
            for(int k=0; k<4; k++){
                uni temp3;
                for(int q=0; q<9; q++)
                    for(int h=0; h<9; h++)
                        temp3.ck[q][h] = 0;
                temp3 = temp2;
                int x2 = temp3.x;
                int y2 = temp3.y;
                int kft = temp3.kF;
                
                if(x2+dis[k][0] > N || y2+dis[k][1] > N || x2+dis[k][0] < 1 || y2+dis[k][1] < 1 )
                    continue;
                if(temp3.ck[y2+dis[k][1]][x2+dis[k][0]] == 1)
                    continue;
                
                if(mp[y2+dis[k][1]][x2+dis[k][0]] >= temp3.val &&
                   kft == -1 &&
                  ( mp[y2+dis[k][1]][x2+dis[k][0]] - temp3.val ) < K &&
                   temp3.ck[y2+dis[k][1]][x2+dis[k][0]] == 0){
                    temp3.val = mp[y2][x2] - 1;
                    temp3.x = x2+dis[k][0];
                    temp3.y = y2+dis[k][1];
                    temp3.kF = 1;
                    temp3.ck[temp3.y][temp3.x] = 1;
                    temp3.rMax++;
                    que.push(temp3);
                }else if(temp3.ck[y2+dis[k][1]][x2+dis[k][0]] == 0 &&
                         mp[y2+dis[k][1]][x2+dis[k][0]] < temp3.val){
                    temp3.val = mp[y2+dis[k][1]][x2+dis[k][0]];
                    temp3.x = x2+dis[k][0];
                    temp3.y = y2+dis[k][1];
                    temp3.ck[temp3.y][temp3.x] = 1;
                    temp3.rMax++;
                    que.push(temp3);
                }
                
                if(temp3.rMax > ansMax)
                    ansMax = temp3.rMax;
            }
        }
        cout << "#" << tc << " " << ansMax << endl;
        
    }
    
    
    
    return 0;
}
