#include <iostream>
#include <map>
#include <list>
#define mp make_pair
#define q1 que.front().first
#define q2 que.front().second
using namespace std;

map <pair<int,int>,int> mmap;
map <pair<int,int>,int> visited;
list <pair<int,int>> que;

int main(){
    int n,m;
    char c;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> c;
            mmap[mp(i,j)] = c - '0';
        }
    }
    que.push_back(mp(0,0));
    visited[mp(0,0)]++;
    while(!que.empty()){
        pair<int,int> p = mp(q1,q2);
        if(q1 >= 0 && q1 < n && q2 >= 0 && q2 < m){
            pair<int,int> p1 = mp(q1+1, q2);
            if(mmap[p1] >= 1 && !visited[p1]){
                visited[p1]++;
                if(mmap[p1] == 1)
                    mmap[p1] = mmap[p]+1;
                que.push_back(p1);
            }
            p1 = mp(q1, q2+1);
            if(mmap[p1] >= 1 && !visited[p1]){
                visited[p1]++;
                if(mmap[p1] == 1)
                    mmap[p1] = mmap[p]+1;
                que.push_back(p1);
            }
            p1 = mp(q1-1, q2);
            if(mmap[p1] >= 1 && !visited[p1]){
                visited[p1]++;
                if(mmap[p1] == 1)
                    mmap[p1] = mmap[p]+1;
                que.push_back(p1);
            }
            p1 = mp(q1, q2-1);
            if(mmap[p1] >= 1 && !visited[p1]){
                visited[p1]++;
                if(mmap[p1] == 1)
                    mmap[p1] = mmap[p]+1;
                que.push_back(p1);
            }
        }
        que.pop_front();
    }
    cout << mmap[mp(n-1,m-1)] << endl;
    return 0;
}
