#include<bits/stdc++.h>
using namespace std;
void InsertionSort(float arr[],int n)
{
   for(long int i=1;i<n;i++)
    {
        float k=arr[i];
        long int j=i-1;
        while(j>=0&&arr[j]>k)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=k;
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

