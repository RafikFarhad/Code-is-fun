#include<string.h>
#include<stdio.h>
int main()
{
    int i,j=0,k,n;
    char str1[1000],str3[100];


    while(scanf("%d",&n)==1 and n!=0)
    {
        j++;
        getchar();

        printf("Case %d:\n",j);
        printf("#include<string.h>\n");
        printf("#include<stdio.h>\n");
        printf("int main()\n{\n");

        for(i=0; i<n; i++)
        {
            char str2[1100];
            int l;



            gets(str2);
            l=strlen(str2);
            if(l==0)
            {
                i--;
                continue;
            }

            printf("printf(\"");

            for(k=0; k<l; k++)
            {
                if(str2[k]=='\"' || str2[k]=='\\')
                    printf("\\");
                printf("%c",str2[k]);
            }

            printf("\\n\");");
            printf("\n");

        }
        printf("printf(\"\\n\");\n");

        printf("return 0;\n");


        printf("}\n");


    }

    return 0;
}
