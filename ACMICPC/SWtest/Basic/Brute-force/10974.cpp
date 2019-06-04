#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input;

bool getNextPermu(vector<int> &perma, int n){

    int i = n-1;
    while(i > 0 && perma[i-1] >= perma[i]) i-=1;
    if(i<=0) return false;

    int j = n-1;
    while(perma[j] <= perma[i-1]) j-=1;
    swap(perma[j], perma[i-1]);

    j = n-1;
    while(i<j){
        swap(perma[i], perma[j]);
        i +=1, j-=1;
    }
    return true;

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    vector<int> number;
    for(int i=1; i<=input; i++){
        number.push_back(i);
    }

    for(int i=0; i<number.size(); i++)cout << number[i] << " ";
    cout << "\n";
    
    while(getNextPermu(number, number.size())){
        for(int i=0; i<number.size(); i++)cout << number[i] << " ";
        cout << "\n";
    }
    return 0;
}