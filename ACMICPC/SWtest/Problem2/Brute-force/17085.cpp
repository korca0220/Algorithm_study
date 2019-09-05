#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <utility>
using namespace std;

int n,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    vector<pair<int,int>> hash;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<m; j++){
            map[i][j] = str[j];
            if(map[i][j] == '#')hash.emplace_back(i,j);
        }
    }

    int ans = 0;
    int hash_size = hash.size();
    for(int i=0; i<hash_size-1; i++){
        int x,y;
        tie(x,y) = hash[i];
        for(int block=0; ; block++){
            if(x-block <0 || x+block >= n) break;
            if(y-block <0 || y+block >= m) break;
            if(map[x][y-block] != '#' || map[x][y+block] != '#') break;
            if(map[x-block][y] != '#' || map[x+block][y] != '#') break;
            map[x][y-block] = '*'; map[x][y+block] = '*';
            map[x-block][y] = '*'; map[x+block][y] = '*';
            for(int j=i+1; j<hash_size; j++){
                int x2, y2;
                tie(x2,y2) = hash[j];
                for(int block2=0;;block2++){
                    if(x2-block2 < 0 || x2+block2 >= n) break;
                    if(y2-block2 < 0 || y2+block2 >= m) break;
                    if(map[x2][y2-block2] != '#' || map[x2][y2+block2] != '#') break;
                    if(map[x2-block2][y2] != '#' || map[x2+block2][y2] != '#') break;
                    int cross = (4*block+1) * (4*block2+1);
                    if(ans < cross) ans = cross;
                }
            }
        }
        for(int block=0;;block++){
            if(map[x][y-block] != '*' || map[x][y+block] != '*') break;
            if(map[x-block][y] != '*' || map[x+block][y] != '*') break;
            map[x][y-block] = '#'; map[x][y+block] = '#';
            map[x-block][y] = '#'; map[x+block][y] = '#';
        }
    }
    cout << ans;

    return 0;
}