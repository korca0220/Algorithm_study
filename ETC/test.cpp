#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'numofPrizes' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY marks
 */

int numofPrizes(int k, vector<int> marks) {
    vector<int> rank;
    int answer =0 ;
    for(int i=0; i<marks.size(); i++){
        int count = 1;
        for(int j=0; j<marks.size(); j++){
            if(i==j)continue;
            if(marks[i] < marks[j])count+=1; 
        }
        rank.push_back(count);
    }
    for(int i=0; i<rank.size(); i++){
        if(rank[i] >= k )answer+=1;
    }
    return answer;
}

int main(){
    vector<int> p;
    
    numofPrizes(4, )
}