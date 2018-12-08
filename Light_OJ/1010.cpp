///#define_SUST
#include <cstdio>
#include <cmath>

int main()
{
    int t, keis = 0, a, b, ans;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &a, &b);
        if(a==1 || b==1) ans = a*b;
        else if(a==2 || b==2)
        {
            if(a==2)
            {
                a = a^b;
                b = a^b;
                a = a^b;
            }
            if(a%4==0) ans = a;
            else if(a%2==0) ans = a+2;
            else ans = a+1;
        }
        else ans = (int)ceil((a*b)/2.0);
        printf("Case %d: %d\n", ++keis, ans);
    }
    return 0;
}
