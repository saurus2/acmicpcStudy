#include <cstdio>
#include <iostream>
#include <string.h>
#include <memory.h>
int min(int &x, int &y){
    if(x>y)
        return x;
    else
        return y;
}
using namespace std;

int main(int argc, char** argv) {
    /* 아래 freopen 함수는 sample_input.txt 를 read only 형식으로 연 후,
     앞으로 표준 입력(키보드) 대신 sample_input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
     만약 본인의 PC 에서 테스트 할 때는, 입력값을 sample_input.txt에 저장한 후 freopen 함수를 사용하면,
     그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 sample_input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
     또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
     단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
    //freopen("sample_input.txt", "r", stdin);
    
    /* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
     C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
     따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
    setbuf(stdout, NULL);
    
    int T;
    int test_case;
    int n,m,k,p,cnt;
    int map[101][101]={0};
    
    scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
    for(test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        cin >> n >> m >> k;
        cnt = 0;
        for(int i = 0; i < m; i++){
            int a,b,c;
            cin >> a >> b >> c;
            map[a][b] = c;
            map[b][a] = c;
        }
        cin >> p;
        for(int i=0; i < p; i++){
            int s,e;
            cin >> s >> e;
            for(int i=1; i<=n; i++){
                if(map[s][i] != 0){
                    for(int j=1; j<=n; j++){
                        if(map[i][j] != 0 && s != j){
                            if(map[s][j] == 0) map[s][j] = map[s][i] + map[i][j];
                            else map[s][j] = min(map[s][j],map[s][i]+map[i][j]);
                        }
                    }
                }
            }
            if(map[s][e] > k) cnt++;
        }
        cout << "Case #" << test_case << endl;
        cout << cnt << endl;;
        memset(map,0,sizeof(map));
        
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
