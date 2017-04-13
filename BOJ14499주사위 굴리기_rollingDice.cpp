#include <iostream>
#include <queue>
using namespace std;
queue<int> order;
int jido[21][21]={0};
int jusa[7]={0};
int djusa[4][3]={
    {0,2,0},
    {4,1,3},
    {0,5,0},
    {0,6,0}};
//1천장, 2위, 3오른쪽, 4왼쪽, 5아래, 6바닥
int n,m,x,y,k,nx,ny;
void pri(){
    if(jido[ny][nx]==0)
        jido[ny][nx] = jusa[djusa[3][1]];
    else{
        jusa[djusa[3][1]] = jido[ny][nx];
        jido[ny][nx] = 0;
    }
    cout << jusa[djusa[1][1]] << endl;
}
int main(){
    cin >> n >> m >> x >> y >> k;
    //높이 n, 가로 m, 출발위치xy, 명령수 k
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> jido[i][j];
        }
    }
    for(int i=0; i<k; i++){
        int tmp;
        cin >> tmp;
        order.push(tmp);
    }
    nx=y, ny=x;
    //동쪽 1, 서쪽 2, 북쪽 3, 남쪽 4
    while(!order.empty()){
        int d = order.front();
        order.pop();
        switch(d){
            case 1://동
                if(nx+1>m-1) continue;
                nx = nx+1;
                swap(djusa[3][1],djusa[1][2]);
                swap(djusa[1][2],djusa[1][1]);
                swap(djusa[1][1],djusa[1][0]);
                pri();
                break;
            case 2://서
                if(nx-1<0) continue;
                nx = nx-1;
                swap(djusa[3][1],djusa[1][0]);
                swap(djusa[1][0],djusa[1][1]);
                swap(djusa[1][1],djusa[1][2]);
                pri();
                break;
            case 3://북
                if(ny-1<0) continue;
                ny = ny-1;
                swap(djusa[0][1],djusa[1][1]);
                swap(djusa[1][1],djusa[2][1]);
                swap(djusa[2][1],djusa[3][1]);
                pri();
                break;
            case 4://남
                if(ny+1>n-1) continue;
                ny = ny+1;
                swap(djusa[3][1],djusa[2][1]);
                swap(djusa[2][1],djusa[1][1]);
                swap(djusa[1][1],djusa[0][1]);
                pri();
                break;
        }
    }
    return 0;
}
