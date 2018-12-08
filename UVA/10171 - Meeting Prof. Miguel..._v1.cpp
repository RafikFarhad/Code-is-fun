/// RAFIK FARHAD
/// fb.com/rafikfarhad
/// SUST_CSE_13
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause");
#define ppp system("pause");
#define ok cout << "OK" <<endl;
#define pf printf
#define CLR(a, b) for(int o=0; o<b; o++) a[o] = 0
#define PI 2*acos(0)
#define SIZE 100000
using namespace std;

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T> void MyDebug(T x, T y)
{
    cout << "Debugging: " << x << ", " << y << endl;
}
template <class T> void MyDebug(T x, T y, T z)
{
    cout << "Debugging: " << x << ", " << y << ", " << z << endl;
}
int adj[30][30], adj2[30][30];

void F_W_for_Me(int n)
{
    int i, j, k;
    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                adj[i][j] = MIN(adj[i][j], adj[i][k]+adj[k][j]);
    return;
}

void F_W_for_Prof(int n)
{
    int i, j, k;
    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                adj2[i][j] = MIN(adj2[i][j], adj2[i][k]+adj2[k][j]);
    return;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("10171.inp","r",stdin);
#endif
    ///                                    MAIN
    int i, j, k, l, n, a, b, street, keis=0;;
    while(sf("%d ", &n)==1 && n )
    {
        char p, q, r, s;
        street= 0;
        map <char, int> mp;
        mp.clear();
        map <int, char> mp2;
        mp2.clear();
        for(i=0; i<30; i++)
            for(j=0; j<30; j++)
            {
                adj[i][j] = SIZE;
                adj2[i][j] = SIZE;
            }
        for(j=0; j<30; j++)
        {
            adj[j][j] = 0;
            adj2[j][j] = 0;
        }
        for(i=0; i<n; i++)
        {
            sf("%c %c %c %c %d ",&p, &q, &r, &s, &b);
            if(mp.count(r)==0)
            {
                mp[r] = street;
                mp2[street++] = r;
            }
            if(mp.count(s)==0)
            {
                mp[s] = street;
                mp2[street++] = s;
            }
            if(q=='B')
            {
                if(p=='Y')
                {
                    adj[mp[r]][mp[s]] = MIN(b, adj[mp[r]][mp[s]]);
                    adj[mp[s]][mp[r]] = MIN(b, adj[mp[s]][mp[r]]);
                }
                else
                {
                    adj2[mp[r]][mp[s]] = MIN(b, adj2[mp[r]][mp[s]]);
                    adj2[mp[s]][mp[r]] = MIN(b, adj2[mp[s]][mp[r]]);
                }
            }
            else
            {
                if(p=='Y')
                {
                    adj[mp[r]][mp[s]] = MIN(adj[mp[r]][mp[s]], b);
                }
                else
                {
                    adj2[mp[r]][mp[s]] = MIN(b, adj2[mp[r]][mp[s]]);
                }
            }
        }

        sf("%c %c ", &p, &q);

        if(mp.count(p)==0 || mp.count(q)==0)
        {
            if(p==q)
            {
                pf("0 %c\n", q);
                continue;
            }
            else pf("You will never meet.\n");
            continue;
        }
        F_W_for_Me(street);
        F_W_for_Prof(street);
        int mini = SIZE, pos = 0, start = mp[p], endd = mp[q];
        vector <char> lists;
        lists.clear();
        for(i=0; i<street; i++)
        {
            if(mini >= adj[start][i]+adj2[endd][i])
            {
                if(mini > adj[start][i]+adj2[endd][i])
                {
                    lists.clear();
                    mini =  adj[start][i]+adj2[endd][i];
                }
                lists.pb(mp2[i]);
            }
        }
        if(mini>=SIZE)
        {
            pf("You will never meet.\n");
            continue;
        }
        cout << mini;
        sort(lists.begin(), lists.end());
        for(i=0; i<lists.size(); i++)
            pf(" %c", lists[i]);
        cout << endl;
        /*for(i=0; i<street; i++, cout << endl)
            for(j=0; j<street; j++)
                cout << adj[i][j] << "\t";
        cout << endl;
        for(i=0; i<street; i++, cout << endl)
            for(j=0; j<street; j++)
                cout << adj2[i][j] << "\t";*/

    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
