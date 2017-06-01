#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main(void){
    int hp=0,sa=0;
    string s;
    getline(cin,s);
    for(int i=0; i<s.size(); i++){
        if(s[i] == ':'){
            if(s[i+2] == ')') hp++;
            else if(s[i+2] == '(') sa++;
        }
    }
    if(hp == 0 && sa == 0) printf("none\n");
    else if(hp == sa) printf("unsure\n");
    else if(hp > sa) printf("happy\n");
    else if(hp < sa) printf("sad\n");
    return 0;
}
