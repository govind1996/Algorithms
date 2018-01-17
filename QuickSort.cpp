#include <bits/stdc++.h>
using namespace std;

long int Partition(vector<float> &v,long int low,long int high)
{
    float pivot=v[high];
    long int i=low-1;
    for(long int j=low;j<high;j++)
    {
        if(v[j]<=pivot)
        {
            i++;
            float temp=v[j];
            v[j]=v[i];
            v[i]=temp;
        }
    }
    float temp=v[i+1];
    v[i+1]=v[high];
    v[high]=temp;
    return (i+1);
}

void quickSort(vector<float> &v,long int low,long int high)
{
    if(low<high)
    {
        long int pi=Partition(v,low,high);
        quickSort(v,low,pi-1);
        quickSort(v,pi+1,high);
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
    quickSort(v,0,v.size()-1);
    for(long int i=0;i<v.size();i++)
        file2<<v[i]<<" ";
    return 0;
}
