#include<stdio.h>
int main(){
    int T;
    double A,B,C;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%lf %lf %lf",&A,&B,&C);
        double sum;
        sum=A+B;
        sum=sum/3;
        A=A-sum;
        A=(A*C)/sum;
        printf("%.0lf\n",A);
    }
    return 0;
}
