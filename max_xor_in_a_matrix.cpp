#include <iostream>
#include <climits>
using namespace std;
int a[10001][101];
int kadane2D(int n,int m)
{
    int *columnSum = new int[n];
    int s=INT_MIN,S=INT_MIN,t;
    for(int row = 0; row<m; row++)
    {
        for(int i=0; i<n; i++) columnSum[i] = 0;
        for(int x = row; x<m; x++)
        {
            s = INT_MIN;
            t = 0;
            for(int i=0; i<n; i++)
            {
                columnSum[i]^=a[x][i];
                t^=columnSum[i];
                if(t>s)
                    s = t;

            }
            if(s>S)
                S = s;
        }
    }
    delete [] columnSum;
    return S;
}
int main( void )
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<kadane2D(n,m)<<endl;
    return 0;
}
