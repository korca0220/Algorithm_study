#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n,m,h;
int in[100][100];

int check(int c){

    int r = 1;
    while(r<=h){
        if(in[r][c] == 1){
            c+=1;
        }else if(in[r][c] == 2){
            c-=1;
        }
        r+=1;
    }
    return c;
}

bool go(){

    for(int i=1; i<=n; i++){
        int temp = check(i);
        if(temp != i) return false;
    }
    return true;

}


int main(){

    scanf("%d %d %d", &n, &m, &h);

    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        in[a][b] = 1;
        in[a][b+1] = 2;
    }

    vector<pair<int,int>> z_in;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=n-1; j++){
            if(in[i][j] != 0) continue;
            if(in[i][j+1] != 0) continue;
            z_in.emplace_back(i,j);
        }
    }

    int ans = -1;
    if(go()){
        printf("0");
        return 0;
    }

    int len = z_in.size();
    for(int i=0; i<len; i++){
        int x1 = z_in[i].first;
        int y1 = z_in[i].second;
        if(in[x1][y1] != 0 || in[x1][y1+1] != 0) continue;
        in[x1][y1] = 1;
        in[x1][y1+1] = 2;
        if(go()){
            if(ans==-1 || ans > 1){
                ans = 1;
            }
        }
        for(int j=i+1; j<len; j++){
            int x2 = z_in[j].first;
            int y2 = z_in[j].second;
            if(in[x2][y2] != 0 || in[x2][y2+1] != 0) continue;
            in[x2][y2] = 1;
            in[x2][y2+1] = 2;
            if(go()){
                if(ans==-1 || ans > 2){
                    ans = 2;
                }
            }

            for(int k=j+1; k<len; k++){
                int x3 = z_in[k].first;
                int y3 = z_in[k].second;
                if(in[x3][y3] != 0 || in[x3][y3+1] != 0) continue;
                in[x3][y3] = 1;
                in[x3][y3+1] = 2;
                if(go()){
                    if(ans == -1 || ans > 3){
                        ans = 3;
                    }
                }

                in[x3][y3] = 0;
                in[x3][y3+1] = 0;
            }
            in[x2][y2] = 0;
            in[x2][y2+1] = 0;
        }
        in[x1][y1] = 0;
        in[x1][y1+1] = 0;
    }
    printf("%d", ans);


    return 0;
}