#include <iostream>
#include <list>
#define mp make_pair

using namespace std;
int main(){
    int a,b,visited[100001]={0};
    list <pair<int,int>> que;
    
    cin >> a >> b;
    que.push_back(mp(a,0));
    visited[a]++;
    while(!que.empty()){
        int tmp,tmp2;
        tmp = que.front().first;
        visited[tmp]++;
        tmp2 = que.front().second;
        if(tmp==b) {
            cout << tmp2;
            break;
        }
        que.pop_front();
        if(tmp-1>=0 && visited[tmp-1] == 0){
            que.push_back(mp(tmp-1,tmp2+1));
            visited[tmp-1]++;
        }
        if(tmp+1 < 100001 && visited[tmp+1] == 0){
            que.push_back(mp(tmp+1,tmp2+1));
            visited[tmp+1]++;
        }
        if(tmp*2 < 100001 && visited[tmp*2] == 0){
            que.push_back(mp(tmp*2,tmp2+1));
            visited[tmp*2]++;
        }
    }
    
    return 0;
}
