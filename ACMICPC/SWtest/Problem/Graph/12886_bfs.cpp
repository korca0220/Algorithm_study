#include <iostream>
#include <tuple>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

bool check[1501][1501];
int sum = 0;

void bfs(int x, int y, int c){

    queue<pair<int,int>> q;
    q.emplace(x,y);
    check[x][y] = true;
    while(!q.empty()){
        int nx,ny,nz;
        int sx,sy,sz;
        tie(nx,ny) = q.front();
        nz = sum - nx- ny;
        q.pop();
        if(nx != ny){
            if(nx < ny){
                sx = nx + nx;
                sy = ny - nx;
            }
            if(nx > ny){
                sx = nx - ny;
                sy = ny + ny;
            }
            if(check[sx][sy] == false){
                q.emplace(sx,sy);
                check[sx][sy] = true;
            }
        }
        if(nx != nz){
            if(nx < nz){
                sx = nx + nx;
                sz = nz - nx;
            }
            if( nx > nz){
                sx = nx - nz;
                sz = nz + nz;
            }
            if(check[sx][ny] == false){
                q.emplace(sx,ny);
                check[sx][ny] = true;
            }
        }
        if(ny != nz){
            if(ny < nz){
                sy = ny + ny;
                sz = nz - ny;
            }
            if(ny > nz){
                sy = ny - nz;
                sz = nz + nz;
            }
            if(check[nx][sy] == false){
                q.emplace(nx,sy);
                check[nx][sy] = true;
            }
        }
    }
}

int main(){

    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    sum = a+b+c;
    if(sum%3 != 0){
        printf("0");
        return 0;
    }
    bfs(a,b,c);
    if(check[sum/3][sum/3]){
        printf("1");
    }else printf("0");

    return 0;
}