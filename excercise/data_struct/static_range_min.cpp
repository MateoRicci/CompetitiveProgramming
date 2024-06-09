#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (ll pw = 1, k = 1; pw * 2 <= SZ(V); pw *= 2, ++k) {
			jmp.emplace_back(SZ(V) - pw * 2 + 1);
			fore(j,0,SZ(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(ll a, ll b) {
		assert(a <= b); // or return inf if a == b
		ll dep = 63 - __builtin_clzll(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

int main(){
    FIN;

    ll n,q;
    cin >> n >> q;

    vector<ll> v(n);

    fore(i,0,n){
        cin >> v[i];
    }
    RMQ<ll> sprace(v);

    fore(i,0,q){
        ll a,b;
        cin >> a >> b;
        a--;
        ll res = sprace.query(a,b);
        cout << res << "\n";
    }
}