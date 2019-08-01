#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int num[10][10]={
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};

int main(){
    int s;
    string str;
    cin >> s >>str;

    int len = str.length();
    for(int i=0; i<5; i++){
        if(i==0 || i==2 || i==4){
            for(int j=0; j<len; j++){
                int r_num = str[j] - '0';
                if(j!=0)printf(" ");
                printf(" ");
                
                if((num[r_num][0] && i == 0) || (num[r_num][3] && i == 2) || (num[r_num][6] && i == 4)){
                    for(int k=0; k<s; k++){
                        printf("-");
                    }
                }else{
                    for(int k=0; k<s; k++){
                        printf(" ");
                    }
                }
                printf(" ");
            }
            printf("\n");
        }else{
            for(int l=0; l<s; l++){
                for(int j=0; j<len; j++){
                    int r_num = str[j] - '0';
                    if(j!=0)printf(" ");

                    if((num[r_num][1] && i==1)||(num[r_num][4] && i==3))printf("|");
                    else printf(" ");

                    for(int k=0; k<s; k++){
                        printf(" ");
                    }
                    if((num[r_num][2] && i==1)||(num[r_num][5] && i==3))printf("|");
                    else printf(" ");
                }
                printf("\n");
            }
        }
    }

    return 0;
}