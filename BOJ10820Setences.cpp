#include <iostream>
#include <cstring>
using namespace std;

void cnt(string str){
    int no[4]={0};
    for(int i=0; i<str.size(); i++){
        if(str[i] >= '0' && str[i] <= '9')
            no[2]++;
        else if(str[i] >= 'a' && str[i] <= 'z')
            no[0]++;
        else if(str[i] >= 'A' && str[i] <= 'Z')
            no[1]++;
        else if(str[i] == ' ')
            no[3]++;
    }
    for(int j=0; j<4; j++)
        cout << no[j] << " ";
    cout << endl;
}

int main(){
    string s;
    while(1){
        getline(cin,s);
        if(s=="")break;
        cnt(s);
    }
    return 0;
}
