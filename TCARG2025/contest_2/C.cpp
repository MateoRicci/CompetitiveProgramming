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
typedef pair<ll,ll> ii;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree
<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
indexed_set;

int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        string s; cin >> s;
        ll n = SZ(s);
        map<char,ll> m;
        for(auto c : s)m[c]++;
        ll max_inv = 0;
        string res = s;;
        vector<char> per = {'A','N','O','T'};
        do{
            // creo la string
            string s2;
            for (auto c : per){
                fore(i,0,m[c]) s2.pb(c);
            }

            // Mapeo de posiciones originales
            map<char, vector<ll>> pos;
            fore(i,0,n) pos[s[i]].pb(i);
            vector<ll> idxs;
            map<char, ll> used;
            for(auto c : s2){
                idxs.pb(pos[c][used[c]++]);
            }

            // Contar inversiones con indexed_set
            // Gracias mateo
            indexed_set st;
            ll inv = 0;
            for(auto x : idxs){
                inv += st.size() - st.order_of_key(x+1);
                st.insert(x);
            }
            
            if(inv > max_inv){
                max_inv = inv;
                res = s2;
            }
        } while(next_permutation(ALL(per)));
        show(res);
    }
}
