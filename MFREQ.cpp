#include<iostream>
using namespace std;
int main()
{
    int n,m,cnt,k,i;
    cin>>n>>m;
    int a[n];
     for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        while(m--)
        {
            int l,r,k,cnt=1,flag=0,ans=-1;
            cin>>l>>r>>k;
            for(int i=l-1;i<=r;)
            {
                if((i+k)<=n&&a[i]==a[i+k-1])
                {
                    ans=a[i];
                    i=r+1;
                }
                else if(a[i]==a[i+1])
                    {
                        cnt++;

                        if(cnt>=k)
                        {
                            ans=a[i];
                            flag=1;
                            i=r+1;
                        }
                        i++;
                    }
                    else
                    {
                        if(cnt>=k)
                        {
                            ans=a[i];
                            flag=1;
                            i=r+1;
                        }
                        i+=cnt;
                        cnt=1;
                    }

            }


                cout<<ans<<endl;

        }
}
