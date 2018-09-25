#include <iostream>
#include <deque>
using namespace std;
int mp[101][101] = {0,};
int dis[4][2] ={
    {0,1},
    {-1,0},
    {0,-1},
    {1,0}
};
// 0 / 1 / 2,1 / 2,3,2,1
/// 0 / 1,0 / 1,2,1,0 / 2,3,2,1,1,2,1,0 /
int boxed[4][2]={
    {0,0},
    {0,1},
    {1,0},
    {1,1}
};
int N,x,y,d,g,ans = 0;
deque <int> que;
deque <int> tmpque;
int main(){
    cin >> N;
    ans = 0;
    for(int i=0; i<N; i++){
        cin >> x >> y >> d >> g;
        que.push_front(d);
        mp[y][x] = 1;
        y = y+dis[d][0];
        x = x+dis[d][1];
        mp[y][x] = 1;
//        cout << endl;
//        for(int o=0; o<(int)que.size(); o++){
//            cout << " " << que[o];
//        }
//        cout << endl;
        int ck = 0;
        for(int j=0; j<g; j++){
            int que_size = (int)que.size();
//            cout << endl << " que : ";
//            for(int o=0; o<que_size; o++){
//                cout << " " << que[o];
//            }
//            cout << endl;
            for(int k=0; k<que_size; k++){
                int tmp_d = que[k];
                tmp_d = (tmp_d + 1) % 4;
                y = (y + dis[tmp_d][0]);
                x = (x + dis[tmp_d][1]);
                if(y < 0 || x < 0 || y > 100 || x > 100){
                    ck = 1;
                    break;
                }
                mp[y][x] = 1;
//                que.push_front(tmp_d);
                tmpque.push_back(tmp_d);
//                cout << endl;
//                for(int q=0; q<10; q++){
//                    for(int w=0; w<10; w++){
//                        cout << " " << mp[q][w];
//                    }
//                    cout << endl;
//                }
            }
//            cout << endl << " tmpque : " ;
//            for(int o=0; o<que_size; o++){
//                cout << " " << tmpque[o];
//            }
            for(int o=0; o<que_size; o++){
                que.push_front(tmpque[o]);
            }
            tmpque.clear();
            if(ck == 1){
                ck = 0;
                break;
            }
        }
        que.clear();
    }
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            int fCnt = 0;
            for(int a=0; a<4; a++){
                if(mp[i+boxed[a][0]][j+boxed[a][1]] == 1){
                    fCnt++;
                }else{
                    break;
                }
                if(fCnt==4)
                    ans++;
            }
        }
    }
//    cout << endl;
    cout << ans;
    return 0;
}

