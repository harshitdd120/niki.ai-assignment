#include <bits/stdc++.h>
#define MOD 1000000007
#define  lli long long int
using namespace std;
void mat_mul(lli a[][2],lli c[][2], lli ans[][2])
{
    //simple function to multiply 2 matrices.
    lli b[2][2]={0};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            b[i][j]=((b[i][j]%MOD)+(a[i][k]%MOD)*(c[k][j]%MOD))%MOD;
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        ans[i][j]=b[i][j];
    }
}
void fast_power(lli a[][2],lli b)
{
    //Fast power method to get power of any number in exponential time , modified so that can apply on Matrices.
    //initially c will be identity matrix
    lli c[2][2]={{1,0},{0,1}};

    while(b>1)
    {

        if(b%2==0)
        {
            mat_mul(a,a,a);
            b=b/2;
        }
        else
        {
            mat_mul(c,a,c);
            mat_mul(a,a,a);
            b=(b-1)/2;
        }
    }
    mat_mul(c,a,a);
}
int main()
{
    // The pattern is simply a fibonacci series.
    // As the given constraints are too big to apply DP for the calculation of fibonacci series,
    // we are going to apply fast modular matrix exponentiation method to calculate fibonacci numbers.
    int t;
    cin>>t;
    while(t--)
    {
        lli n,a[2][2]={{1,1},{1,0}},x1;
        cin>>n;
        //as the answer for n=1 is 2 that means the series is starting from 3rd term , so calculating (n+2)th term.
        fast_power(a,n+2);

            x1=a[0][1];
            a[0][0]=1;
            a[0][1]=1;
            a[1][0]=1;
            a[1][1]=0;
        cout<<x1<<endl;
    }
}

