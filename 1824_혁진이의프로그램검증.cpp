#include <iostream>
using namespace std;
int T, Testcase;
int R, C;

char map[20][20];
int visit[20][20];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int qdir = 1;
int memo;
int stopsign;

int status(int x,int y,int dir);
void dfs(int idx, int dir,int x,int y);

int main(){
    cin >> Testcase;
    for(T = 0; T<Testcase; T++){
        cin >> R >> C;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cin >> map[i][j];
            }
        }
        
        dfs(0,3,0,0);
        
        if(stopsign == 0)
            cout << "#" << T + 1 << " " << "NO" << endl;
        else
            cout << "#" << T + 1 << " " << "YES" << endl;
        
        memo = 0, stopsign = 0, qdir = 1;
        
        for(int i=0; i<20; i++){
            for(int j=0; j<20; j++){
                map[i][j] = 0;
                visit[i][j] = 0;
            }
        }
    }
    return 0;
}

int status(int x,int y, int dir){
    if(map[y][x] == '>')
        return 3;
    else if(map[y][x] == 'v')
        return 1;
    else if(map[y][x] == '<')
        return 2;
    else if(map[y][x] ==  '^')
        return 0;
    else if(map[y][x] == '_'){
        if(memo == 0)
            return 3;
        else
            return 2;
    }
    else if(map[y][x] == '|'){
        if(memo == 0)
            return 1;
        else
            return 0;
    }else if(map[y][x] == '?'){
        return 5;
    }else if(map[y][x] == '.')
        return dir;
    else if(map[y][x] == '@'){
        return -1;
    }else if(map[y][x] == '+'){
        if(memo == 15)
            memo = 0;
        else
            memo++;
    }
    else if(map[y][x] == '-'){
        if(memo == 0)
            memo = 15;
        else
            memo--;
    }else
        memo = map[y][x] - '0';
    return dir;
}

void dfs(int idx,int dir,int x,int y){
    if(stopsign == 1)
        return;
    visit[y][x]++;
    if(visit[y][x] > 4)
        return;
    int ndir = status(x,y,dir);
    if(ndir == -1){
        stopsign = 1;
        return;
    }
    else if(ndir == 5){
        for(int k=0; k<4; k++){
            qdir = k;
            int nx = (x + dx[qdir]) % C;
            int ny = (y + dy[qdir]) % R;
            if(nx < 0)
                nx = C - 1;
            if(ny < 0)
                ny = R - 1;
            dfs(idx + 1, qdir, nx, ny);
        }
    }else{
        int nx = (x + dx[ndir]) % C;
        int ny = (y + dy[ndir]) % R;
        if(nx < 0)
            nx = C - 1;
        if(ny < 0)
            ny = R - 1;
        dfs(idx + 1, ndir, nx, ny);
    }
}

