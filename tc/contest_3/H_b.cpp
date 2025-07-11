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

bool check(string a, string b, map<char,int> &order){
    ll sz = min(SZ(a), SZ(b));
    fore(i,0,sz){
        fore(i,0,5){

        }
        if(order[a[i]] < order[b[i]]){
            return true;
        } else if(order[a[i]] > order[b[i]]){
            return false;
        }
    }
    return(SZ(a) < SZ(b));
}

int main(){
    FIN;
    ll m;
    cin >> m;
    vector<string> s(m);
    fore(i,0,m){
        cin >>s[i];
    }
    string order(5, ' ');
    fore(i,0,5) order[i] = 'a' + i;
    bool valid = false;

    do{
        // codigo
        map<char,int> mm;
        fore(i,0,SZ(order)){
            mm[order[i]] = i;
        }
        bool valid_here = true;
        fore(i,0,m-1){
            valid_here = valid_here && check(s[i],s[i+1],mm);
        }
        valid = valid || valid_here;

    } while(next_permutation(ALL(order)));
    if(!valid) show("Impossible\n");
    else show("YES\n");


    return 0;
}