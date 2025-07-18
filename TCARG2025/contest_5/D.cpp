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

const ll MAXN = 200005;
ll dp[MAXN][2];
ll n;

ll f(ll i,ll flag, vector<ii> &nums, vector<ll> &a){
    if(i>=n) return 0;
    if(dp[i][flag] != -1) return dp[i][flag];
    dp[i][flag] = 0;
    ll val = a[i];
    auto it = upper_bound(ALL(nums), ii{val,i});
    if(it != nums.end()){
        ll nval = it->fst,npos =it->snd;
        if(nval != val){
            dp[i][flag] = f(i+1,0,nums,a);    
        } else{
            if(!flag){
                dp[i][flag] = max((npos-i+1) + f(npos,1,nums,a), f(i+1,0,nums,a));
            } else{
                // DGB(i);
                // DGB(npos);
                dp[i][flag] = max((npos-i) + f(npos,1,nums,a), f(i+1,0,nums,a));
            }
        }
    } else{ 
        dp[i][flag] = f(i+1,0,nums,a);
    }
    return dp[i][flag];
}


int main(){
    FIN;
    ll t = 1;
    cin >> t;
    while(t--){
        cin >> n;
        vector<ii> nums(n); // nums{valor, indice}
        vector<ll> a(n);
        fore(i,0,n) dp[i][0] = -1, dp[i][1] = -1;
        fore(i,0,n) cin >> a[i], nums[i].fst = a[i], nums[i].snd = i;
        sort(ALL(nums));
        ll res = f(0,0,nums,a);
        cout << res << "\n";
        // DGB(res);
    }
}
