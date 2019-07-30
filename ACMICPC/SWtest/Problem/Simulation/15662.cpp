#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    vector<string> in(T);
    for(int i=0; i<T; i++){
        cin >> in[i];
    }

    int k;
    scanf("%d", &k);
    while(k--){
        int no, value;
        vector<int> dirs(T);

        scanf("%d %d", &no, &value);
        no -= 1;
        dirs[no] = value;
        
        for(int i=no-1; i>=0; i--){
            if(in[i][2] != in[i+1][6]){
                dirs[i] = -dirs[i+1];
            }else break;
        }

        for(int i=no+1; i<T; i++){
            if(in[i-1][2] != in[i][6]){
                dirs[i] = -dirs[i-1];
            }else break;
        }

        for(int i=0; i<T; i++){
            if(dirs[i] == 0) continue;
            if(dirs[i] == 1){
                char temp = in[i][7];
                for(int j=7; j>=1; j--){
                    in[i][j] = in[i][j-1];
                }
                in[i][0] = temp;
            }
            else if(dirs[i] == -1){
                char temp = in[i][0];
                for(int j=0; j<7; j++){
                    in[i][j] = in[i][j+1];
                }
                in[i][7] = temp;
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<T; i++){
        if(in[i][0] =='1')cnt+=1;
    }
    printf("%d", cnt);

    return 0;
}