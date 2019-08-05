#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int in[401][801];
int s[401][801];
int ans;

void cal(int row, int left, int right, int sum){

    if(row < 1 || row > n) return ;
    if(left < 1 || right > 2*row-1) return ;
    sum += s[row][right] - s[row][left-1];
    if(sum > ans) ans = sum;
    if(left % 2 == 0){
        cal(row-1, left-2, right, sum);
    }else{
        cal(row+1, left, right+2, sum);
    }


}

int main(){

    int tc = 0;
    while(true){        
        scanf("%d", &n);
        if(n==0) break; 
        tc++;       
        ans = -987654321;

        memset(in, 0, sizeof(0));
        memset(s, 0, sizeof(s));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=2*i-1; j++){
                scanf("%d", &in[i][j]);
                s[i][j] = s[i][j-1] + in[i][j];
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=2*i-1; j++){
                cal(i, j,j, 0);
            }
        }
        printf("%d. %d\n", tc, ans);
    }



    return 0;
}