#include <bits/stdc++.h>
using namespace std;
long int len=0;
void Heapify(long int arr[],long int i,long int n)
{
    long int l=2*i+1;
    long int r=2*i+2;
    long int highest=i;
    if(l<n&&arr[l]>arr[highest])
        highest=l;
    if(r<n&&arr[r]>arr[highest])
        highest=r;
    if(highest!=i)
    {
        long int temp=arr[i];
        arr[i]=arr[highest];
        arr[highest]=temp;
        Heapify(arr,highest,n);
    }
}
long int Delete(long int arr[])
{
    if(len==0)
    {
        return -1;
    }
    long int maxi=arr[0];
    arr[0]=arr[len-1];
    len--;
    Heapify(arr,0,len);
    return maxi;
}
void Insert(long int arr[],long int val)
{
    len++;
    arr[len]=val;
    long int i=len;
    while(i>0&&arr[(i-1)/2]<arr[i])
    {
        swap(arr[(i-1)/2],arr[i]);
        i=(i-1)/2;
    }
}
int main(int argc,char **argv)
{

    ifstream file1;
    ofstream file2;
    file1.open(argv[1]);
    file2.open("out.txt");
    long int arr[1000];
    char s[10];
    while(file1>>s)
    {
        int ch;
        if(!(strcmp(s,"insert")))
            ch=1;
        else
            ch=2;
        switch(ch)
        {
            case 1:long int num;
                    file1>>num;
                    Insert(arr,num);
                    break;
            case 2:file2<<Delete(arr)<<" ";
                    break;
        }
    }
}
