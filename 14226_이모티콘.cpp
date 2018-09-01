#include <iostream>
#include <deque>
using namespace std;

int ans,cnt = 0;
bool chk[2001][2001];

struct node{
    int anser;
    int clip;
};

deque <node> que;

int main(){
    cin >> ans;
    node n1;
    n1.anser = 1;
    n1.clip = 0;
    chk[1][0] = 1;
    
    que.push_back(n1);
    while(!que.empty()){
        int que_size = (int)que.size();
        while(que_size--){
            node temp = que.front();
            que.pop_front();
            
            if(temp.anser == ans){
                cout << cnt << endl;
                return 0;
            }
            
            node copy = temp;
            copy.clip = copy.anser;
            que.push_back(copy);
            
            if(temp.clip >= 0){
                node paste = temp;
                paste.anser = temp.anser + temp.clip;
                if(chk[paste.anser][paste.clip] == 0 &&
                   paste.anser <= 1000)
                    que.push_back(paste);
                chk[paste.anser][paste.clip] = 1;
            }
            
            node abs = temp;
            abs.anser--;
            if(chk[abs.anser][abs.clip] == 0 &&
               abs.anser > 1)
                que.push_back(abs);
            chk[abs.anser][abs.clip] = 1;
        }
        cnt++;
    }
}




