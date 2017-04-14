#include <stdio.h>
int map[21][21];
int roll[7];
int mov[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };
int arr[3] = {3,5,1}; //옆, 앞, 위
void move(int n){
    int cur = (n-1) >> 1;
    int tmp;
    int mv = 0;
    if( n == 1 || n == 4) // 1동 2서 3북 4남
        mv = 1;
    if(mv) {
        tmp = arr[cur];
        arr[cur] = arr[2];
        arr[2] = 7 - tmp;
        //윗면인 2번에 5의 반대편을 올려줌
        //윗면에 3을 올려줌
    }else{
        tmp = arr[2];
        arr[2] = arr[cur];
        //오른면인 3을 위로 올려줌
        //왼면인 4를 위로 올려줌
        arr[cur] = 7 - tmp;
    }
}

int main(){
    int n,m,x,y,k;
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &map[i][j]);
    int mv;
    int a,b;
    while(k--){
        scanf("%d", &mv);
        a = x + mov[mv-1][0];
        b = y + mov[mv-1][1];
        //방향에 1칸 만큼 더해줌
        if(0 <= a && a < n && 0 <= b && b < m){
            move(mv);
            // 주사위의 위치 변경
            x = a;
            y = b;
            //변경된 좌표 입력
            if(map[x][y]){
                //맵에 숫자가 있으면
                roll[7 - arr[2]] = map[x][y];
                //주사위 면에 윗면과 반대 좌표에 맵에 적힌 숫자 저장
                map[x][y] = 0;
                //맵은 0
            }else{
                map[x][y] = roll[7 - arr[2]];
                //맵에 0이면 주사위 숫자 입력
            }
            printf("%d\n", roll[arr[2]]);
        }
    }
    
}
