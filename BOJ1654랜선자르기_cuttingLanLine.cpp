#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> Q;
int main(){
    long long k,n,s,e,maxv=-1,mid;
    cin >> k >> n;
    for(int i=0; i<k; i++){
        int tmp;
        cin >> tmp;
        Q.push_back(tmp);
        maxv = ( maxv > tmp ? maxv : tmp);
        //가장 큰 랜선부터 시작
    }
    e=maxv; s=0;
    while(s<=e){
        //시작점이 끝점보다 이하일때만 돔
        mid = (e+s)/2;
        int cnt =0;
        for(int i=0; i<Q.size(); i++){
            cnt += Q.at(i)/mid;
        }
        if(cnt>=n) s = mid + 1;
        else if(cnt < n) e = mid - 1;
        //나눠진 숫자가 크거나 같으면 랜선의 길이를 늘리고
        //나눠진 숫자가 작으면 끝을 줄인다, 마지막까지 계속 하여
        //특정 길이가 아닌 가장 긴 랜선이 길이를 구함
    }
    cout << e << endl;
    return 0;
}
