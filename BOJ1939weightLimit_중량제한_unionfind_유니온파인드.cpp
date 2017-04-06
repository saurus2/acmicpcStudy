#include <iostream>
#include <algorithm>
#include <vector>
#define mp make_pair
using namespace std;
typedef pair<int,pair<int,int>> pp;
pair<int,pair<int,int>> arr[100001];
int n,m,p[10001],s,d;
int f(int x){
    return x^p[x] ? p[x] = f(p[x]) : x;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b,v;
        cin >> a >> b >> v;
        arr[i].first = v;
        arr[i].second.first = a;
        arr[i].second.second = b;
    }
    cin >> s >> d;
    sort(arr,arr+m,greater<pp>());
    //가장 가중치가 큰것부터 사용하기위해 배열에 페어를 정렬
    for(int i=0; i<=n; i++) p[i] = i;
    //유니온 파인드를 사용하기위한 초기화
    for(int i=0; i<m; i++){
        p[f(arr[i].second.first)] = f(arr[i].second.second);
        //x좌표에서 y좌표로 갈때 y값으로 집합을 생성하는 함수
        if(f(s)==f(d)){
            cout << arr[i].first; break;
            //유니온 파인드로 만들어지 집합에서 처음 출발지와
//            도착지가 조건과 같다면 가장큰 가중치의 값을 출력
        }
    }
    return 0;
}
