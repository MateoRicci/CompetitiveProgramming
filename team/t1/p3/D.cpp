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

ll pot2(ll n){
    ll i = 0;
    while((1LL<<i) <= n) i++;
    i--;
    return i;
}

int main(){
    FIN;

    ll n,k; cin >> n >> k;

    ll naux = n;
    multiset<ll> nums;
    ll oper = 0;
    while(naux > 0){
        ll p = 1LL << pot2(naux);
        naux-=p;
        nums.insert(p);
        oper++;
    }

    if(k<oper || k > n) cout << "NO\n";
    else if(k==oper){
        cout << "YES\n";
        for (auto elem : nums) {
            cout << elem << " ";
        }
        cout << "\n";
    }
    else{
        ll falt = k-oper;
        while(falt > 0){
            auto it = nums.rbegin();
            ll aux = *it;
            nums.erase(prev(it.base()));
            nums.insert(aux/2);
            nums.insert(aux/2);
            falt--;
        }
        cout << "YES\n";
        for (auto elem : nums) {
            cout << elem << " ";
        }
        cout << "\n";   
    }


}