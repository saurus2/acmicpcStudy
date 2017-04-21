nclude <iostream>
using namespace std;
int main(){
	char c;
	int f1 = 1, cnt = 0;
	while((c=getchar())!=-1 && c != '\n'){
		if(c == ' ') f1 = 1;
		else{
			if(f1 == 1) cnt++;
			f1 = 0;
		}
	}
	cout << cnt;
}
