#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) fori+1(auto& i:a) cin>>i
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
template <typename T> using ordered_set                = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T1, typename T2> using ordered_map  = tree <T1, T2, less <T1>, rb_tree_tag, tree_order_statistics_node_update>;
 
class Policy {
private:
    ordered_set<ii> pbds;
public:
    Policy() {
        pbds.clear();
    }
    void add(ii value) {
        pbds.insert(value);
    }
    void remov(ii value) {
        auto fnd = pbds.find(value);
        if (fnd != pbds.end()) {
            pbds.erase(fnd);
        }
    }
    ii kth(int k) {
        return *pbds.find_by_order(k);
    }
    int countLess(ii value) {
        return pbds.order_of_key(value);
    }
    int countEqual(ii value) {
        return countLess({value.fst, value.snd + 1}) - countLess(value);
    }
    int countLessOrEqual(ii value) {
        return countLess({value.fst, value.snd + 1});
    }
    int countGreater(ii value) {
        return pbds.size() - countLess({value.fst, value.snd + 1});
    }
};

int main(){
    FIN;
    ll n,T; cin >> n >> T;
    vector<ll> a(n);
    fore(i,0,n) cin >> a[i], a[i]-=i;
    // lo que menos voy a esperar va a ser si o si t-n
    set<ii> s;
    Policy pbds = Policy();
    ll res = 0;

    fore(i,0,n){
        pbds.add(ii{a[i],i});
        ll espera = T - 1 - i;
        if(espera<=0) break; // si me quedo sin tiempo
        res = max(res, ll(pbds.countLess(ii{espera + 1, -1})));
    }
    show(res);
}
