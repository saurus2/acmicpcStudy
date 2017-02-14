#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue <int> qu;
    int n=0,m=0;
    cin >> n >> m;
    for(int i=1; i<=n; i++) qu.push(i);
    cout << "<";
    while(qu.size() != 1){
        for(int j=0; j<m-1; j++) { qu.push(qu.front()); qu.pop(); }
        cout << qu.front() << ", ";
        qu.pop();
    }
    cout << qu.front();
    cout << ">";
}
