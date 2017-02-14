#include <iostream>
#include <vector>
using namespace std;
vector <char> v[1000];
int cnt =0;

void search(char a,int type){
    int cnt = 0;
    if(a == '.') return;
    if(type == 0) cout << a;//프리오더 일때 루트부터 출력
    search(v[a].at(cnt),type);//재귀함수로 왼쪽 자식을 탐색함
    if(type == 1) cout << a;//인오더 일때 왼쪽 자식부터 출력
    cnt++;
    search(v[a].at(cnt),type);//오른쪽 자식 탐색
    if(type == 2) cout << a;//포스트오더 일때 오른쪽 자식부터 출력 
    return ;
}

int main(){
    char a,b,c,start = '\0';
    int n = 0,ch=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        if(ch == 0) start = a;
        ch = 1;
        v[a].push_back(b); //백터로 트리 생성 부모에 연결되어있는 자식들을 백터에 삽입
        v[a].push_back(c);
    }
    search(start,0);
    cout << endl;
    search(start,1);
    cout << endl;
    search(start,2);
    cout << endl;
    return 0;
}
