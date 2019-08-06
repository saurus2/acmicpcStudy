#include <iostream>
using namespace std;
int D,W,T,K,film[14][21],cpFilm[14][21],ckFilm[14],answer=100000000;
void input(){
    answer=10000000;
    cin >> D >> W >> K;
    for(int i=0; i<D; i++){
        for(int j=0; j<W; j++){
            int tmp;
            cin >> tmp;
            if(tmp==0)
                film[i][j]=1;
            else if(tmp==1)
                film[i][j]=2;
            cpFilm[i][j]=0;
        }
    }
    for(int i=0; i<14; i++)
        ckFilm[i]=0;
}
void pfCkFilm(){
    cout << endl;
    for(int i=0; i<14; i++){
        cout << ckFilm[i] << " ";
    }
}
int test(){
    int ckRow=0;
    for(int i=0; i<W; i++){
        ckRow=0;
        for(int j=0; j<D; j++){
            int sV=cpFilm[j][i];
            if(j+1==j+K){
                ckRow=1;
                break;
            }
            for(int p=j+1; p<j+K; p++){
                if(sV != cpFilm[p][i]){
                    break;
                }
                if(p==j+K-1){
                    ckRow=1;
                }
            }
            if(ckRow==1){
                break;
            }
        }
        if(ckRow==0)
            return 0;
    }
    return 1;
}
void cp(){
    for(int i=0; i<D; i++){
        for(int j=0; j<W; j++){
            cpFilm[i][j]=film[i][j];
        }
    }
}
void changeRow(){
    for(int i=0; i<D; i++){
        if(ckFilm[i]!=0){
            for(int j=0; j<W; j++){
                cpFilm[i][j]=ckFilm[i];
            }
        }
    }
}
void pf2(){
    cout << endl << "change : " << endl;
    for(int i=0; i<D; i++){
        for(int j=0; j<W; j++){
            cout << cpFilm[i][j] << " ";
        }
        cout << endl;
    }
}
void orgPf(){
    cout << endl << "original : " << endl;
    for(int i=0; i<D; i++){
        for(int j=0; j<W; j++){
            cout << cpFilm[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void dfs(int idx,int cnt){
    if(cnt>=answer)
        return;
    if(idx>D)
        return;
    if(cnt>0){
        //solve Function
        cp();
        changeRow();
        if(test()==1){
            answer=min(answer,cnt);
        }
    }
    for(int i=idx; i<D; i++){
        if(ckFilm[i]==1 || ckFilm[i]==2)
            continue;
        ckFilm[i]=1;
        dfs(i,cnt+1);
        ckFilm[i]=0;
    }
    for(int i=idx; i<D; i++){
        if(ckFilm[i]==2 || ckFilm[i]==1)
            continue;
        ckFilm[i]=2;
        dfs(i,cnt+1);
        ckFilm[i]=0;
    }
}
int main(){
    cin >> T;
    for(int tc=1; tc<=T; tc++){
        input();
        cp();
        if(test()==1){
            answer=0;
        }else{
            dfs(0,0);
        }
        cout << "#" << tc << " " << answer << endl;
    }
}

