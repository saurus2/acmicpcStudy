#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;
int main(){
    vector<tuple<int,int,string>> set1;
    pair<int,int> set2;
    int n =0,age=0;
    string name;
    cin >> n;
    for(int i=0; i<n; i++){
        age = 0;
        cin >> age >> name;
        set1.push_back(tuple<int,int,string>(age,i,name));//벡터에 튜플을 이용해서 3가지 나이,들어가는순서,이름 넣기
    }
    sort(set1.begin(),set1.end());//튜플을 정렬하면 원소 순서대로 정렬함, 나이, 순서, 이름대로 정렬
    for(int i=0; i<set1.size(); i++){
        cout << get<0>(set1[i]) << " " << get<2>(set1[i]) << endl;
    }
}
