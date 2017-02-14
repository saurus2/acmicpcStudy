#include <stdio.h>
int main(){
    int n=0,counts[10001]={0,},input=0;
    //1 부터 10000 까지의 숫자 종류를 저장하기 위해 배열을 할당
    scanf("%d",&n);
    for(int i = 0; i<n; i++){
        scanf("%d",&input);
        counts[input]++;
        //숫자에 인덱스를 위해 숫자의 갯수를 세어 저장
    }
    for(int i=1; i<=10000; i++)
        counts[i] = counts[i] + counts[i-1];
        //정렬될 숫자의 인덱스를 위해 누적을 시킴
    for(int i=1; i<=10000; i++){
        int index = counts[i]-counts[i-1];
        if(i==1){
            index = counts[i];
            //첫 숫자는 전의 숫자와 비교할 필요가 없음
        }
        while(index--){
            printf("%d\n",i);
            //전 숫자와 차이만큼 숫자 출력
        }
    }
    return 0;
}

