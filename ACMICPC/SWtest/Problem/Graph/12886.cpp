#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

bool check[500][500];
int sum = 0;

void dfs(int x, int y){

    if (check[x][y]) return;
    check[x][y] = true;
    int a[3] = {x, y, sum-x-y};
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (a[i] < a[j]) {
                int b[3] = {x, y, sum-x-y};
                b[i] += a[i];
                b[j] -= a[i];
                dfs(b[0], b[1]);
            }
        }
    }
}

int main(){

    vector<int> a(3);
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    sum = a[0] + a[1] + a[2];
    if(sum%3 != 0){
        printf("0");
        return 0;
    }
    dfs(a[0], a[1]);
    if(check[sum/3][sum/3]){
        printf("1");
    }else printf("0");

    return 0;
}