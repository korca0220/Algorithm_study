#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 50;
int input;
char candy[MAX][MAX];
int M_INF = -987654321;
int final_result;

int calculator(){

    // X 축 체크    
    int result = 0;

    for(int i=0; i<input; i++){
        int temp = 1;
        for(int j=0; j<input-1; j++){
            if ( candy[i][j] == candy[i][j+1] ) temp++;
            else{
                result = max(result, temp);
                temp = 1;
            }
            // 증가하고 끝난 경우
            result = max(result, temp);
        }
    }


    // y 축 체크
    for(int i=0; i<input-1; i++){
        int temp = 1;
        for(int j=0; j<input; j++){
            if ( candy[j][i] == candy[j+1][i])temp++;
            else{
                result = max(result, temp);
                temp = 1;
            }
            result = max(result, temp);
        }
    }
    return result;
}


void bomboni(){

    for(int i=0; i<input-1; i++){
        for(int j=0; j<input-1; j++){
            swap(candy[i][j], candy[i][j+1]);
            final_result = calculator();
            swap(candy[i][j], candy[i][j+1]);
        }   
    }
}

int main(){

    scanf("%d", &input);

    for(int i=0; i<input; i++){        
        scanf("%s", candy[i]);
    }
        

    return 0;
}