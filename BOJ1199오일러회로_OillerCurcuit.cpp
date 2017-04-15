#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n,s;
short map[1000][1000];
vector<short> arr;

void dfs(short idx){
    for(int i=0; i<n; i++){
        //        dfs로 탐색
        while(map[idx][i]){
            map[idx][i]--;
            map[i][idx]--;
            dfs(i);
            //            오일러 회로니까 가는선 오는선 모두 제거 , 오일러 회로가 된다는 가정하에 수행
        }
    }
    arr.emplace_back(++idx);
    //    dfs로 마지막까지 다돌고 난 뒤에 끝날때 인덱스를 벡터에 넣어준다.
}

int main(){
    bool check = true;
    cin >> n;
    for(int i=0; i<n; i++){
        s=0;
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            s += map[i][j];
            //            오일러 회로인 지 판단하기 위해 간선의 갯수를 더한다
        }
        if(s & 1) check = false;
        //        간선이 홀수이면 오일러 회로가 성립하지 않음
    }
    if(!check) {
        cout << "-1";
        return 0;
    }else{
        dfs(0);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(map[i][j] != 0) check = 0;
        //        오일러 회로이라면 모든 간선을 다 뺐음
        if(check)
            for(int i=arr.size()-1; i>=0; --i)
                cout << arr.at(i) << " ";
        //        백터에 인덱스를 넣을때 dfs로 끝까지 내려가서 입력했기 때문에 반대로 출력
        else cout << "-1" << endl;
    }
    return 0;
}
