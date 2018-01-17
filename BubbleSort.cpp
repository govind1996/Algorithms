#include<bits/stdc++.h>
using namespace std;
int BubbleSort(float arr[],int n)
{
    float temp;
    for(long int i=0;i<n-1;i++)
    {
        for(long int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
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
    BubbleSort(arr,n);
    for(long int i=0;i<n;i++)
    {
        file2<<arr[i]<<" ";
    }
    file2.close();
    return 0;
}

