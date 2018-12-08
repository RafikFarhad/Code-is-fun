///#define_SUST
#include<cstdio>
int main()
{
    int n, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n<11) printf("%d %d\n", 0, n-0);
        else printf("%d %d\n", 10, n-10);
    }
    return 0;
}
