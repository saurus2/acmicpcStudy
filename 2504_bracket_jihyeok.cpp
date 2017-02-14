#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack <int> tac;
    //스택 만들기
    char ch[31] = {0};
    int sum=0,temp=0,temp2=0;
    cin >> ch;
    //괄호 문장 입력
    for(int i=0; i<31; i++){
        if(ch[i] == 0) break;
        //괄호가 끝나면 끝
        if(ch[i] == '('){
            tac.push(ch[i]);//열리는 괄호일때 넣기
        }else if(ch[i] == '['){
            tac.push(ch[i]);
        }else if(ch[i] == ')'){
            if(tac.top() == '('){
                tac.pop();
                tac.push(2);//닫혔을때 스택에 2 넣기
            }else if(tac.top() != '(' && tac.top() != '[' && tac.top() != ')' && tac.top() != ']'){
                temp = tac.top();//스택에 들어가 있는 원소가 숫자일때 계산
                tac.pop();
                if(tac.top() == '('){// ( 괄호 안에 들어가있는 숫자들은 곱하기 2
                    tac.pop();
                    tac.push(temp * 2);
                }
            }
        }else if(ch[i] == ']'){
            if(tac.top() == '['){
                tac.pop();
                tac.push(3);
            }else if(tac.top() != '(' && tac.top() != '[' && tac.top() != ')' && tac.top() != ']'){
                temp = tac.top();//스택에 들어있는 원소가 숫자이며 [ 괄호 안에있는 숫자들은 곱하기 3
                tac.pop();
                if(tac.top() == '['){
                    tac.pop();
                    tac.push(temp * 3);
                }
            }
        }
        while(!tac.empty()){
            if(tac.top() != '(' && tac.top() != '[' && tac.top() != ')' && tac.top() != ']'){
                temp2 += tac.top();//스택에 숫자만 남아있을때 결과 값에 더해주기 
                tac.pop();
            }else{
                if(temp2>0) tac.push(temp2);
                temp2 = 0;
                break;
            }
        }
        if(tac.empty()){
            sum += temp2;
            temp2=0;
        }
    }
    cout << sum;
}
