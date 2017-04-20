nclude <iostream>
using namespace std;
int main(){
	int arr[130] = {0},i=0,maxv=-987654321;
	char c;
	while((c=getchar())&& c!=EOF){
		islower(c);
		i=c-'a';
		arr[i]++;
		if(maxv < arr[i] && c != ' ' && c != 10) {maxv = arr[i];}
	}
	for(int i=0; i<=130; i++) if(arr[i] == maxv) cout << (char)(i+'a');
	return 0;
}

