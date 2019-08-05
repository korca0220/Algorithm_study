#include <iostream>
#include <cstring>
using namespace std;

bool s[201][201];

int main(){

    int n,m;
    scanf("%d %d", &n, &m);
    memset(s, true, sizeof(s));

    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        s[a][b] = false;
        s[b][a] = false;
    }
    int ans=0;
    for(int i=1; i<=n-2; i++){
        for(int j=i+1; j<=n-1; j++){            
            for(int k=j+1; k<=n; k++){                
                if(s[i][j] && s[i][k] && s[j][k]){                    
                    ans+=1;
                }
            }
        }
    }
    printf("%d", ans);

    return 0;
}