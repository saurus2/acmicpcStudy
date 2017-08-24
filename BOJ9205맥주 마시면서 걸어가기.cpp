#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <stdio.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        n += 2;
        vector<vector<pair<int,int>>>map(n);
        vector<pair<int,int>> map2(n);
        int c[101] = {0};
        for(int i=0; i<n; i++){
            int x,y;
            cin >> x >> y;
            map2[i].first = x;
            map2[i].second = y;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                int dis = abs(map2[i].first-map2[j].first) + abs(map2[i].second-map2[j].second);
                if(dis <= 1000){
                    map[i].push_back(make_pair(j,dis));
                }
            }
        }
        stack<int> stack2;
        stack2.push(0);
        c[0]=1;
        while(!stack2.empty()){
            int here = stack2.top();
            int sc = 0;
            for(int i=0; i<map[here].size(); i++){
                if(c[map[here][i].first]==true) continue;
                else{
                    c[map[here][i].first]=true;
                    stack2.push(map[here][i].first);
                    sc = 1;
                    break;
                }
            }
            if(sc==0)
                stack2.pop();
        }
        if(c[n-1]==1){
            cout << "happy" << endl;
        }else
            cout << "sad" << endl;
    }
    return 0;
}
