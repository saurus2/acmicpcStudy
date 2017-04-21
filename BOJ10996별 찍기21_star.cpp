nclude <iostream>
using namespace std;
int main(){
	int n,cnt=0; cin >> n;
	for(int k=0; k<n; k++){
		for(int j=0; j<2; j++){
			for(int i=0; i<n; i++){
				if(cnt%2 == 0) cout << "*";
				else cout << " ";
				cnt++;
			}
			if(n%2==0) cnt--;
			if(n==1) j++;
			cout << endl;
		}
	}
}
