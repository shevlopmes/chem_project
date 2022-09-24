#include <bits/stdc++.h>

using namespace std;



template<typename T>
vector <T> operator - (vector <T> a, vector <T> b)
{
    vector <T> c;
    for(int t=0; t<max(a.size(), b.size()); ++t)
    {
        if(t<a.size())
        {
            if(t<b.size())
            {
                c.push_back(a[t]-b[t]);
            }
            else
            {
                c.push_back(a[t]);
            }
        }
        else
        {
            c.push_back(-b[t]);
        }
    }
    return c;
}

template<typename T>
vector <T> operator + (vector <T> a, vector <T> b)
{
    vector <T> c;
    for(int t=0; t<max(a.size(), b.size()); ++t)
    {
        if(t<a.size())
        {
            if(t<b.size())
            {
                c.push_back(a[t]+b[t]);
            }
            else
            {
                c.push_back(a[t]);
            }
        }
        else
        {
            c.push_back(b[t]);
        }
    }
    return c;
}

template<typename T>
vector <T> operator * (T a, vector <T> b)
{
    vector <T> c;
    for(int t=0; t<b.size(); ++t)
    {
        c.push_back(b[t]*a);
    }
    return c;
}

template<typename T>
vector <T> operator * (vector <T> b, T a)
{
    vector <T> c;
    for(int t=0; t<b.size(); ++t)
    {
        c.push_back(b[t]*a);
    }
    return c;
}


int NOD(int a, int b)
{
    int nod;
    for(int i=min(abs(a),abs(b)); i>0;--i)
    {
        if(a%i==0 && b%i==0)
        {
            nod=i;
            break;
        }
    }
    return nod;
}

class RACIONAL
{
private:
    int znamenatel;
    int chislitel;
public:
    int chisl()
    {
        return chislitel;
    }
    int znam()
    {
        return znamenatel;
    }
    RACIONAL(int p, int q)
    {
        if(p!=0)
        {
        int nod=NOD(p,q);
        chislitel=p/nod;
        znamenatel=q/nod;
        if(znamenatel<0)
        {
            chislitel=-chislitel;
            znamenatel=-znamenatel;
        }
        }
        else
        {
            chislitel=0;
            znamenatel=1;
        }
    }
    RACIONAL(pair <int,int> drob)
    {
        int p=drob.first, q=drob.second;
        if(p!=0)
        {
        int nod=NOD(p,q);
        chislitel=p/nod;
        znamenatel=q/nod;
        }
        else
        {
            chislitel=0;
            znamenatel=1;
        }
    }
    pair <int,int> racvpair()
    {
        pair<int, int> drob={chislitel, znamenatel};
        return drob;
    }
    int racvint()
    {
        return chislitel/znamenatel;
    }
    double racvdouble()
    {
        return chislitel/znamenatel;
    }
    RACIONAL(int p)
    {
        chislitel=p;
        znamenatel=1;
    }
};

//typedef RACIONAL rac;


namespace std {

decltype(cout)& operator << (decltype(cout)& where, RACIONAL what) {
    where << what.chisl() << '/' <<what.znam();
    return where;
}

};
bool operator != (RACIONAL a, RACIONAL b)
{
    if(a.chisl()*b.znam()!=b.chisl()*a.znam())
    {
        return true;
    }
    return false;
}

RACIONAL operator + (RACIONAL a, RACIONAL b)
{
    RACIONAL c(a.chisl()*b.znam()+b.chisl()*a.znam(), a.znam()*b.znam());
    return c;
}

RACIONAL operator - (RACIONAL a, RACIONAL b)
{
    RACIONAL c(a.chisl()*b.znam()-b.chisl()*a.znam(), a.znam()*b.znam());
    return c;
}

RACIONAL operator - (RACIONAL a)
{
    RACIONAL c(-a.chisl(), a.znam());
    return c;
}

RACIONAL operator * (RACIONAL a, RACIONAL b)
{
    RACIONAL c(a.chisl()*b.chisl(), a.znam()*b.znam());
    return c;
}

RACIONAL operator * (RACIONAL a, int b)
{
    RACIONAL c(a.chisl()*b, a.znam());
    return c;
}

RACIONAL operator * (int b, RACIONAL a)
{
    RACIONAL c(a.chisl()*b, a.znam());
    return c;
}

vector<RACIONAL> operator * (RACIONAL b, vector<RACIONAL> a)
{
    for(int t=0; t<a.size(); ++t)
    {
        a[t]=a[t]*b;
    }
    return a;
}

vector<RACIONAL> operator * (vector<RACIONAL> a, RACIONAL b)
{
    for(int t=0; t<a.size(); ++t)
    {
        a[t]=a[t]*b;
    }
    return a;
}

RACIONAL operator / (RACIONAL a, RACIONAL b)
{
    RACIONAL c(a.chisl()*b.znam(), a.znam()*b.chisl());
    return c;
}

RACIONAL operator / (RACIONAL a, int b)
{
    RACIONAL c(a.chisl(), a.znam()*b);
    return c;
}

RACIONAL operator / (int b, RACIONAL a)
{
    RACIONAL c(a.chisl(), a.znam()*b);
    return c;
}

template<typename T>
class MATRITCA_CLASS
{
private:
    vector <vector<T>> matritca;
public:
    MATRITCA_CLASS(vector <vector<T>> a)
    {
        matritca=a;
    }
    void dobavlenie_stroki(vector<T> a)
    {
        matritca.push_back(a);
    }
    void dobavlenie_stolbtca(vector<T> a)
    {
        for(int i=0; i<matritca.size(); ++i)
        {
            matritca[i].push_back(a[i]);
        }
    }
    void vyvod()
    {
        for(int i=0; i<matritca.size(); ++i)
        {
            for(int j=0; j<matritca[0].size(); ++j)
            {
                cout << matritca[i][j] << " ";
            }
            cout << '\n';
        }
    }
    vector <vector<T>> telo()
    {
        return matritca;
    }
    void pomenyt_stroki(int m, int n)
    {
        int s=m+n;
        m=min(m,n);
        n=s-m;
        matritca.insert(matritca.begin()+n,matritca[m]);
        matritca.insert(matritca.begin()+m,matritca[n]);
        matritca.erase(matritca.begin()+m+1,matritca.begin()+m+1);
        matritca.erase(matritca.begin()+n+1,matritca.begin()+n+1);
    }
    void privedenie_k_trapetcevidnoi_forme()
    {
        int N_stroki_s_ne_nul_elem;
        for(int j=0; j<matritca[0].size(); ++j)
        {
            N_stroki_s_ne_nul_elem=-1;
            if(j<matritca.size())
            {
            for(int i=j; i<matritca.size(); ++i)
            {
                if(matritca[i][j]!=RACIONAL(0) && N_stroki_s_ne_nul_elem==-1)
                {
                    N_stroki_s_ne_nul_elem=i;
                }
                if(i!=N_stroki_s_ne_nul_elem && N_stroki_s_ne_nul_elem!=-1)
                {
                    matritca[i]=matritca[i]-(matritca[i][j]/matritca[N_stroki_s_ne_nul_elem][j])*matritca[N_stroki_s_ne_nul_elem];
                }
            }
            if(N_stroki_s_ne_nul_elem!=-1)
            {
                int n=N_stroki_s_ne_nul_elem;
                int m=j;
                int s=m+n;
                m=min(m,n);
                n=s-m;
                matritca.insert(matritca.begin()+n,matritca[m]);
                matritca.insert(matritca.begin()+m,matritca[n+1]);
                matritca.erase(matritca.begin()+m+1,matritca.begin()+m+2);
                matritca.erase(matritca.begin()+n+1,matritca.begin()+n+2);
            }
            }
        }
    }
};


//vector<RACIONAL>

template<typename T>
MATRITCA_CLASS <T> operator + (MATRITCA_CLASS <T> A, MATRITCA_CLASS <T> B)
{
    vector <vector<T>> telo_c;
    vector<T> pustaia_stroka;
    for(int i=0; i<A.telo().size();++i)
    {
        telo_c.push_back(pustaia_stroka);
        for(int j=0; j<A.telo()[0].size(); ++j)
        {
            telo_c[i].push_back(A.telo()[i][j]+B.telo()[i][j]);
        }
    }
    MATRITCA_CLASS <T> C(telo_c);
    return C;
}

template <typename T>
MATRITCA_CLASS <T> operator - (MATRITCA_CLASS <T> A, MATRITCA_CLASS <T> B)
{
    vector <vector<T>> telo_c;
    vector<T> pustaia_stroka;
    for(int i=0; i<A.telo().size();++i)
    {
        telo_c.push_back(pustaia_stroka);
        for(int j=0; j<A.telo()[0].size(); ++j)
        {
            telo_c[i].push_back(A.telo()[i][j]-B.telo()[i][j]);
        }
    }
    MATRITCA_CLASS <T> C(telo_c);
    return C;
}

template <typename T>
MATRITCA_CLASS <T> operator * (MATRITCA_CLASS <T> A, MATRITCA_CLASS <T> B)
{
    vector <vector<T>> telo_c;
    vector<T> pustaia_stroka;
    T d;
    for(int i=0; i<A.telo().size();++i)
    {
        telo_c.push_back(pustaia_stroka);
        for(int j=0; j<B.telo()[0].size(); ++j)
        {
            d=0;
            for(int t=0; t<B.telo().size();++t)
            {
                d+=A.telo()[i][t]*B.telo()[t][j];
            }
            telo_c[i].push_back(d);
        }
    }
    MATRITCA_CLASS <T> C(telo_c);
    return C;
}

vector <RACIONAL> reshenie_sistemy_nul(MATRITCA_CLASS<RACIONAL> A)
{
    int nomer_ne_nul=-1;
    RACIONAL otvet=RACIONAL(0);
    //A.vyvod();
    //cout << '\n';
    A.privedenie_k_trapetcevidnoi_forme();
    vector <vector <RACIONAL> > a=A.telo();
    //A.vyvod();
    //cout << '\n';
    vector <RACIONAL> reshenie_naoborot;
    for(int i=a.size()-1; i>-1; i=i-1)
    {
        if(a[i][a[0].size()-1]!=0 || nomer_ne_nul!=-1)
        {
            if(nomer_ne_nul==-1)
            {
                nomer_ne_nul=i;
                reshenie_naoborot.push_back(RACIONAL(1));
            }
            otvet=RACIONAL(0);
            int z=a[0].size();
            //cout << "@" << z-1 << " " << i-nomer_ne_nul-2+z << '\n' ;
            for(int t=z-1; t>z-2-nomer_ne_nul+i; --t)
            {
                otvet=otvet-a[i][t]*reshenie_naoborot[z-1-t];
                //cout << otvet << " " << reshenie_naoborot[z-1-t] << "! ";
                //cout << "& " << t << " "<< i << " " << a[i][t] << " " << reshenie_naoborot[z-1-t] <<"& ";
            }
            if(a[i][z-2-nomer_ne_nul+i]!=0)
            {
                reshenie_naoborot.push_back(otvet/a[i][z-2-nomer_ne_nul+i]);
                //cout << "!" <<otvet/a[i][z-2-nomer_ne_nul+i] << '\n';
            }
            //cout << "!" <<otvet << '\n';H2SO4+Ca3P2=H2O+Ca3P2O8+SO2
        }
    }
    vector <RACIONAL> reshenie;
    for(int t=reshenie_naoborot.size()-1; t>=0; t--)
    {
        //cout << reshenie_naoborot[reshenie_naoborot.size()-1-t];
        reshenie.push_back(reshenie_naoborot[t]);
    }
    for(int t=0; t<reshenie.size();++t)
    {
        if(reshenie[t].znam()>1)
        {
            reshenie=reshenie*reshenie[t].znam();
        }
    }
    return reshenie;
}

int kolvo_elementa(string veshestvo, int nomer_element)
{
    string element1;
    for(int t=0; t<veshestvo.size(); ++t)
    {
        //if(veshestvo[a])
    }
}

//template<typename T>
MATRITCA_CLASS <RACIONAL> reaktcia_v_uravnenie  (string reaktcia)
{
    vector <string> veshestva;
    string element;
    string veshestvo;
    int kolvo_veshestv=count(reaktcia.begin(),reaktcia.end(),'+')+2;
    int kolvo_elementa_int;
    string kolvo_elementa_string;
    map <string, int> nomer_stroki_elementa;
    vector<vector<RACIONAL>> sistema_uravneniy;
    vector <RACIONAL> nul_stroka;
    for(int i=0; i<kolvo_veshestv;++i)
    {
        nul_stroka.push_back(RACIONAL(0));
    }
    for(int t=0; t<reaktcia.size(); ++t)
    {
        if(reaktcia[t]>='A' && reaktcia[t]<='Z')
        {
            element.erase(element.begin(),element.end());
            element.push_back(reaktcia[t]);
            if(reaktcia[t+1]>='a' && reaktcia[t+1]<='z' )
            {
                element.push_back(reaktcia[t+1]);
            }
            if(nomer_stroki_elementa.find(element)==nomer_stroki_elementa.end())
            {
                nomer_stroki_elementa[element]=nomer_stroki_elementa.size();
            }
        }
    }
    for(int i=0; i<nomer_stroki_elementa.size();++i)
    {
        sistema_uravneniy.push_back(nul_stroka);
    }
    int t=0;
    for(int i=0; i<reaktcia.size(); ++i)
    {
        if(reaktcia[i]=='+' || reaktcia[i]=='=')
        {
            ++t;
        }
        if(reaktcia[i]>='A' && reaktcia[i]<='Z')
        {
            element.erase(element.begin(),element.end());
            element.push_back(reaktcia[i]);
            if(reaktcia[i+1]>='a' && reaktcia[i+1]<='z' )
            {
                ++i;
                element.push_back(reaktcia[i]);
            }
            if(reaktcia[i+1]>='1' && reaktcia[i+1]<='9')
            {
                kolvo_elementa_string.erase(kolvo_elementa_string.begin(),kolvo_elementa_string.end());
                ++i;
                for(i; (i<reaktcia.size() && (reaktcia[i]>='1' && reaktcia[i]<='9')); ++i)
                {
                    kolvo_elementa_string.push_back(reaktcia[i]);
                }
                kolvo_elementa_int=stoi(kolvo_elementa_string);
                if(i<reaktcia.size())
                {
                    --i;
                }
            }
            else
            {
                kolvo_elementa_int=1;
            }
            if(i>reaktcia.find("="))
            {
                sistema_uravneniy[nomer_stroki_elementa[element]][t]=sistema_uravneniy[nomer_stroki_elementa[element]][t]-RACIONAL(kolvo_elementa_int);
            }
            else
            {
                sistema_uravneniy[nomer_stroki_elementa[element]][t]=sistema_uravneniy[nomer_stroki_elementa[element]][t]+RACIONAL(kolvo_elementa_int);
            }

        }
    }
    return MATRITCA_CLASS <RACIONAL> (sistema_uravneniy);

}
/*template<typename T>

template<typename T>
class matrix {
public:
    matrix() : body() {}
    const vector< vector<T> >& get_ref() const {
        return body;
    }

    void multiply_into_myself(T what) {
        for(auto& row : body) {
            for(auto& elem : row) {
                elem*=what;
            }
        }
    }
private:
    vector< vector<T> > body;
};*/

/*bool test() {
    vector<RACIONAL> f(2, 3), g(3, 4);
    if(f-f != RACIONAL(0)) {
        return false;
    }
    if(f+g != RACIONAL(17, 12)) {
        return false;
    }

    if(f != f) {
        return false;
    }

    //...
    return true;
}*/

int main()
{
    cout << fixed << setprecision(5);
    /*int a,n;
    cin >> n;
    vector<RACIONAL> pustaia_stroka;
    vector<vector <RACIONAL>> b;
    for(int t=0; t<n; ++t)
    {
        b.push_back(pustaia_stroka);
        for(int i=0; i<n; ++i)
        {
            cin >> a;
            b[t].push_back(RACIONAL(a));
        }
    }
    MATRITCA_CLASS<RACIONAL> A= MATRITCA_CLASS<RACIONAL>(b);
    A.privedenie_k_trapetcevidnoi_forme();
    A.vyvod();

    */vector<RACIONAL> pustaia_stroka;
    string reaktcia;
    cin >> reaktcia;
    MATRITCA_CLASS<RACIONAL> A=reaktcia_v_uravnenie(reaktcia);
    vector<RACIONAL> a=reshenie_sistemy_nul(A);
    cout << '\n';
    for(int i=0; i<a.size();++i)
    {
        cout << a[i].racvint() << " ";
    }
    //cout << RACIONAL(0)*RACIONAL(0);*/

    return 0;
}


