#include <iostream>
#include <vector>
#include <string>
using namespace std;

int r,c,time;
int map[201][201];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void setBomb(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j] == 0) map[i][j] = 3;
            else if(map[i][j] >0) map[i][j] -=1;
        }
    }
}
void bomb(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j] == 1){
                map[i][j] = 0;
                for(int k=0; k<4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx>=0 && nx<r && ny>=0 && ny<c){
                        if(map[nx][ny] != 1)map[nx][ny] = 0;
                    }
                }
            }
        }
    }
}
void minusBomb(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j] > 0)map[i][j] -=1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> time;
    string str;
    for(int i=0; i<r; i++){
        cin >> str;
        for(int j=0; j<c; j++){
            if(str[j] == 'O') map[i][j] = 2; // 초기 1초를 그냥 보내기 때문
            else map[i][j] = 0;
        }
    }
    int t=2; // 초기 1초 감소, 시작 카운트
    while(t<= time){
        if(t%2 == 0){
            setBomb();
        }else{
            bomb();
            minusBomb();
        }
        t += 1;
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j] == 0) cout << ".";
            else cout << "O";
        }
        cout << "\n";
    }

    return 0;
}