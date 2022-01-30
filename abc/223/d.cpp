#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include<atcoder/all>
using namespace atcoder;

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
using P = vector<ll, ll>;
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

using mint = modint998244353;

int N,M; //頂点と辺の数
vector<vector<int>> G; //グラフ
vector<int> h; //入次数
vector<int> ans; //答えを格納

void topoBFS(){
  //queue<int> unchecked;
  priority_queue<int, vector<int>, greater<int>> unchecked;
  for(int i=0; i<N; i++){
    if(h[i]==0){
      unchecked.push(i); //入次数が0の頂点をキューに入れる
    }
  }
  while(!unchecked.empty()){
    //int current = unchecked.front();
    int current = unchecked.top();
    unchecked.pop();
    ans.push_back(current); //キューから取り出したらすぐソート後のリストに加える

    for(int next: G[current]){ //「行ける」頂点について
      h[next]--; //入次数を減らす
      if(h[next]==0){ //入次数0になったらキューに追加
        unchecked.push(next);
      }
    }
  }
}

int main(){
  fio();
  cin>>N>>M;
  G.resize(N);
  h.resize(N, 0); //入次数0初期化
  int f,t;
  for(int i=0; i<M; i++){
    cin>>f>>t;
    f--; t--; //1始まりで辺の情報を入れるならデクリメントする
    G[f].push_back(t); //fからtに行ける
    h[t]++; //tの入次数を増やす
  }

  topoBFS();

  bool isDAG = ans.size()==N; //DAGであるかどうか
  if(isDAG){
    for(int x: ans){
      cout<<x+1 << " "; //1始まりで出力するときはx+1とする
    }
    cout << endl;
  }else{
    cout<< -1 <<endl;
  }
}