#include <stdio.h>
int board[11][11]={0},
chessman[25]={0},//체스가 놓여있는 자리 표시
cross[25],//대각선의 위치 표시
Max = -1,
boardSize=0,
result = 0;
void dfs(int row,int cal,int cnt,int flag){
    //깊이우선탐색
    if(cnt>Max)
        //비숍의 갯수를 놓일때마다 최대값으로 갱신
        Max = cnt;
    if(cal > boardSize){
        //열이 체스판의 크기를 넘어버리면 줄을 하나 늘림
        row++;
        if(flag==0){
            //체스판의 대각선을 2부분으로 나눠 생각함
            // \ 모양의 대각선이 1칸 걸쳐서 반복됨
            if(row % 2 == 0)//줄이 짝수일 경우 대각선은 항상 2번째 부터 시작
                cal = 2;
            else
                cal = 1;//아니면 1번째 부터 시작
        }else if(flag==1){//다른 대각선 종류에 대해서 수행
            if(row % 2 == 0)//줄이 짝수일경우 대각선은 항상 1번째 부터 시작
                cal = 1;
            else
                cal = 2;//위와 마찬가지
        }
    }
    if(row > boardSize)//줄이 체스판을 넘어가 버리면 끝
        return;
    if(chessman[row + cal] == 0 && cross[10 + row - cal] == 0 && board[row][cal] == 1){
        //체스판에 놓일 비숍의 위치는 열+줄로 저장
        //대각선은 열과 줄의 차이가 최대 10이니 10 + 줄 - 열로 저장
        //체스판에 1로 표시된 곳이 비숍을 놓을 수 있는 장소
        chessman[row + cal] = 1;
        cross[10 + row - cal] = 1;
        dfs(row, cal + 2, cnt + 1,flag);//대각선은 한칸씩 걸러서 위치하기 때문에 열을 2칸 증가, 비숍 수 증가
        chessman[row + cal] = 0;//비숍을 안놨을때를 가졍하기 위함
        cross[10 + row - cal] = 0;
    }
    dfs(row, cal + 2, cnt, flag);//비숍을 놓지 않고 재귀함수를 다시 돌림
    return;
}
int main(){
    scanf("%d",&boardSize);
    for(int i=1; i<=boardSize; i++){
        for(int j=1; j<=boardSize; j++){
            scanf("%d",&board[i][j]);
        }
    }
    dfs(1,1,0,0);//대각선을 두부분으로 나눈다고 했으니 dfs 재귀함수를 두번 수행해줘야함
    result = Max;
    Max = -1;
    dfs(1,2,0,1);//마찬가지로 수행 후, 두 부분에서 비숍의 최대값들을 더해주면됨
    result += Max;
    printf("%d\n",result);
    return 0;
}
