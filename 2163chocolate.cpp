#include <iostream>
using namespace std;
int main(){
    int cho[301][301]={0,};
    int n=0,m=0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((i==0 && j>0))
                cho[i][j] = cho[i][j-1]+1;
            else if(j==0 && i>0)
                cho[i][j] = cho[i-1][j]+1;
            else if(i>0 && j>0)
                cho[i][j] = cho[i][j-1] + (i+1);
            
            for(int n1 = 0; n1 < n; n1++){
                for(int n2 = 0; n2 < m; n2++){
                    cout << cho[n1][n2] << " ";
                }
                cout << endl;
            }
        }
    }
    cout << cho[n-1][m-1];
    return 0;
}
// 1 2 3
//10 1 2
//21 3 5
//32 5 8
