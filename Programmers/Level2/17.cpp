#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

struct comp{
    bool operator()(const int p, const int pp){
        return p > pp;
    }
};


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int,int>>> list;
    map<string ,int> num_list;

    for(int i=0; i<genres.size(); i++){
        num_list[genres[i]] +=plays[i]; 
        list[genres[i]].push_back(make_pair(plays[i],i));
    }
    for(auto p : list){
        sort(list[p.first].begin(), list[p.first].end(), [](const pair<int,int> p, const pair<int,int> pp) -> bool{
            if(p.first == pp.first) return p.second < pp.second;
            return p.first > pp.first;
        });
    }
    vector<pair<string,int>> v_num_list;
    for(auto p : num_list){
        v_num_list.push_back(make_pair(p.first, p.second));
    }
    sort(v_num_list.begin(), v_num_list.end(), [](const pair<string,int> p, const pair<string,int> pp) -> bool{
        return p.second > pp.second;
    });

    for(auto p : v_num_list){
        for(int i=0; i<list[p.first].size(); i++){
            if(i<2)answer.push_back(list[p.first][i].second);
        }
    }

    return answer;
}