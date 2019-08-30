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

vector<int> lu(vector<int> a) {
    int temp = a[1];
    a[1] = a[5];
    a[5] = a[9];
    a[9] = a[24];
    a[24] = temp;
    temp = a[3];
    a[3] = a[7];
    a[7] = a[11];
    a[11] = a[22];
    a[22] = temp;
    return a;
}
vector<int> ld(vector<int> a) {
    a = lu(a);
    a = lu(a);
    a = lu(a);
    return a;
}
vector<int> ru(vector<int> a) {
    int temp = a[2];
    a[2] = a[6];
    a[6] = a[10];
    a[10] = a[23];
    a[23] = temp; 
    temp = a[4];
    a[4] = a[8];
    a[8] = a[12];
    a[12] = a[21];
    a[21] = temp;
    return a;
}
vector<int> rd(vector<int> a) {
    a = ru(a);
    a = ru(a);
    a = ru(a);
    return a;
}
vector<int> ul(vector<int> a) {
    int temp = a[13];
    a[13] = a[5];
    a[5] = a[17];
    a[17] = a[21];
    a[21] = temp;
    temp = a[14];
    a[14] = a[6];
    a[6] = a[18];
    a[18] = a[22];
    a[22] = temp;
    return a;
}
vector<int> ur(vector<int> a) {
    a = ul(a);
    a = ul(a);
    a = ul(a);
    return a;
}
vector<int> dl(vector<int> a) {
    int temp = a[15];
    a[15] = a[7];
    a[7] = a[19];
    a[19] = a[23];
    a[23] = temp;
    temp = a[16];
    a[16] = a[8];
    a[8] = a[20];
    a[20] = a[24];
    a[24] = temp;
    return a;
}
vector<int> dr(vector<int> a) {
    a = dl(a);
    a = dl(a);
    a = dl(a);
    return a;
}
vector<int> fl(vector<int> a) {
    int temp = a[3];
    a[3] = a[17];
    a[17] = a[10];
    a[10] = a[16];
    a[16] = temp;
    temp = a[4];
    a[4] = a[19];
    a[19] = a[9];
    a[9] = a[14];
    a[14] = temp;
    return a;
}
vector<int> fr(vector<int> a) {
    a = fl(a);
    a = fl(a);
    a = fl(a);
    return a;
}
vector<int> bl(vector<int> a) {
    int temp = a[1];
    a[1] = a[18];
    a[18] = a[12];
    a[12] = a[15];
    a[15] = temp;
    temp = a[2];
    a[2] = a[20];
    a[20] = a[11];
    a[11] = a[13];
    a[13] = temp;
    return a;
}
vector<int> br(vector<int> a) {
    a = bl(a);
    a = bl(a);
    a = bl(a);
    return a;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> q(25);
    for(int i=1; i<=24; i++){
        cin >> q[i];
    }
    if(check(lu(q)) || check(ld(q)) || check(ru(q)) || check(rd(q))){
        cout << "1";
        return 0;
    }
    if(check(ul(q)) || check(ur(q)) || check(dl(q)) || check(dr(q))){
        cout << "1";
        return 0;
    }
    if(check(fl(q)) || check(fr(q)) || check(bl(q)) || check(br(q))){
        cout << "1";
        return 0;
    }
    cout << "0";

    return 0;
}