#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][n];
    int sum=0;
    int maxsum=2*n-2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            sum+=a[i][j];
        }
    }
    sum-=n*n;
for (int slice = 2*n-1; slice >=0; --slice)    {
        int z = slice < n ? 0 : slice - n + 1;
        for (int j = z; j <= slice - z; ++j)
        {
            a[slice-j][j]=1;
            if(sum>0)
            {
                if(sum>=m-1)
                {
                    sum-=m-1;
                    a[slice-j][j]=m;
                }
                else
                {
                    a[slice-j][j]=1+sum;
                    sum=0;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

}
