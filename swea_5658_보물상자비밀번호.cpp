#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n,k,t;
string st;
vector <int> vc;
void input(){
    cin >> t;
}

int jin[100];
void func(){
    vc.clear();
    char endc;
    int nm=n/4;
    int stSize=st.size();
    int tCnt=0;
    for(int ii=0; ii<=nm; ii++){
        tCnt=0;
        for(int i=0; i<4; i++){
            int tmNm=nm-1;
            int tmp=0;
            int val=16;
            for(int l=0; l<nm; l++){
                if(l==nm-1){
                    val=1;
                }else{
                    val=16;
                    for(int k=tmNm; k>1; k--){
                        val*=16;
                    }
                }
                int atmp=jin[st[tCnt]];
                tmp+=atmp * val;
                tCnt++;
                tmNm--;
            }
            int vcS=vc.size();
            int f=0;
            for(int j=0; j<vcS; j++){
                if(vc[j]==tmp){
                    f=1;
                }
            }
            if(f==0)
                vc.push_back(tmp);
        }
        endc=st[n-1];
        for(int i=n-1; i>0; i--){
            st[i]=st[i-1];
        }
        st[0]=endc;
//        cout << st << endl;
    }
    sort(vc.begin(),vc.end());
}
int main(){
    jin[49]=1;
    jin[50]=2;
    jin[51]=3;
    jin[52]=4;
    jin[53]=5;
    jin[54]=6;
    jin[55]=7;
    jin[56]=8;
    jin[57]=9;
    jin[65]=10;
    jin[66]=11;
    jin[67]=12;
    jin[68]=13;
    jin[69]=14;
    jin[70]=15;
    input();
    for(int i=1; i<=t; i++){
        cin >> n >> k;
        cin >> st;
        func();
        int answer=vc[vc.size()-k];
        cout << "#" << i << " " <<answer <<endl;
    }
}

