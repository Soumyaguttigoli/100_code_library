#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
    long long N;
    scanf("%lld",&N);
    int a[40];
    //scanf("%d",&N);

    int k = 0;
    for(int i = 0;N > 0;i++)
    {
        a[i] = N % 2;
        N = N / 2;
        k++;
    }

    //printf("%d\n",k);
    //a[k + 1] = 0;
    while(k != 32)
    {
        a[k] = 0;
        k++;
    }

    /*printf("\n");
    for(int i = 0;i < k;i++)
    {
        printf("%d ",a[i]);
    }*/

    for(int i = 0;i < k;i++)
    {
        if(a[i] == 1)
            a[i] = 0;

        else
            a[i] = 1;
    }

    //printf("\n");
    /*for(int i = 0;i < k;i++)
    {
        printf("%d ",a[i]);
    }*/

    long long sum = 0;
    //printf("\n");
    for(int i = 0;i < k;i++)
    {
        sum = sum + (pow(2,i) * a[i]);
    }

    printf("%lld\n",sum);
    }
}