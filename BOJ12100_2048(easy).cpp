#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int mat[20][20];
int solve(int idx);
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    printf("%d\n", solve(0));
    return 0;
}

int solve(int idx){//dfs로 깊이 5까지 내려감
    if(idx == 5){
        int ret = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                ret = max(ret,mat[i][j]);
        return ret;
    }
    int ret = 0;
    for(int i=0; i<4; i++){//4가지 방향 좌우상하로 숫자를 합침
        int temp[20][20];
        memcpy(temp,mat,sizeof(mat));//임시배열에 복사
        
        for(int q=0; q<n; q++){
            vector<int> temp;
            for(int p=0; p<n; p++)
                if((i<2 ? mat[q][p] : mat[p][q]) != 0)
                    //좌우 일때 백터에 좌표를 바꿔 순서대로 저장 , 0이 아닌 원소만!
                    temp.push_back(i<2 ? mat[q][p] : mat[p][q]);
            
            if(i==1 || i==3)
                reverse(temp.begin(),temp.end());
            vector<int> perm;
            
            for(int p=0; p<temp.size(); p++)
                if(p+1 < temp.size() && temp[p] == temp[p+1]){
                    //0,1 비교 1,2 비교 이런 식으로 비교해가면서 같으면 2배의 값을 새로운 백터에 삽입
                    perm.push_back(temp[p]*2);
                    p++;
                }else
                    perm.push_back(temp[p]);
            //같지 않으면 그냥 값만 삽입
            
            for(int p=perm.size(); p<n; p++)
                perm.push_back(0);//나머지 칸에 0으로 채움
            
            if(i==1 || i ==3)//숫자 합친 후에 방향에 따라 다시 복구
                reverse(perm.begin(), perm.end());
            
            for(int p=0; p<n; p++)//좌우상하에 따라서 원래 맵에 어디에 저장할지 조절함
                (i<2 ? mat[q][p] : mat[p][q]) = perm[p];
        }
        
        ret = max(ret, solve(idx+1));
        //dfs로 리턴되는 값과 계산한 값의 최대값을 저장
        
        memcpy(mat,temp,sizeof(temp));
        //dfs로 계속 방향바꾸면서 들어갔다 나오면 임시저장해놓았던 배열로 원상복귀한다
    }
    return ret;
    // 리턴
}
