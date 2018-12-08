/**         HODOR          **/


#include<bits/stdc++.h>
#define CLR(o)                                  memset(o, 0x00, sizeof o)
#define CLR1(o)                                 memset(o, -1, sizeof o)
#define takei(a)                                scanf("%d", &a)
#define takell(a)                               scanf("%lld", &a)
#define takellu(a)                              scanf("%llu", &a)
#define sf                                      scanf
#define pb                                      push_back
#define mp                                      make_pair
#define ppp                                     system("pause")
#define okk                                      cout << "OKA" <<endl;
#define pf                                      printf
#define NL                                      printf("\n")
#define PI                                      2*acos(0)
//#define all(o)                                  o.begin(), o.end()
#define csi                                     pf("Case %d: ", ++keis)
#define csii                                     pf("Case %d:\n", ++keis)
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875
#define xx                                      first
#define yy                                      second

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
//int SET(int mask, int pos){return mask singlebar (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
int T, N, id[110];
const int L = 100;
double mat[110][110], b[110];
const double EPS = 0.000000001;

void GAUSSIAN()
{
    int i, j, pos, k;
    double t;
    for(i=1; i<=L;i++)
        id[i] = i;
    for(i=1; i<L; i++)
    {
        if(fabs(mat[i][i])<EPS)
        {
            pos = i+1;
            while(mat[pos][i]==0)
                pos++;
            for(j=1; j<=L; j++)
                swap(mat[i][j], mat[pos][j]);
            swap(b[i], b[pos]);
            swap(id[i], id[pos]);
        }
        for(j=i+1; j<=L; j++)
        {
            t = mat[j][i]/mat[i][i];
            for(k=i; k<=L; k++)
            {
                mat[j][k]-=mat[i][k]*t;
            }
            b[j] -= b[i]*t;
        }
    }
    for(i=L; i>=1; i--)
    {
        for(j=i+1; j<=L; j++)
        {
            b[i]-=mat[i][j]*b[j];
        }
        b[i]/=mat[i][i];
    }
    return;
}

int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l, c, d, x, y, a, keis(0);
//    char pp[100];
//    fgets(pp, 100, stdin);
    int ar[102];
    takei(t);

    while(t--)
    {
        takei(c);
        CLR(ar);
        CLR(mat);
        for(i=1; i<=100; i++)
        {
            ar[i] = i;
            //matrix[i][100] = 1.0;
        }
        while(c--)
        {
            takei(a);
            takei(d);
            ar[a] = d;
        }

        for(i=1; i<100; i++)
        {
            for(j=1; j<=6; j++)
            {
                if(i+j>100)
                {
                    mat[i][i]--;
                    continue;
                }
                mat[i][ar[i+j]]-=1.0;
            }
            mat[i][i] += 6.0;
            b[i] = 6.0;
        }
        mat[100][100] = 1.0;
        b[100] = 0.0;
        GAUSSIAN();
        csi;
        pf("%.10lf\n", b[1]);
    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



