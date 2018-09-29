#include <iostream>
using namespace std;
int diseR[4] ={0,};
int diseC[2] ={0,};
int N,M,y,x,K;
int mp[21][21];
int main(){
    cin >> N >> M >> y >> x >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> mp[i][j];
        }
    }
    for(int i=0; i<K; i++){
        int dis;
        cin >> dis;
        //0
        //1
        //2
        //3
        
        //0
        //1
        int t_up,t_down,t_front,t_back,t_left,t_right;
        t_down = diseR[0];
        t_front = diseR[1];
        t_up = diseR[2];
        t_back = diseR[3];
        
        t_left = diseC[0];
        t_right = diseC[1];
        
        switch(dis){
            case 1:
                if(x+1 >= M) continue;
                x++;
                diseR[2] = t_left;
                diseR[0] = t_right;
                diseC[0] = t_down;
                diseC[1] = t_up;
                cout << diseR[2] << endl;
                if(mp[y][x] == 0){
                    mp[y][x] = t_right;
                }else{
                    diseR[0] = mp[y][x];
                    mp[y][x] = 0;
                }
                break;
            case 2:
                if(x-1 < 0) continue;
                x--;
                diseR[2] = t_right;
                diseR[0] = t_left;
                diseC[0] = t_up;
                diseC[1] = t_down;
                cout << diseR[2] << endl;
                if(mp[y][x] == 0){
                    mp[y][x] = t_left;
                }else{
                    diseR[0] = mp[y][x];
                    mp[y][x] = 0;
                }
                break;
            case 3:
                if(y-1 < 0) continue;
                y--;
                diseR[0] = t_back;
                diseR[1] = t_down;
                diseR[2] = t_front;
                diseR[3] = t_up;
                cout << diseR[2] << endl;
                if(mp[y][x] == 0){
                    mp[y][x] = t_back;
                }else{
                    diseR[0] = mp[y][x];
                    mp[y][x] = 0;
                }
                break;
            case 4:
                if(y+1 >= N) continue;
                y++;
                diseR[0] = t_front;
                diseR[1] = t_up;
                diseR[2] = t_back;
                diseR[3] = t_down;
                cout << diseR[2] << endl;
                if(mp[y][x] == 0){
                    mp[y][x] = t_front;
                }else{
                    diseR[0] = mp[y][x];
                    mp[y][x] = 0;
                }
                break;
        }
    }
}

