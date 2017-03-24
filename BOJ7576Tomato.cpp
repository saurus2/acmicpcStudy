#include <iostream>
#include <queue>
using namespace std;
int box[1001][1001];
typedef pair<int, int> point;
int di[] = {-1,1,0,0},
dj[] = {0,0,-1,1};
int tomato = 0,
maxtime = 1;

int main(){
    int R,C;
    cin >> C >> R;
    queue<point> q;
    for(int i = 1; i <= R; ++i){
        for(int j=1; j<= C; ++j){
            cin >> box[i][j];
            if(box[i][j] == 1 || box[i][j] == 0) tomato++;
            if(box[i][j] == 1) q.push(point(i,j));
        }
    }
    point here;
    while(!q.empty()){
        here = q.front();
        int hi = here.first;
        int hj = here.second;
        q.pop();
        tomato--;
        for(int i=0; i<4; ++i){
            int ni = hi + di[i];
            int nj = hj + dj[i];
            if(ni < 1 || ni>R || nj<1 || nj>C)continue;
            if(box[ni][nj] == 0){
                box[ni][nj] = box[hi][hj] + 1;
                q.push(point(ni,nj));
            }
        }
    }
    if(tomato == 0)
        cout << box[here.first][here.second] -1 << endl;
    else
        cout << -1 << endl;
    
    return 0;
}
