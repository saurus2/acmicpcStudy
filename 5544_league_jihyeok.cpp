#include <iostream>
#include <algorithm>
bool op(int a,int b) { return a>b; }
using namespace std;
int main(){
    int n=0,a=0,b=0,sa=0,sb=0,score[101]={0,},rank[100]={0,},people=1,tscore[101]={0,};
    cin >> n;
    for(int i=0; i<n*(n-1)/2; i++){
        cin >> a >> b >> sa >> sb;
        if(sa>sb) score[a-1]+=3;
        else if(sa<sb) score[b-1]+=3;
        else if(sa == sb) {score[a-1]++; score[b-1]++;}
    }
    for(int i=0; i<n; i++) tscore[i] = score[i];
    sort(score,score+n,op);
    rank[0] = 1;
    people = 2;
    for(int i=1; i<n; i++){
        if(score[i] == score[i-1]) {people++; rank[i] = rank[i-1];}
        else{rank[i] = people; people++;}
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(tscore[i] == score[j]) {
                cout << rank[j] << endl;
                break;
            }
        }
    }
    
}
