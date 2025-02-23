#include <bits/stdc++.h>
//peremen trebuyut nashi serdca
using namespace std;

template<typename T> void vyvesti_vector(vector<T> a){
    for(int i = 0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
    cout << '\n';
}
template<typename T> void wyvesti_vector(vector<T> a){
    for(int i = 0; i < a.size(); ++i){
        vyvesti_vector(a[i]);
    }
}
vector<vector<int>> case_1d (vector<int> a,vector<int> b){
    if(a.size()!=b.size()) return {{-3}};
    int summa1 = 0, summa2 = 0;
    for(int i = 0; i < a.size(); ++i){
        summa1+=a[i]; summa2+=b[i];
    }
    if(summa1!=summa2) return {{-2}};
    vector<int> indexa(a.size());
    for(int i = 0; i < a.size(); ++i){
        indexa[i] = i;
    }
    sort(indexa.begin(),indexa.end(),[&](int x, int y){return(a[x]<a[y]);});
    vector<int> indexb(a.size());
    for(int i = 0; i < a.size(); ++i){
        indexb[i] = i;
    }
    sort(indexb.begin(),indexb.end(),[&](int x, int y){return(b[x]<b[y]);});

    for(int i = 0; i < a.size(); ++i){
        if(a[indexa[i]]!=b[indexb[i]]) {
            return {{-1}};
        }
    }

    int koren_proizvodnoi = 0;
    vector<vector<int>> otvet(a.size());
    otvet[indexa[0]].push_back(indexb[0]);
    for(int i = 1; i < a.size(); ++i){
        if(a[indexa[i]] > a[indexa[koren_proizvodnoi]]){
            koren_proizvodnoi = i;
            otvet[indexa[i]].push_back(indexb[i]);
        }
        else {
            for(auto tmp : otvet[indexa[koren_proizvodnoi]]) otvet[indexa[i]].push_back(tmp);
            otvet[indexa[i]].push_back(indexb[i]);
            for(int j = koren_proizvodnoi; j < i; ++j){
                otvet[indexa[j]].push_back(indexb[i]);
            }
        }
    }
    return otvet;
}
const int ogranichenie_na_stepen = 4;
vector<vector<int>> genocid_nulej (vector<vector<int>> a){
    vector<vector<int>> otvet(a.size());
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a[0].size(); ++j){
            if(a[i][j]!=0){ otvet[i].push_back(a[i][j]); }
        }
    }
    for(int i = 0; i < a.size(); ++i){
        for(int j = otvet[i].size(); j < ogranichenie_na_stepen; ++j){
            otvet[i].push_back(0);
        }
    }
    return otvet;
}
vector<int> peresechenie (vector<int> a, vector<int> b){
    vector<int> otvet;
    set<int> elementib;
    for(int i = 0; i < b.size();++i){
        elementib.insert(b[i]);
    }
    for(int i = 0; i < a.size();++i){
        if(elementib.find(a[i]) != elementib.end()) otvet.push_back(a[i]);
    }
    return otvet;
}
vector<vector<int>> otseivanie_teoremoj_vieta (vector<vector<int>> u, vector<vector<int>> v){
    vector<vector<int>> otvet (u.size(), vector<int>(1,0));
    vector<vector<int>> a = genocid_nulej(u);
    vector<vector<int>> b = genocid_nulej(v);
    if(a.size()!=b.size()) return {{-6}};
    vector<int> suma(a.size(),0);
    vector<int> sumb(b.size(),0);
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a[0].size();++j){
            suma[i] += a[i][j];
        }
    }
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a[0].size();++j){
            sumb[i] += b[i][j];
        }
    }
    vector<vector<int>> sravnenie_summ = case_1d(suma,sumb);
    if(sravnenie_summ[0][0] < 0) return {{-5}};
    for(int i = 0; i < otvet.size(); ++i){
        otvet[i] = sravnenie_summ[i];
    }
    vector<int> sigma2a(a.size(),0);
    vector<int> sigma2b(b.size(),0);
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a[0].size(); ++j){
            for(int k = j+1; k < a[0].size(); ++k){
                sigma2a[i]+=a[i][j]*a[i][k];
            }
        }
    }
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a[0].size(); ++j){
            for(int k = j+1; k < a[0].size(); ++k){
                sigma2b[i]+=b[i][j]*b[i][k];
            }
        }
    }
    vector<vector<int>> sravnenie_sigm2 = case_1d (sigma2a,sigma2b);
    if(sravnenie_sigm2[0][0] < 0) return {{-4}};
    for(int i = 0; i < otvet.size(); ++i){
        otvet[i] = peresechenie(otvet[i],sravnenie_sigm2[i]);
    }
    vector<int> sigma3a(a.size(),0);
    vector<int> sigma3b(b.size(),0);
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a[0].size(); ++j){
            for(int k = j+1; k < a[0].size(); ++k){
                    for(int l = k+1; l < a[0].size(); ++l){
                sigma3a[i]+=a[i][j]*a[i][k]*a[i][l];
            }}
        }
    }
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a[0].size(); ++j){
            for(int k = j+1; k < a[0].size(); ++k){
                    for(int l = k+1; l < a[0].size(); ++l){
                sigma3b[i]+=b[i][j]*b[i][k]*b[i][l];
            }}
        }
    }
    vector<vector<int>> sravnenie_sigm3 = case_1d (sigma3a,sigma3b);
    if(sravnenie_sigm3[0][0] < 0) return {{-3}};
    for(int i = 0; i < otvet.size(); ++i){
        otvet[i] = peresechenie(otvet[i],sravnenie_sigm3[i]);
    }
    vector<int> sigma4a(a.size(),0);
    vector<int> sigma4b(b.size(),0);
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a[0].size(); ++j){
            for(int k = j+1; k < a[0].size(); ++k){
                    for(int l = k+1; l < a[0].size(); ++l){
                            for(int q = l+1; q < a[0].size(); ++q){
                sigma4a[i]+=a[i][j]*a[i][k]*a[i][l]*a[i][q];
            }}}
        }
    }
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a[0].size(); ++j){
            for(int k = j+1; k < a[0].size(); ++k){
                    for(int l = k+1; l < a[0].size(); ++l){
                            for(int q = l+1; q < a[0].size(); ++q){
                sigma4b[i]+=b[i][j]*b[i][k]*b[i][l]*b[i][q];
            }}}
        }
    }
    vector<vector<int>> sravnenie_sigm4 = case_1d (sigma4a,sigma4b);
    if(sravnenie_sigm4[0][0] < 0) return {{-2}};
    for(int i = 0; i < otvet.size(); ++i){
        otvet[i] = peresechenie(otvet[i],sravnenie_sigm4[i]);
    }
    return otvet;
}
//rebra v formate vectora iz 3 chisel: ver1, ver2, ves
vector<vector<int>> rebra_v_tablicu (int kol_vo_ver, vector<vector<int>> rebra){
    vector<vector<int>> otvet (kol_vo_ver, vector<int> (kol_vo_ver,0));
    for(int i = 0; i < rebra.size(); ++i){
        otvet[rebra[i][0]][rebra[i][1]]+=rebra[i][2];
        otvet[rebra[i][1]][rebra[i][0]]+=rebra[i][2];
    }
    return otvet;
}
bool ravny (vector<vector<int>> a, vector<vector<int>> b){
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a[0].size(); ++j){
            if(a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}
bool podstavit (vector<int> parosochetanie, vector<vector<int>> a, vector<vector<int>> b){
    //parosochetanie[i] = j <=> i ver iz a sopostavlena j ver iz b
    vector<vector<int>> c (b.size());
    for(int i = 0; i < b.size(); ++i){
        c[i] = b[parosochetanie[i]];
    }
    return ravny(a,c);
}
const int ogranichenie_na_kolvo_vershin = 50;
vector<int> match(ogranichenie_na_kolvo_vershin,-1);
vector<bool>used(ogranichenie_na_kolvo_vershin);
bool dfs(vector<vector<int>>& g, int v){
    if(used[v]){return false;}
    used[v] = true;
    for(int u:g[v]){
        if(match[u]==-1 || dfs(g,match[u])){
            match[u] = v;
            return true;
        }
    }
    return false;
}
vector<int> max_parosochetanie (vector<vector<int>> g, int n){
    for(int v = 0;  v < n; ++v){
        fill(used.begin(),used.end(),false);
        bool t = dfs(g,v);
    }
    vector<int> ans;
    for(int i = 0; i < n; ++i){
        if(match[i]==-1) return {-1};
        ans.push_back(match[i]);
    }
    return ans;
}
vector<vector<int>> vse_parosoch;
void all_parosoch (vector<vector<int>>& rebra, vector<int>& ans, vector<int>& usedb, int k){
    int n = usedb.size();
    if(k==n) {vse_parosoch.push_back(ans); return;}
    int i = k;
            for(int j: rebra[i]){
                if(usedb[j] == 0){
                    usedb[j] = 1;
                    ans[i] = j;
                    k++;
                    all_parosoch(rebra,ans,usedb,k);
                    k--;

                    usedb[j] = 0;
                    ans[i] = -1;
                }
            }
            return;

}
signed main()
{
    int n,m;
    cin >> n >> m;
    int k1, k2;
    cin >> k1 >> k2;
    vector<vector<int>> rebraa(k1, vector<int>(3));
    for(int i = 0; i < k1; ++i){
        cin >> rebraa[i][0] >> rebraa[i][1] >> rebraa[i][2];
        rebraa[i][0]--;
        rebraa[i][1]--;
    }
    cout << endl;
    vector<vector<int>> rebrab(k2, vector<int>(3));
    for(int i = 0; i < k2; ++i){
        cin >> rebrab[i][0] >> rebrab[i][1] >> rebrab[i][2];
        rebrab[i][0]--;
        rebrab[i][1]--;
    }
    cout << endl;
    vector<vector<int>> a = rebra_v_tablicu(n,rebraa);
    vector<vector<int>> b = rebra_v_tablicu(m,rebrab);
    vector<vector<int>> c = otseivanie_teoremoj_vieta(a,b);
    switch(c[0][0]){
    case -6:
        cout << "Code -6: sizes are not equal";
        return 0;
    case -5:
        cout << "Code -5: sums are not equal";
        return 0;
    case -4:
        cout << "Code -4: sigma2s are not equal";
        return 0;
    case -3:
        cout << "Code -3: sigma3s are not equal";
        return 0;
    case -2:
        cout << "Code -2: multiples are not equal";
        return 0;
    default:
        vector<int> tmp = max_parosochetanie(c,n);
        if(tmp[0] == -1){
            cout << "Code -7: max_parosochetanie does not include all ver";
            return 0;
        }
        if(podstavit(tmp,a,b)){
            vyvesti_vector(tmp);
            return 0;
        }
        vector<int> ans(n,-1);
        vector<int> usedb (n,0);
        all_parosoch(c,ans,usedb,0);
        for(int i = 0; i < vse_parosoch.size(); ++i){
            if(podstavit(vse_parosoch[i],a,b)){
                vyvesti_vector(vse_parosoch[i]);
                return 0;
            }
        }
        cout << "Code -1: these two vectors are not equal without any obvious reason";
        return 0;
    }
    return 0;
}
