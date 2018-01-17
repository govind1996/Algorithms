#include<bits/stdc++.h>
using namespace std;
void InsertionSort(float arr[],int n)
{
    float temp;
    for(long int i=0;i<n-1;i++)
    {
        long int ind=i;
        for(long int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[ind])
            {
                ind=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[ind];
        arr[ind]=temp;
    }
}
int main(int argc, char **argv)
{
    int n=0;
    float arr[10000],num;
    ifstream file1;
    ofstream file2;
    file1.open(argv[1]);
    file2.open("out.txt");
    while(file1>>num)
    {
        arr[n]=num;
        n++;
    }
    file1.close();
    InsertionSort(arr,n);
    for(long int i=0;i<n;i++)
    {
        file2<<arr[i]<<" ";
    }
    file2.close();
    return 0;
}

