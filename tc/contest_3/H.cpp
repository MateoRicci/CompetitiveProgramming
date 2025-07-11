#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll MAXN = 26;
vector<ll> g[MAXN];ll n; ll nn = MAXN;
vector<ll> tsort(){  // lexicographically smallest topological sort
	vector<ll> r;priority_queue<ll> q;
	vector<ll> d(2*nn,0);
	fore(i,0,nn)fore(j,0,g[i].size())d[g[i][j]]++;
	fore(i,0,nn)if(!d[i])q.push(-i);
	while(!q.empty()){
		ll x=-q.top();q.pop();r.pb(x);
		fore(i,0,g[x].size()){
			d[g[x][i]]--;
			if(!d[g[x][i]])q.push(-g[x][i]);
		}
	}
	return r;  // if not DAG it will have less than n elements
}

bool dfs(ll v, vector<int> &vis){
    vis[v] = 1;
    bool valid = true;
    for(auto u : g[v]){
        if(!vis[u]){
            valid = valid && dfs(u,vis);
        } else if(vis[u] == 1){
            return false;
        }
    }
    vis[v] = 2;
    return valid;
}

int main(){
    FIN;
    ll t = 1;
    // cin >> t;
    while(t--){
        cin >> n;
        vector<string> s(n); fore(i,0,n) cin >> s[i];
        fore(i,0,n){
            fore(j,0,SZ(s[i])){
                s[i][j] = s[i][j] - 'a';
            }
        }
        set<pll> edges;
        fore(i,0,n-1){
            ll j = 0;
            bool sacame = false;
            while(j < SZ(s[i])){
                if(j>=SZ(s[i+1])){
                    cout << "Impossible\n";
                    return 0;
                }
                if(s[i][j] != s[i+1][j]){
                    if(!edges.count({s[i][j],s[i+1][j]})){
                        g[s[i][j]].pb(s[i+1][j]);
                        edges.insert({s[i][j],s[i+1][j]});
                        // sacame = true;
                        break;
                    } else{
                        // sacame = true;
                        break;
                    }
                }
                j++;
            }
            if(sacame) break;
        }
        // bool valid = true;
        // fore(i,0,MAXN){
        //     vector<int> vis(MAXN,0);
        //     valid = valid && dfs(i,vis);
        // }

        // if(!valid){show("Impossible");return 0;}
        
        // fore(i,0,26) show(SZ(g[i]));
        
        vector<ll> res = tsort();
        vector<char> res2;
        
        if(SZ(res)!=26){
            show("Impossible");return 0;
        }
        // else {show("YES");return 0;}

        for(auto x : res){
            char c = 'a' + x;
            res2.pb(c);
        }

        for(auto c :res2) cout << c;
        show("");
    }
    return 0;
}