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
#define oper(a,b) (a+b)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
    FIN;
    ll t = 1;
    // cin >> t;
    while(t--){
        int n;cin >> n;
        vector<pair<int,int>> nums(n);
        fore(i,0,n) cin >> nums[i].fst >> nums[i].snd;
        sort(ALL(nums));
        vector<int> a(n),b(n);
        fore(i,0,n){
            a[i] = nums[i].fst;
            b[i] = nums[i].snd;
        }
        vector<int> dp(n);
        fore(i,1,n){
            int cantidad_que_destruyo = (lower_bound(ALL(a),a[i]) - lower_bound(ALL(a), a[i] - b[i]));
            dp[i] = cantidad_que_destruyo + dp[max(0LL,i-cantidad_que_destruyo-1)]; // en dp[i] tengo la cantidad que muerten
        }
        ll res = n;
        // showAll(dp);
        fore(i,1,n+1){
            res = min(res, dp[i-1] + n - i);
        }
        show(res);
    }
}