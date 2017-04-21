#include <iostream>
using namespace std;
int main(){
	int t,ar[7]={0};
	cin >> t;
	while(t--){
		int tmp,i=0,j=0,rev =0,tmpr=0,cnt=0;
		cin >> tmp;
		tmpr = tmp;
		rev = tmp%10;
		tmp/=10;
		while(tmp/10!=0){
			rev = rev * 10 + tmp%10;
			i++;
			tmp /= 10;
		}
		rev = rev * 10 + tmp%10;
		rev += tmpr;
		while(rev/10!=0){
			ar[j] = rev%10;
			rev/=10;
			j++;
		}
		ar[j]=rev%10;
		for(int i=0; i<=j && i<=j/2-1; i++){
			if(ar[i] == ar[j-i]){
				cnt++;
			}
		}
		if(cnt == j/2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
