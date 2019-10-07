#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,visited[20];
long long mAns=-3000000000;
string st;
string oper;

void input(){
    cin >> n;
    cin >> st;
    for(int i=0; i<20; i++)
        visited[i]=0;
}

long long cal(){
    vector <string> tms;
    long long answer=0,a1,a2;
    int opCnt=1;
    for(int i=1; i<n; i++){
        if(st[i]=='+' || st[i]=='-' || st[i]=='*'){
            if(visited[opCnt]==0){
                string s;
                if(visited[opCnt-1]==0){
                    s="";
                    s=s+st[i-1];
                    tms.push_back(s);
                }
                s="";
                s=s+st[i];
                tms.push_back(s);
                if(i==n-2){
                    s="";
                    s=s+st[i+1];
                    tms.push_back(s);
                }
                i++;
            }else if(visited[opCnt]==1){
                string s="";
                a1=st[i-1]-'0';
                a2=st[i+1]-'0';
                if(st[i]=='+'){
                    s=to_string(a1+a2);
                }else if(st[i]=='-'){
                    s=to_string(a1-a2);
                }else if(st[i]=='*'){
                    s=to_string(a1*a2);
                }
                tms.push_back(s);
                i++;
            }
            opCnt++;
        }
    }
    int tmsSize=tms.size();
    long long tmpp1=0;
    answer=stoi(tms.at(0));
    for(int i=1; i<tmsSize-1; i++){
        if(tms.at(i)=="+"){
            tmpp1=stoi(tms.at(i+1));
            answer+=tmpp1;
        }else if(tms.at(i)=="-"){
            tmpp1=stoi(tms.at(i+1));
            answer-=tmpp1;
        }else if(tms.at(i)=="*"){
            tmpp1=stoi(tms.at(i+1));
            answer*=tmpp1;
        }
    }
    return answer;
}

void dfs(int idx,int cnt){
    mAns = max(mAns,cal());
    
    for(int i=idx; i<n/2+1; i++){
        if(visited[i]==1) continue;
        if(visited[i-1]==1) continue;
        visited[i]=1;
        dfs(i,cnt+1);
        visited[i]=0;
    }
}
int main(){
    input();
    if(n==1){
        cout << st << endl;
        return 0;
    }
    dfs(1,0);
    cout << mAns << endl;
}

