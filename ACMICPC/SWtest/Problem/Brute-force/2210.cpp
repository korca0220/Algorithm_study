#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N = 5;
map<string, bool> check;
vector<string> bag;
int in[5][5];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void go(int x, int y, int len, string num){

    if(len==5){
        if(check[num]==false){
            check[num] = true;
            bag.push_back(num);
        }
        return ;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0<=nx && nx < N && 0<= ny && ny < N){
            go(nx, ny, len+1, num+to_string(in[nx][ny]));
        }
    }


}


int main(){
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            scanf("%d", &in[i][j]);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            go(i,j, 0, to_string(in[i][j]));
        }
    }
    printf("%d", bag.size());


    return 0;
}