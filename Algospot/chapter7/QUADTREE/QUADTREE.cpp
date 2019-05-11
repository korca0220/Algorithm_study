#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;


const int MAX_SIZE = 20;

char decompressed[MAX_SIZE][MAX_SIZE];

/*
시간 초과
void decompress(string::iterator& it, int y, int x, int size){

    char head = *(it++);

    if(head == 'b' || head == 'w'){
        for(int dy ==0; dy <size; dy++){
            for(int dx ==0; dx <size; dx++){
                decompressed[y+dy][x+dx] = head;
            }
        }
    }
    else{
        int half = size/2;
        decompress(it, y, x, half);
        decompress(it, y, x+half, half);
        decompress(it, y+half, x, half);
        decompress(it, y+half, x+half, half);
    }
}
*/

string reverse(string::iterator& it){
    char head = *it;
    ++it;
    if(head == 'b' || head == 'w')
        return string(1, head);

    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(){

    int t_input;
    string s_input;
    cin.sync_with_stdio(false);
    
    scanf("%d", &t_input);

    while(t_input--){
        cin >> s_input;
        string::iterator s_iter=s_input.begin();
        cout << reverse(s_iter) << "\n";
    }


    return 0;
}