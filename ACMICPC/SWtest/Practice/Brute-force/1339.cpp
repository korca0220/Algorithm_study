#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N;
char alpha[256];

int getMax(vector<string> &w, vector<char> &w_d, vector<int> num){

    for(int i=0; i<w_d.size(); i++){
        alpha[w_d[i]] = num[i];
    }
    int sum = 0;
    for(auto word : w){
        int now = 0;
        for(char v : word){
            now = now * 10 + alpha[v];
        }
        sum += now;
    }

    return sum;

}

int main(){
    scanf("%d", &N);

    string str;
    vector<string> word;
    vector<char> word_detail;
    for(int i=0; i<N; i++){
        cin >> str;
        word.push_back(str);
        for(auto v : str){
            word_detail.push_back(v);
        }
    }
    sort(word_detail.begin(), word_detail.end());
    word_detail.erase(unique(word_detail.begin(), word_detail.end()), word_detail.end());

    vector<int> number;
    int n_size = word_detail.size();
    for(int i=9; i>9-n_size; i--){
        number.push_back(i);
    }

    int max_num = -987654321;
    do{
        max_num = max(max_num, getMax(word, word_detail, number));
    }while(prev_permutation(number.begin(), number.end()));

    printf("%d", max_num);
    return 0;
}