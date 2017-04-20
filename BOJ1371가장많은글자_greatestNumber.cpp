#include <iostream>
using namespace std;
int main(){
	int arr[26] = {0},i=0,maxv=-987654321;
	char c;
	while((c=getchar())&& c!=EOF){
		islower(c);
		i=c-'a';
		arr[i]++;
		if(maxv < arr[i] && i>-1 && i<=26) {maxv = arr[i];}
	}
	for(int i=0; i<=26; i++) if(arr[i] == maxv) cout << (char)(i+'a');
	return 0;
}

