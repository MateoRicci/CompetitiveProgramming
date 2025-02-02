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
    ll k; cin >> k;
    string s; cin >> s;
    ll n = SZ(s);
    if(k==2){
        string s1,s2;
        fore(i,0,n){
            char aux1 = '0';
            char aux2 = '1';
            s1.pb(aux1);
            s2.pb(aux2);

            if(i<n-1){
                s2.pb(aux1);
                s1.pb(aux2);
                i++;
            }
        }
        ll res1 = 0;
        ll res2 = 0;

        fore(i,0,n){
            if(s[i]!=s1[i]) res1++;
            if(s[i]!=s2[i]) res2++;
        }
        if(res1<res2){
            cout << res1 << " " << s1 << "\n";
        } else{
            cout << res2 << " " << s2 << "\n";
        }
    } else{
        s.pb('3');
        ll acc = 1;
        ll res = 0;
        fore(i,0,n){
            if(s[i] != s[i-1]) acc = 1;
            else{
                acc++;
                if(acc==k){
                    // si es igual que el siguiente cambio en el que estoy
                    if(s[i] == s[i+1]){
                        if(s[i]=='0') s[i] = '1';
                        else s[i] = '0';
                        res++;
                    } else{
                        // si no me conviene cambiar el anterior
                        if(s[i-1]=='0') s[i-1] = '1';
                        else s[i-1] = '0';
                        res++;
                        acc = 1;
                    }
                }
            }
        }
        s.pop_back();
        cout << res<< " " << s << "\n";
    }
    return 0;
}