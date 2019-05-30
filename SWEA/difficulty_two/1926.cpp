#include <iostream>
using namespace std;

int input;
int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    for(int i=1; i<=input; i++){
        bool check = false;
        if(i>10){
            int temp = i;
            while(temp){
                if(temp % 10 == 3 || temp % 10 ==  6 || temp % 10 == 9){
                    cout << "-";
                    check = true;
                }
                temp = temp/10;
            }
            if(!check) cout << i;
        }else{
            if(i == 3 || i == 6 || i == 9 )cout << "-";
            else cout << i;
        }
        cout << " ";
    }

    return 0;
}