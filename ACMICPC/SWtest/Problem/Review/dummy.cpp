#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int main(){

    ios::sync_with_stdio(false);
    cin >> N;
    
    vector<vector<int>>map(N+1, vector<int>(N+1, -1));
    
    int a;
    cin >> a;
    vector<vector<bool>>apple(N+1, vector<bool>(N+1, false));
    for(int i=0; i<a; i++){
        int xx, yy;
        cin >> xx >> yy;
        apple[xx][yy] = true;
    }

    int dir = 0;
    int time=0;
    int len = 1;

    int k = 0;
    cin >> k;

    int x,y;
    x=y=1;
    map[x][y] = 0;
    for(int i=0; i<=k; i++){
        int t = N*N+1;
        char ch = 'L';
        if(i < k){
            cin >> t >> ch;
        }
        while(time < t){
            time+=1;
            x += dx[dir];
            y += dy[dir];
            if(x<=0 || x>=N+1 || y<=0 || y>=N+1){
                cout << time;
                return 0;
            }
            if(apple[x][y] == true){
                len+=1;
                apple[x][y] = false;
            }

            if(map[x][y] != -1){
                if(time - map[x][y] <= len){
                    cout << time;
                    return 0;
                }
            }
            map[x][y] = time;
        }
        if(ch == 'L')dir = (dir+3)%4;
        else dir = (dir+1)%4;
    }
    cout << time;

    return 0;
}