#include<bits/stdc++.h>
using namespace std;

void Merge(vector<float>& v,long int p,long int q,long int r)
{
    long int n1=q-p+1;
    long int n2=r-q;
    long int i,j;
    vector<float> L(n1);
    vector<float> R(n2);
    for(i=0;i<n1;i++)
        L[i]=v[p+i];
    for(j=0;j<n2;j++)
        R[j]=v[q+j+1];
    i=0;j=0;
    for(long int k=p;k<=r;k++)
    {
        if(i<n1&&j<n2)
        {
            if(L[i]<R[j])
            {
                v[k]=L[i];
                i++;
            }
            else
            {
                v[k]=R[j];
                j++;
            }
        }
        else if(j<n2)
        {
            v[k]=R[j];
            j++;
        }
        else
        {
            v[k]=L[i];
            i++;
        }
    }
}
void mergeSort(vector<float>& v,long int l,long int r)
{
    if(l<r)
    {
        long int m;
        m=(l+r)/2;
        mergeSort(v,l,m);
        mergeSort(v,m+1,r);
        Merge(v,l,m,r);
    }
}
int main(int argc,char **argv)
{
    ifstream file1;
    ofstream file2;
    file1.open(argv[1]);
    file2.open("out.txt");
    vector<float> v;
    float num;
    while(file1>>num)
    {
        v.push_back(num);
    }
    file1.close();
    mergeSort(v,0,v.size()-1);
    for(long int i=0;i<v.size();i++)
        file2<<v[i]<<" ";

}
