#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
    FIN;

    ll n,m;
    cin >> n >> m;
    ll m_aux = m;
    ll n_aux = n;

    multiset<int> h;
    vector<int> t;
    while(n_aux--){
        int price;
        cin >> price;
        h.insert(price);
    }
    
    while(m_aux--){
        int customer;
        cin >> customer;
        t.push_back(customer);
    }
 
    fore(i,0,m){
        auto it = h.lower_bound(t[i]);
        if(t[i] == *it){
            cout << *it << endl;
            h.erase(it);
        } else if(it != h.begin()){
            --it;
            cout << *it << endl;
            h.erase(it);
        } else{
            cout << -1 << endl;
        }
        
    }
}