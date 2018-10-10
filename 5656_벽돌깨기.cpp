#include <iostream>
using namespace std;

int N,W,H;
int ans;
int map[15][12];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool check_range(int x, int y){
    if(x >= 0 && y >= 0 && x < H && y < W)
        return true;
    else
        return false;
}

void breakWall(int x,int y){
    if(map[x][y] == 0)
        return;
    
    int d = map[x][y];
    map[x][y] = 0;
    
    for(int i=1; i<d; i++){
        for(int j=0; j<4; j++){
            int nx = x + dx[j] * i;
            int ny = y + dy[j] * i;
            
            if(check_range(nx, ny) && map[nx][ny] != 0)
                breakWall(nx, ny);
        }
    }
}

void allign_map(){
    for(int i=0; i<W; i++){
        for(int j=H-2; j>=0; j--){
            int x = j, y = i;
            
            if(map[x][y] == 0)
                continue;
            
            while(true){
                if(map[x+1][y] == 0 && check_range(x+1, y)){
                    map[x+1][y] = map[x][y];
                    map[x][y] = 0;
                    x++;
                }else
                    break;
            }
        }
    }
}

void go(int k){
    int tmp[15][12];
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            tmp[i][j] = map[i][j];
    
    if(k == N){
        int cnt = 0;
        for(int i=0; i<H; i++)
            for(int j=0; j<W; j++)
                if(map[i][j] != 0)
                    cnt++;
        if(cnt < ans)
            ans = cnt;
        
        return;
    }
    
    for(int i=0; i<W; i++){
        int x =0, y=i;
        while(check_range(x,y) && map[x][y] == 0)
            x++;
        
        breakWall(x, y);
        allign_map();
        go(k+1);
        
        for(int j=0; j<H; j++){
            for(int k=0; k<W; k++){
                map[j][k] = tmp[j][k];
            }
        }
    }
}

int main(){
    int tc;
    cin >> tc;
    
    for(int t=1; t<=tc; t++){
        cin >> N >> W >> H;
        
        ans = 999999999;
        for(int i=0; i<H; i++)
            for(int j=0; j<W; j++)
                cin >> map[i][j];
        
        go(0);
        
        cout << "#" << t << " " << ans << endl;
    }
}

