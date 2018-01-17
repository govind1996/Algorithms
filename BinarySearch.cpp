#include<bits/stdc++.h>
using namespace std;
int BinarySearch(vector<long int> v,long int l,long int r,long int num){
    long int m;
    while(l<=r)
    {
            m=(l+r)/2;
        if(v[m]==num)
            return m;
        else if(v[m]<num)
            l=m+1;
        else
            r=m-1;
    }
    return -1;
}
int main(int argc, char **argv)
{
    ifstream file1,file2;
    ofstream file3;
    file1.open(argv[1]);
    file2.open(argv[2]);
    file3.open("out.txt");
    vector<long int> v;
    long int ans,input,num;
    while(file1>>num)
    {
        v.push_back(num);
    }
 //   for(int i=0;i<v.size();i++)
     //   cout<<v[i]<<endl;
    file1.close();
    while(file2>>input)
    {
        ans=BinarySearch(v,0,v.size()-1,input);
        file3<<ans<<endl;
    }
    file2.close();
    file3.close();
    return 0;
}

