#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int in[5][5];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
map<string, bool> str;
vector<string> bag;

void getBag(int x, int y, int index, string num){

    if(x<0 || x>=5 || y<0 || y>=5) return ;
    if(index==6){                    
        if(str[num] == false){            
            str[num] = true;
            bag.push_back(num);
        }
        return ;
    }

    for(int i=0; i<4; i++){
        getBag(x+dx[i], y+dy[i], index+1, num+to_string(in[x][y]));        
    }

}

int main(){

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> in[i][j];
        }
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            getBag(i,j,0,"");
        }
    }
    cout << bag.size();

    return 0;
}