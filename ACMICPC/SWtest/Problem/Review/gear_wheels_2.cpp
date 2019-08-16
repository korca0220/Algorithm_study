#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){

    int n;
    scanf("%d", &n);
    vector<string> in(n);
    for(int i=0; i<n; i++){
        cin >> in[i];
    }
    int k;
    scanf("%d", &k);
    while(k--){
        vector<int> dir(n);
        int no, value;
        scanf("%d %d", &no, &value);
        no -= 1;
        dir[no] = value;

        for(int i=no-1; i>=0; i--){
            if(in[i][2] != in[i+1][6]){
                dir[i] = -dir[i+1];
            }else break;
        }
        for(int i=no+1; i<n; i++){
            if(in[i-1][2] != in[i][6]){
                dir[i] = -dir[i-1];
            }else break;
        }
        for(int i=0; i<n; i++){
            if(dir[i] == 0) continue;
            if(dir[i] == 1){
                char temp = in[i][7];
                for(int j=7; j>0; j--){
                    in[i][j] = in[i][j-1];
                }
                in[i][0] = temp;
            }
            else if(dir[i] == -1){
                char temp = in[i][0];
                for(int j=0; j<7; j++){
                    in[i][j] = in[i][j+1];
                }
                in[i][7] = temp;
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(in[i][0] == '1')cnt+=1;
    }
    printf("%d", cnt);


    return 0;
}