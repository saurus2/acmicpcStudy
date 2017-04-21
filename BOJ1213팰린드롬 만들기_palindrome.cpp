nclude <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	int hol=0,al[26]={0};
	char c=0;
	cin >> s;
	for(int i=0; i<s.size(); i++) al[s[i]-'A']++;
	for(int i=0; i<26; i++){
		if(al[i]%2==1) {
			if(hol){
				cout << "I'm Sorry Hansoo" << endl;
				return 0;
			}
			hol = 1;
			c = i+'A';
		}
	}
	for(int i=0; i<26; i++) for(int j=0; j<al[i]/2; j++)cout << (char)(i+'A');
	if(hol) cout << c;
	for(int i=25; i>=0; i--)for(int j=0; j<al[i]/2; j++) cout << (char)(i+'A');
}

