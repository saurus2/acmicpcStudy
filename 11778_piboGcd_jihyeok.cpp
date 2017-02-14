#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<unsigned long long>> matrix;
unsigned long long mod = 1000000007;
matrix operator * (matrix &a, matrix &b){
    //행렬을 이용한 logN 이걸리는 피보나치 수열 구하기
    long long n=a.size();
    matrix c(2, vector<unsigned long long>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}
unsigned long long gcd(unsigned long long v,unsigned long long u){
    //유클리드 호제법을 이용해서 gcd 구하기
    unsigned long long mod = u % v;
    while(mod > 0){
        u = v;
        v = mod;
        mod = u % v;
    }
    return v;
}
int main(){
    unsigned long long n=0,m=0;
    unsigned long long rgcd=0;
    cin >> n >> m;
    rgcd = gcd(n,m);
    matrix ans = {{1,0},{0,1}};
    //1을 곱했을때와 같은 역할 하는 행렬
    matrix a = {{1,1},{1,0}};
    // 1 , 1 fb(2),fb(1)
    // 1 , 0 fb(1),fb(0)
    while(rgcd>0){
        if(rgcd%2==1){
            //홀수일 경우에 그냥 한번 곱함
            ans = ans * a;
        }
        a = a * a;
        //짝수일 경우에는 2번 곱함
        rgcd /= 2;
    }
    cout << ans[0][1]%mod << endl;
    return 0;
}
