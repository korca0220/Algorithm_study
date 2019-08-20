#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int in[401][801];
int s[401][801];
int n;
int ans;
void getCal(int row, int left, int right, int sum){

    if(row > n || row <1) return ;
    if(left<1 || right > 2*row-1 ) return ;
    sum += s[row][right] - s[row][left-1];
    if(ans < sum) ans = sum;
    if(right % 2 == 0){
        getCal(row-1, left-2, right, sum);
    }else{
        getCal(row+1, left, right+2, sum);
    }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc = 0;
    while(true){
        cin >> n;
        if(n==0)break;
        tc++;
        ans = -987654321;
        memset(in, 0, sizeof(in));
        memset(s, 0, sizeof(s));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i*2-1; j++){
                cin >> in[i][j];
                s[i][j] = s[i][j-1] + in[i][j];
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i*2-1; j++){
                getCal(i, j, j, 0);
            }
        }
        cout << tc << ". " << ans << "\n";
    }
    return 0;
}