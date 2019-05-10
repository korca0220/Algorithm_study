#include <cstdio>
#include <iostream>
using namespace std;


const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1 ,0, 1, -1, 1};

char boggle[5][5];
char in_boggle[5];
int t_input;
int word_input;

bool inRange(int y, int x){

    if(!boggle[x][y]) return false;
    else return true;
}

bool hasWord(int y, int x, const string &word){

    //범위 안에 없는 경우
    if(!inRange(y, x)) return false;
    
    //첫 글자부터 안맞는 경우
    if(boggle[y][x] != word[0]) return false; 

    if(word.size() ==1) return true;

    for(int direction=0; direction < 8; ++direction){
        int nextY = y + dy[direction], nextX = x + dx[direction];

        if(hasWord(nextY, nextX, word.substr(1))) return true;
    }
    return false;
}


int main(){

    scanf("%d", &t_input);

    while(t_input--){
        for(int i=0; i<5; i++){
            scanf("%s", boggle[i]);
        }

        scanf("%d", &word_input);
        bool checkword = false;
        
        for(int i=0; i<word_input; i++){
            scanf("%s", in_boggle);
            for(int x=0; x<5; x++){
                for(int y=0; y<5; y++){
                    if(checkword = hasWord(y, x, in_boggle))break;
                }
                if(checkword) break;   
            }
            if(checkword) printf("%s YES\n", in_boggle);
            else printf("%s NO\n", in_boggle);
        }
    }
    
    return 0;
}