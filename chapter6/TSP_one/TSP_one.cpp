#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 100;
const double INF = 987654321;

int n; //도시의 개수
int dist[MAX][MAX]; //두 도시간의 거리

//path : 지금까지 만든 경로
//visited : 각 도시 방문 여부
//current_length : 지금까지 만든 경로 길이
vector<int> path;
vector<bool> visited;
double current_length;

double shortestPath(vector<int>& path, vector<bool>& visited, double current_length){

    // 기저조건 : 경로의 길이가 도시와 같은경우(모두 방문한 경우)
    if(path.size() == n){
        // 현재 경로 + path에서부터 ~path 끝까지의 거리
        return current_length + dist[path[0]][path.back()];
    }
    double ret = INF;

    //다음 방문할 도시를 모두 시도
    for(int next=0; next<n; next++){
        if(visited[next]) continue; //이미 방문한경우
        int here = path.back();
        path.push_back(next);
        visited[next] = true;

        // 나머지 경로들을 shortestPath로 얻어온 뒤 최소값을 비교
        double cand = shortestPath(path, visited, current_length+dist[here][next]);
        ret = min(ret, cand);
        visited[next] = false;
        path.pop_back();
    }
    return ret;
}

int main(){



    return 0;
}