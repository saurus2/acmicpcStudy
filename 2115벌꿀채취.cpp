#include <iostream>
using namespace std;

int map[11][11],
ch[11][11],chmap[11][11],chmap2[11][11],
n,t,m,c,maxV =0,ans=0,flag=0,maxA=0,
max1=0,max2=0;

int dfs(int i,int j,int li,int sum,int li_fu,int f){
    if(j > li_fu || ch[i][j] == 1 || chmap[i][j] == 1) return 0;
    if((li + map[i][j]) <= c){
        li += map[i][j];
        sum += map[i][j] * map[i][j];
        (sum > maxV) ? maxV = sum : maxV;
        f = 1;
    }else{
        f = 0;
    }
    ch[i][j] = 1;
    dfs(i,j+1,li,sum,li_fu,f);
    if(f == 1){
        li -= map[i][j];
        sum -= map[i][j] * map[i][j];
    }
    ch[i][j] = 0;
    dfs(i,j+1,li,sum,li_fu,f);
    return 0;
}

int main(){
    cin >> t;
    for(int tc=1; tc<=t; tc++){
        cin >> n >> m >> c;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> map[i][j];
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ch[i][j] = chmap[i][j] = chmap2[i][j] = 0;
            }
        }
        maxV = 0, ans = 0, maxA = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int tempi,tempj;
                tempi = i, tempj = j;
                ans = 0, maxV = 0;
                if(j+m > n) continue;
                dfs(i,j,0,0,j+(m-1),0);
                max1 = maxV;
                //                if(max1 != 0)
                //                    cout << "max1 : " << max1  << endl;
                for(int k=tempj; k<tempj+m; k++){
                    chmap[tempi][k] = 1;
                    chmap2[tempi][k] = 1;
                }
                for(int k=0; k<n; k++){
                    for(int l=0; l<n; l++){
                        maxV = 0;
                        if(l+m > n) continue;
                        if(chmap2[k][l] == 1) continue;
                        dfs(k,l,0,0,l+(m-1),0);
                        max2 = maxV;
                        //                        if(max2 != 0)
                        //                            cout << "max2 : " << max2 << endl;
                        if(maxA < max1 + max2) maxA = max1 + max2;
                        
                    }
                }
                for(int k=tempj; k<tempj+m; k++){
                    chmap[tempi][k] = 0;
                }
            }
        }
        cout << "#" << tc << " " << maxA << endl;
        
    }
    return 0;
}
