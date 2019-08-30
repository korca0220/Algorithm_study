#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> q){

    for(int i=0; i<6; i++){
        int temp = 0;  
        for(int j=0; j<4; j++){
            if(q[i*4+1] != q[i*4+j+1]) return false;
        }
    }
    return true;

}

vector<int> ur(vector<int> q){
    int temp = q[2];
    q[2] = q[20];
    q[20] = q[11];
    q[11] = q[13];
    q[13] = temp;
    temp = q[1];
    q[1] = q[18];
    q[18] = q[12];
    q[12] = q[15];
    q[15] = temp;
    return q;
}
vector<int> ul(vector<int> q){
    q = ur(q);
    q = ur(q);
    q = ur(q);
    return q;
}
vector<int> dr(vector<int> q){
    int temp = q[4];
    q[4] = q[19];
    q[19] = q[9];
    q[9] = q[14];
    q[14] = temp;
    temp = q[3];
    q[3] = q[17];
    q[17] = q[10];
    q[10] = q[16];
    q[16] = temp;
    return q;
}
vector<int> dl(vector<int> q){
    q = dr(q);
    q = dr(q);
    q = dr(q);
    return q;
}
vector<int> rr(vector<int> q){
    int temp = q[2];
    q[2] = q[6];
    q[6] = q[10];
    q[10] = q[23];
    q[23] = temp;
    temp = q[4];
    q[4] = q[8];
    q[8] = q[12];
    q[12] = q[21];
    q[21] = temp;
    return q;
}
vector<int> rl(vector<int> q){
    q = rr(q);
    q = rr(q);
    q = rr(q);
    return q;
}
vector<int> lr(vector<int> q){
    int temp = q[1];
    q[1] = q[24];
    q[24] = q[9];
    q[9] = q[5];
    q[5] = temp;
    temp = q[3];
    q[3] = q[22];
    q[22] = q[11];
    q[11] = q[7];
    q[7] = temp;
    return q;
}
vector<int> ll(vector<int> q){
    q = lr(q);
    q = lr(q);
    q = lr(q);
    return q;
}

vector<int> fr(vector<int> q){
    int temp = q[23];
    q[23] = q[19];
    q[19] = q[7];
    q[7] = q[15];
    q[15] = temp;
    temp = q[24];
    q[24] = q[19];
    q[19] = q[7];
    q[7] = q[15];
    q[15] = temp;
    return q;
}
vector<int> fl(vector<int> q){
    q = fr(q);
    q = fr(q);
    q = fr(q);
    return q;
}
vector<int> br(vector<int> q){
    int temp = q[22];
    q[22] = q[18];
    q[18] = q[6];
    q[6] = q[13];
    q[13] = temp;
    temp = q[21];
    q[21] = q[17];
    q[17] = q[5];
    q[5] = q[14];
    q[14] = temp;
    return q;
}
vector<int> bl(vector<int> q){
    q = br(q);
    q = br(q);
    q = br(q);
    return q;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> q(25);
    for(int i=1; i<=24; i++){
        cin >> q[i];
    }
    if(check(ur(q)) || check(ul(q)) || check(dr(q)) || check(dl(q))){
        cout << "1";
        return 0;
    }
    if(check(rr(q)) || check(rl(q)) || check(lr(q)) || check(ll(q))){
        cout << "1";
        return 0;
    }
    if(check(fr(q)) || check(fl(q)) || check(br(q)) || check(bl(q))){
        cout << "1";
        return 0;
    }
    cout << "0";

    return 0;
}