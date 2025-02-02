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


int main(){
    FIN;
    ll n,k; cin >> k >> n;
    ll minp = n/3; ll maxp = n/2 + n%2;
    if(n%3) minp++;
    if(k < minp || k > maxp) show("*");
    else{
        ll dif = n-k;
        string res;
        ll carry = 0;
        if(dif > k){
            res.pb('-');
            dif--;
            carry = 1;
        } else{
            res.pb('X');
            k--;
        }
        fore(i,1,n){
            // DGB(i);
            // DGB(dif);
            // DGB(k);
            // DGB(carry);
            if(res[i-1]=='X'){
                res.pb('-');
                dif--;
                carry = 1;
            } else if(res[i-1]=='-' && dif >= k && i>1 && carry){
                res.pb('-');
                dif--;
                carry = 0;
            } else{
                res.pb('X');
                k--;
                carry = 0;
            }
        }
        cout << res << "\n";
    }
    return 0;
}