#include <iostream>
#include <vector>
#include <string>
using namespace std;



int main(){

    vector<string> in(4);
    for(int i=0; i<4; i++){
        cin >> in[i];
    }
    int k;
    scanf("%d", &k);

    while(k--){
        vector<int> dir(4);
        int no, value;
        scanf("%d %d", &no, &value);
        no -= 1;
        dir[no] = value;
        for(int i=no-1; i>=0; i--){
            if(in[i][2] != in[i+1][6]){
                dir[i] = -dir[i+1];
            }else break;
        }

        for(int i=no+1; i<4; i++){
            if(in[i-1][2] != in[i][6]){
                dir[i] = -dir[i-1];
            }else break;
        }
        for(int i=0; i<4; i++){
            if(dir[i] == 0) continue;
            if(dir[i] == 1){
                char temp = in[i][7];
                for(int j=7; j>=1; j--){
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

    int sum = 0;
    if(in[0][0] == '1')sum+=1;
    if(in[1][0] == '1')sum+=2;
    if(in[2][0] == '1')sum+=4;
    if(in[3][0] == '1')sum+=8;

    printf("%d", sum);

    return 0;
}