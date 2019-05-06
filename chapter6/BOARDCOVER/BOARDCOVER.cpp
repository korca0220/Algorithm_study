#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
#define CHANGE(X) X=='#' ? 1:0

const int coverType[4][3][2] = {
    { {0,0}, {1,0}, {0,1} },
    { {0,0}, {0,1}, {1,1} },
    { {0,0}, {1,0}, {1,1} },
    { {0,0}, {1,0}, {1,-1} }
};

int t_input;
int H,W;

vector<vector <int> > board;

bool set(vector<vector <int> >& board, int y, int x, int type, int delta){
    bool ok = true;
    for(int i=0; i<3; i++){ // covertType의 개수 4개, 바뀔 수 있는 위치 3개 
        const int ny = y + coverType[type][i][0]; // ex) { { {0, }, {1, }, {0, } } }
        const int nx = x + coverType[type][i][1]; // ex) { { {, 0}, {, 1}, {, 1} } }

        // 보드의 크기를 넘는 경우
        if(ny < 0 || ny >=board.size() || nx <0 || nx >=board[0].size()){
            ok = false;
        }
        // 변화 시킨 위치가 검은판인 경우
        else if( (board[ny][nx] += delta) > 1){
            ok = false;
        }
    }
    return ok;
}

int cover(vector<vector <int> >& board){
    // 아직 채우지 못한 칸은 가장 위의 왼쪽부터 찾는다
    int y = -1, x = -1;
    for(int i=0; i<board.size(), ++i){
        for(int j=0; j<board[0].size(), ++j){
            if(board[i][j] == 0){
                y = i;
                x = j;
                break;
            }
        }
        if(y != -1) break;
    }

    if( y== -1) return 1;
    int ret = 0;
    for(int type=0; type<4; ++type){
        // 만약 board[y][x]를 type 형태로 덮을 수 있으면 
        if(set(board, y, x, type, 1)) ret += cover(board);
        set(board, y, x, type, -1); // 덮었던 블록 치우기
    }
    return ret;
}

int main(){

    char board_input;
    scanf("%d", &t_input);
    
    while(t_input--){
        int ret = 0;
        scanf("%d %d", &H, &W);
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                scanf("%c", &board_input);
                board[i][j] = CHANGE(board_input);
            }
        }
        ret = cover(board);
        printf("%d\n", ret);
    }


    return 0;
}