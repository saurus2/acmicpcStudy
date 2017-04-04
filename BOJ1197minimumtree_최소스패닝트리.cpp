#include <iostream>
#include <vector>
#include <queue>
#define mp make_pair
using namespace std;
typedef pair<long long,pair<int,int>> p;
priority_queue<p,vector<p>,greater<p>>que;
int check[5]={0};
int find(int u){
    if(u == check[u]) return u;
    return check[u] = find(check[u]);
}

void merge(int u, int v){
    u = find(u), v = find(v);
    if(u > v) swap(u, v);
    if(u==v) return;
    check[u] = v;
}

int main (){
    int v,e,v1,v2;
    
    long long minsum=0,key;
    cin >> v >> e;
    for(int i=1; i<e+1; i++) check[i] = i;
    for(int i=0; i<e; i++){
        cin >> v1 >> v2 >> key;
        que.push(mp(key,mp(v1,v2)));
    }
    
    while(!que.empty()){
        int tv1,tv2;
        long long tkey;
        tv1=find(que.top().second.first);
        tv2=find(que.top().second.second);
        tkey=que.top().first;
        que.pop();
        if(check[tv1] == check[tv2]) continue;
        merge(tv1,tv2);
        minsum += tkey;
    }
    cout << minsum;
    return 0;
}
