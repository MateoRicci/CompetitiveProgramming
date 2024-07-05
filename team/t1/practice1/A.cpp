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

bool compare_first(const pair<ll,pair<ll,bool>>& a, const pair<ll,pair<ll,bool>>& b) {
  return a.first < b.first;
}

int main(){
    FIN;
    ifstream cin("access.in");
    ofstream cout("access.out");
    ll n,m;
    cin >> n;
    vector<bool> stat(n);
    // [f,t] open, close
    vector<ll> from(n), to(n);
    fore(i,0,n){
        string a,b,c;
        cin >> a >> b >> c;

        if(a=="allow") stat[i] = 1;
        else stat[i]=0;

        bool mask = false;
        ll mask_pos = 0;
        string aux_ip = "";
        ll ip = 0;
        ll ipc = 0;
        // string to ll -> ll(stoi(aux_ip))
        
        // ip maker
        fore(j,0,SZ(c)){ // max sz of c is 14
            if(c[j]=='.'){
                ll x = ll(stoi(aux_ip));
                if(ipc == 0) ip += x * (1LL << 24);
                else if(ipc == 1) ip += x * (1LL << 16);
                else if(ipc == 2) ip += x * (1LL << 8);
                aux_ip = "";
                ipc++;
            } else if(c[j] != '/'){
                aux_ip += c[j];
            }

            if(c[j] == '/'){
                ll x = ll(stoi(aux_ip));
                ip += x;
                mask = true;
                mask_pos = j;
            }
        }

        if(!mask){
            ll x = ll(stoi(aux_ip));
            ip += x;
        }

        
        // making mask
        ll mask_n = 0;
        if(mask){
            string m_aux = "";
            fore(j,mask_pos+1,SZ(c)){
                m_aux += c[j];
            }
            mask_n = ll(stoi(m_aux));
            mask_n = 32 - mask_n;

            ll ipt = ip - 1 + (1LL << mask_n); 

            from[i] = ip;
            to[i] = ipt;;
        } else{
            from[i] = ip;
            to[i] = ip;
        }



    }

    set<pair<ll,pair<ll,bool>>> ranges; // <IP , <ID , ESTADO>>
    ranges.insert({-1,{-1,1}});
    ranges.insert({LONG_LONG_MAX,{-1,1}});

    // ranges.insert({3232235522, {100, 1}});

    fore(hi,0,n){
        ll i = n-1-hi;
        pair<ll,pair<ll,bool>> li,lr,sup,inf, aux;
        li = {from[i], {i, stat[i]}};
        lr = {to[i], {i, stat[i]}};

        auto it = lower_bound(ranges.begin(), ranges.end(), li, compare_first); // mayor o igual que li
        auto itt = lower_bound(ranges.begin(), ranges.end(), lr, compare_first); // mayor o igual que ld

        inf = *it; 
        sup = *itt;

        it--; // menor estricto del li
        itt--; // menor estricto del ld

        if(inf.snd.fst == it->snd.fst && it->snd.fst != -1){ // chequeo id del rango li
            ranges.insert({li.fst-1,it->snd});
        }
        if(sup.snd.fst == itt->snd.fst && itt->snd.fst != -1){ // chequeo id del rango ld
            ranges.insert({lr.fst+1,itt->snd});
        }


        // TLE 24
        it = lower_bound(ranges.begin(), ranges.end(), li, compare_first); // mayor o igual que li
        itt = upper_bound(ranges.begin(), ranges.end(), lr, compare_first); // mayor o igual que ld
        ranges.erase(it,itt); // borro todo lo que hay en el medio


        // WA 12
        // while(it->first < li.fst){
        //     it++;
        // }   

        // while(it->first <= lr.fst && it->snd.fst != -1){
        //     ranges.erase(it);
        //     it++;
        // }

        ranges.insert(li);
        ranges.insert(lr);

    }


    // for(const auto& p : ranges) {
    //     cout << "(" << p.first << ", (" << p.second.first << ", " << p.snd.snd << ") )\n";
    // }   

    cin >> m;
    fore(i,0,m){
        string q; cin >> q;

        string aux_ip = "";
        ll ipc = 0, ip = 0;

        fore(j,0,SZ(q)){
            if(q[j]=='.'){
                ll x = ll(stoi(aux_ip));
                if(ipc == 0) ip += x * (1LL << 24);
                else if(ipc == 1) ip += x * (1LL << 16);
                else if(ipc == 2) ip += x * (1LL << 8);
                aux_ip = "";
                ipc++;
            } else{
                aux_ip += q[j];
            }
        }

        ll x = ll(stoi(aux_ip));
        ip += x;    
        pair<ll,pair<ll,bool>> ip_search = {ip,{m,m}}; // VER ESTO
        auto it = lower_bound(ranges.begin(), ranges.end(), ip_search, compare_first);
        ll value = it->first;
        pair<ll,bool> st = it->second;

        if(value == ip){ // esa ip existe en mis rangos
            if(st.snd) cout << "A";
            else cout << "D";
        } else{ // hago chequeo de rangos
            pair<ll,pair<ll,bool>> sup,inf;
            sup = *it;
            it--;
            inf = *it;
            if(inf.snd.fst == sup.snd.fst){ // si los id son los mismos
                if(inf.snd.snd) cout << "A";
                else cout << "D";
            } else{ // si los id son distintos el rango no esta definido => acces allowed
                cout << "A";
            }
        }

    }
    cout << "\n";

    // CHEQUEO DE RANGOS
    // SI EL VALUE == QUERY --> STATUS DEL VALUE
    // SI LA IZQUIERDA TIENE EL MISMO ID QUE EL DE LA DERECHA --> STATUS DEL VALUE
    // SI SON DISTINTOS ID => RANGO NO DECLARADO --> 1

    cin.close();
    cout.close();
}

// GRACIAS DURAN.