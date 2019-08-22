#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;

bool dist[1500][1500];
int a,b,c;
int sum = 0;

void bfs(int x, int y){

    queue<pair<int,int>> q;
    q.emplace(x,y);
    dist[x][y] = true;
    while(!q.empty()){
        int nx,ny,nz;
        int sx,sy,sz;
        tie(nx,ny) = q.front();
        nz = sum - nx - ny;
        q.pop();
        if(nx != ny){
            if(nx < ny){
                sx = nx * 2;
                sy = ny - nx;
            }else{
                sx = nx - ny;
                sy = ny * 2;
            }
            if(dist[sx][sy] == false){
                q.emplace(sx,sy);
                dist[sx][sy] = true;
            }
        }
        if(nx != nz){
            if (nx < nz){
                sx = nx * 2;
                sz = nz - nx;
            }else{
                sx = nx - nz;
                sz = nz * 2;
            }
            if(dist[sx][ny] == false){
                q.emplace(sx,ny);
                dist[sx][ny] = true;
            }
        }
        if(ny != nz){
            if(ny < nz){
                sy = ny * 2;
                sz = nz - ny;
            }else{
                sy = ny - nz;
                sz = nz * 2;
            }
            if(dist[nx][sy] == false){
                q.emplace(nx,sy);
                dist[nx][sy] = true;
            }
        }
    } 
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c ;
    sum = a+b+c;
    if(sum%3 != 0){
        cout << "0";
        return 0;
    }
    memset(dist, false, sizeof(dist));
    bfs(a,b);

    cout << dist[sum/3][sum/3] ;

    return 0;
}