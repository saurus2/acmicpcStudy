#include <iostream>
using namespace std;
int N,M,H;
int ans;

bool map[31][12];

bool check(){
    for(int i=1; i<=N; i++){
        int current = i;
        for(int j=1; j<=H; j++){
            if(map[j][current] == true)
                current += 1;
            else if(current - 1 > 0 && map[j][current-1] == true){
                current -= 1;
            }
        }
            if(i == current)
                continue;
            else
                return false;
    }
    return true;
}

void go(int row,int cnt, int target){
    if(ans != 1000000)
        return;
    if(cnt == target){
        if(check()){
            ans = cnt;
        }
        return ;
    }
    
    for(int i=row; i<=H; i++){
        for(int j=1; j<N; j++){
            if(map[i][j] == false){
                if(map[i][j-1] == false &&
                   map[i][j+1] == false){
                    map[i][j] = true;
                    go(i,cnt+1,target);
                    map[i][j] = false;
                }
            }
        }
    }
    return;
}

int main(){
    cin >> N >> M >> H;
    
    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        map[a][b] = true;
    }
    
    ans = 1000000;
    
    for(int i=0; i<4; i++){
        go(1,0,i);
        if(ans != 1000000)
            break;
    }
    
    if(ans == 1000000)
        ans = -1;
    cout << ans << endl;
    return 0;
}

