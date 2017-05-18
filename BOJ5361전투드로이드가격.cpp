#include <iostream>
using namespace std;

void func(int n);

int main(){
    int n;
    cin >> n;
    func(n);
    return 0;
}

void func(int n){
    float a,b,c,d,e;
    float a2=350.34, b2=230.90, c2=190.55, d2=125.30, e2=180.90;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c >> d >> e;
        printf("$%.2f\n",a*a2+b*b2+c*c2+d*d2+e*e2);
    }
    return;
}
