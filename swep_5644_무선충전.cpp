#include <iostream>
#include <vector>

using namespace std;

typedef struct battery{
    int x;
    int y;
    int cover;
    int power;
}battery;

int dist(int x,int y,int x_,int y_){
    return abs(x-x_) + abs(y-y_);
}

int dx[5] = {0,-1,0,1,0};
int dy[5] = {0,0,1,0,-1};
int M,A,ans;

int main(){
    int tc;
    cin >> tc;
    
    for(int t=1; t<=tc; t++){
        cin >> M >> A;
        
        int x1,y1,x2,y2;
        ans=0;
        x1=0;
        y1=0;
        x2=9;
        y2=9;
        vector<battery> b(A);
        vector<vector<pair<int,int>>> p(M+1);
        
        p[0].push_back({0,0});
        p[0].push_back({9,9});
        
        for(int i=0; i<2; i++){
            for(int j=1; j<=M; j++){
                int tmp;
                cin >> tmp;
                if(i==0){
                    x1 += dx[tmp];
                    y1 += dy[tmp];
                    p[j].push_back({x1,y1});
                }else{
                    x2 += dx[tmp];
                    y2 += dy[tmp];
                    p[j].push_back({x2,y2});
                }
            }
        }
        
        for(int i=0; i<A; i++){
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2 >> b[i].cover >> b[i].power;
            b[i].x = tmp2-1;
            b[i].y = tmp1-1;
        }
        
        for(int i=0; i<=M; i++){
            int sum1 = 0, sum2 = 0;
            int cnt1 = 0, cnt2 = 0;
            int MAX = 0;
            int selected = -1;
            
            for(int j=0; j<A; j++){
                int x,y,x_,y_;
                x = p[i][0].first;
                y = p[i][0].second;
                x_ = b[j].x;
                y_ = b[j].y;
                if(dist(x,y,x_,y_) <= b[j].cover){
                    cnt1++;
                    if(b[j].power > MAX){
                        selected = j;
                        MAX = b[j].power;
                    }
                }
            }
            sum1 = MAX;
            
            int selected2 = -2;
            MAX = 0;
            for(int j=0; j<A; j++){
                int x,y,x_,y_;
                x = p[i][1].first;
                y = p[i][1].second;
                x_ = b[j].x;
                y_ = b[j].y;
                
                if(dist(x,y,x_,y_) <= b[j].cover){
                    cnt2++;
                    if(b[j].power > MAX){
                        selected2 = j;
                        MAX = b[j].power;
                    }
                }
            }
            sum2 = MAX;
            
            if(selected == selected2){
                int sum1next = 0;
                int sum2next = 0;
                
                if(cnt1==1 && cnt2 == 1){
                    ans += sum1;
                    continue;
                }
                
                if(cnt1 >=2){
                    MAX = 0;
                    for(int j=0; j<A; j++){
                        int x,y,x_,y_;
                        x = p[i][0].first;
                        y = p[i][0].second;
                        x_ = b[j].x;
                        y_ = b[j].y;
                        
                        if(j != selected && b[j].power > MAX &&
                           dist(x,y,x_,y_) <= b[j].cover){
                            MAX = b[j].power;
                        }
                    }
                    sum1next = MAX;
                }
                
                if(cnt2 >=2){
                    MAX = 0;
                    for(int j=0; j<A; j++){
                        int x,y,x_,y_;
                        x=p[i][1].first;
                        y=p[i][1].second;
                        x_=b[j].x;
                        y_=b[j].y;
                        
                        if(j!=selected && b[j].power > MAX && dist(x,y,x_,y_) <= b[j].cover){
                            MAX = b[j].power;
                        }
                    }
                    sum2next = MAX;
                }
                
                if(cnt1 >=2 && cnt2 == 1)
                    ans += (sum1next + sum2);
                
                if(cnt1 == 1 && cnt2 >= 2)
                    ans += (sum2next + sum1);
                
                if(cnt1 >=2 && cnt2 >= 2){
                    if(sum1next > sum2next)
                        ans += (sum1next + sum2);
                    else
                        ans += (sum2next + sum1);
                }
            }
            
            else{
                ans += (sum1 + sum2);
            }
        }
        cout << "#" << t << " " << ans << endl;
    }
}

