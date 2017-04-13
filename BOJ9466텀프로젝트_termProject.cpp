#include <iostream>
#include <string.h>
using namespace std;
int arr[100003], chk[100003], num[1000003];
int main(){
    int t,n,ans;
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        for(int i=1; i<=n; i++){
            chk[i] = num[i] = 0;
            //방문 배열,
            cin >> arr[i];
        }
        int cycle = 1;
        for(int i=1; i<=n; i++){
            if(chk[i]) continue;
            //방문했으면 뛰어넘기
            else chk[i] = cycle;
            //방문하지 않았으면 사이클의 갯수 저장
            int cnt = 1, pos=i;
            num[i] = 1;
            while(1){
                pos = arr[pos];
                //해당노드의 다음노드
                if(chk[pos]) break;
                //방문 했으면 멈춤
                cnt++;
                //갯수 증가
                chk[pos] = cycle;
                //이동 노드위치에 사이클 수 입력
                num[pos] = cnt;
                //노드 갯수를 입력
            }
            if(i != pos){
                if(cycle == chk[pos]) ans += (num[pos] - 1);
                else ans += cnt;
            }
            cycle++;
        }
        cout << ans << endl;
    }
}
