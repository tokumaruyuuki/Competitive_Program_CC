#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
typedef long long ll;
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
const int MOD = (int)1e9 + 7;
//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    //sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    string weather;cin >> weather;
    int ans = 0;
    if(weather[1]=='R'){
        if(weather[0]=='R' && weather[2]=='R')ans=3;
        else if(weather[0]=='R' || weather[2]=='R')ans=2;
        else ans = 1;
    } else {
        if(weather[0]=='R' || weather[2]=='R')ans=1;
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/abc175/tasks/abc175_a