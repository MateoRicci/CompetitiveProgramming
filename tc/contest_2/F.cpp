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
#define bint __int128
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct Hash {
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	vector<bint> h,pi;
	Hash(string& s){
		assert((P*PI)%MOD==1);
		h.resize(s.size()+1);pi.resize(s.size()+1);
		h[0]=0;pi[0]=1;
		bint p=1;
		fore(i,1,s.size()+1){
			h[i]=(h[i-1]+p*s[i-1])%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
		}
	}
	ll get(int s, int e){
		return (((h[e]-h[s]+MOD)%MOD)*pi[s])%MOD;
	}
};

int main(){
    FIN;
    ll t = 1;
    // cin >> t;
    while(t--){
        string s,t;
        cin >> s;
        cin >> t;
        ll cont_0 = 0;
        ll cont_1 = 0;
        ll fst0 = 1000000000;
        ll fst1 = 1000000000;
        fore(i,0,SZ(s)){
            if(s[i]=='0') {cont_0++;fst0=min(i,fst0);}
            if(s[i]=='1') {cont_1++;fst1=min(i,fst1);}
        }
        Hash h(t);
        ll res = 0;
        fore(dist,1,SZ(t)){
            // dist es el largo de r0
            ll largo_total_r0 = cont_0*dist;
            if(((SZ(t)-largo_total_r0)%cont_1)!=0) continue;
            ll largo_total_r1 = (SZ(t)-largo_total_r0);
            ll dist1 = largo_total_r1/cont_1;
            if(largo_total_r0+largo_total_r1 > SZ(t)) continue; // por si a caso
            if(dist1 <= 0) break;
            // show("BUSCA IGUALES");
            // DGB(dist);
            // DGB(dist1);
            // DGB(fst1);
            // si llego aca es pq al menos en largo entra
            ll val0,val1;
            if(fst0 < fst1){
                val0 = h.get(fst0,fst0+dist);
                val1 = h.get((fst1*dist),(fst1*dist)+dist1);
            } else{
                val1 = h.get(fst1,fst1+dist1);
                val0 = h.get((fst0*dist1),(fst0*dist1)+dist);
            }
            if(val0==val1) continue;
            ll pos = 0;
            bool valido = true;
            fore(i,0,SZ(s)){
                if(s[i]=='0'){
                    // DGB(val0);
                    // DGB(h.get(pos,pos+dist));
                    if(val0 != h.get(pos,pos+dist)){
                        valido = false;
                        break;
                    }
                    pos += dist;
                } else{
                    // DGB(val1);
                    // DGB(h.get(pos,pos+dist1));
                    // DGB(pos);
                    // DGB(pos+dist1);
                    if(val1 != h.get(pos,pos+dist1)){
                        valido = false;
                        break;
                    }
                    pos += dist1;
                }
            }
            if(valido) res++;
        }
        show(res);
    }
}