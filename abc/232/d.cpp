#include <bits/stdc++.h>
#define fio()         \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
using namespace std;
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define rrep(i, n) for(int i = n; i > 0; --i)
#define repp(i, n, m) for(int i = m; i < int(n); ++i)
#define fore(i_in, a) for(auto &i_in : a)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
const int SIZE = 100005;
const int inf = INT_MAX;
const int modi = 1000000007;
const long long INF = LLONG_MAX;
const long long modl = 1000000007LL;
const long long modll = 998244353LL;

void yes() { cout << "Yes" << endl; }
void no() { cout << "No" << endl; }
void yn(bool t) {
    if(t)
        yes();
    else
        no();
}
void Yes() { cout << "YES" << endl; }
void No() { cout << "NO" << endl; }
void YN(bool t) {
    if(t)
        Yes();
    else
        No();
}

void pri(ll a) { cout << a << endl; }
void spri(string a) { cout << a << endl; }
void priV(vector<ll> &vec) {
    for(size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << ":";
    }
    cout << endl;
}

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

int N,M;
int H,W;
graph G;
vector<string> C;

int h,w;
vector<vector<int>> A;

bool judge(int a, int b){
    if(a >= H || b >= W){
        return false;
    }
    return true;
}


void load_map(){
    A[0][0] = 1;
    queue<int> pp;
    queue<int> qq;
    pp.push(0);
    qq.push(0);

    while(!pp.empty()){
        int st = pp.front(); pp.pop();
        int ct = qq.front(); qq.pop();
        if(judge(st+1, 0)){
            if(C[st+1][ct]=='.'){
                if(A[st+1][ct] < A[st][ct]+1){
                    A[st+1][ct]=A[st][ct]+1;
                    pp.push(st+1);
                    qq.push(ct);
                }
            }

        }
        if(judge(0, ct+1)){
            if(C[st][ct+1]=='.'){
                if(A[st][ct+1] < A[st][ct]+1){
                    A[st][ct+1]=A[st][ct]+1;
                    pp.push(st);
                    qq.push(ct+1);
                }
            }

        }
    }
}

int main(void){
    fio(); cin >> H >> W;
    C.resize(H);
    A.resize(H, vector<int> (W,0));

    rep(i,H){
        string s; cin >> s;
        C[i] = (s);
    }
    load_map();
    int ans = 0;
    rep(i,H){
        rep(j,W){
            if(ans < A[i][j]) ans = A[i][j];
        }
    }
    cout << ans << endl;
}
