#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;

bool getCheck(vector<char> a){

    int mo=0, ja=0;
    for(int i=0; i<a.size(); i++){
        if ( a[i] == 'a' || a[i] =='e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
            mo++;
        }else ja ++;
    }
    if (mo >= 1 && ja >=2) return true;
    else return false;

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;
    vector<char> alpha;
    vector<int> selected;
    char input;
    for(int i=0; i<C; i++ ){
        cin >> input;
        alpha.push_back(input);
    }
    sort(alpha.begin(), alpha.end());
    for(int i=0; i<L; i++)selected.push_back(1);
    for(int i=0; i<C-L; i++)selected.push_back(0);

    do{
        vector<char> check_temp;
        for(int i=0; i<C; i++){
            if(selected[i] != 0) check_temp.push_back(alpha[i]);
        }
        if(getCheck(check_temp)){
            for(int i=0; i<check_temp.size(); i++)cout << check_temp[i];
            cout << "\n";
        }
        
    }while(prev_permutation(selected.begin(), selected.end()));


    return 0;
}