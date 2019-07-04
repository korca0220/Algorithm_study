#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int a[5][5];

int main(){

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &a[i][j]);
        }
    }

    int ans = 0;
    for(int s=0; s<(1<<(n*m)); s++){
        int sum = 0;
        // 가로 처리부분
        for(int i=0; i<n; i++){
            int cur = 0;
            for(int j=0; j<m; j++){
                int k = i*m+j;
                if((s&(1<<k)) == 0 ){ // 괄호 처리 중요! (k가 있는곳이 0인가 확인)
                    cur = cur * 10 + a[i][j];
                }else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        for(int j=0; j<m; j++){
            int cur = 0;
            // 세로 부분 처리
            for(int i=0; i<n; i++){
                int k = i*m+j;
                if((s&(1<<k)) != 0){
                    cur = cur * 10 + a[i][j];
                }else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ans = max(ans, sum);
    }

    
    printf("%d", ans);


    return 0;
}