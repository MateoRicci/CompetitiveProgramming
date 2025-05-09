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
        ll n; cin >> n;
        vector<string> w(n);
        ll res = 0;
        fore(i,0,n)cin >> w[i];
        fore(i,0,n-1){
            fore(j,i+1,n){
                if(w[j] == "-") continue;
                ll naux = w[i].length();
                ll naux2 = w[j].length();
                if(naux != naux2) continue;
                fore(kk,0,naux){
                    ll k = kk;
                    bool flag = true;
                    fore(l,0,naux){
                        if(w[i][l] != w[j][k]){
                            flag = false;
                            break;
                        }
                        k++; k = k%naux;
                    }
                    if(flag){
                        w[j] = "-";
                        break;
                    }
                }

            }
        }
        fore(i,0,n){
            if(w[i]!="-") res++;
        }
        cout << res << "\n";
    }