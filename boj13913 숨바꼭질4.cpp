#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int visited[100001] = {0,};
int trace[100001] = {0,};
deque <int> que;
vector <int> vt;
#define MAX 100005
int main(){
    int n,k;
    cin >> n >> k;
    que.push_back(n);
    for(int i=0; i<100001; i++)
        trace[i] = -1;
    while(!que.empty()){
        int now = que.front();
        que.pop_front();
        
        if(now == k){
            break;
        }
        
        if(now * 2 <= MAX && trace[now * 2] == -1){
            que.push_back(now*2);
            trace[now*2] = now;
        }
        
        if(now + 1 <= MAX && trace[now + 1] == -1){
            que.push_back(now+1);
            trace[now+1] = now;
        }
        
        if(now - 1 >= 0 && trace[now - 1] == -1){
            que.push_back(now-1);
            trace[now-1] = now;
        }
    }
    int des = k;
    while(des != n){
        vt.push_back(trace[des]);
        des = trace[des];
    }
    cout << vt.size() << endl;
    for(int i=vt.size() - 1; i >= 0; i--){
        cout << vt[i] << " ";
    }
    cout << k;
    return 0;
}
