#include <iostream>
#include <string.h>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;
int len=0;
void max_Heapify(int arr[],int i,int n)
{
    int l=2*i+1;
    int r=2*i+2;
    int highest=i;
    if(l<n&&arr[highest]<arr[l])
        highest=l;
    if(r<n&&arr[highest]<arr[r])
        highest=r;
    if(highest!=i)
    {
        int temp=arr[i];
        arr[i]=arr[highest];
        arr[highest]=temp;
        max_Heapify(arr,highest,n);
    }
}
int deletion(int arr[])
{
    if(len==0)
        return 0;
    int maxi=arr[0];
    len-=1;
    arr[0]=arr[len];
    max_Heapify(arr,0,len);
    return maxi;
}
void insertion(int arr[],int val)
{
    len+=1;
    int i=len;
    arr[i]=val;
    while(i>0&&arr[(i-1)/2]<arr[i])
    {
        int temp=arr[(i-1)/2];
        arr[(i-1)/2]=arr[i];
        arr[i]=temp;
        i=(i-1)/2;
    }
}
int main(int argc,char **argv)
{

    ifstream f1;
    ofstream f2;
    f1.open(argv[1]);
    f2.open("out.txt");
    int arr[5000];
    char s[15],f,g;
    int result1;
    while(f1>>s)
    {
        int choice;
        if(!(strcmp(s,"delete")))
            choice=1;
        else
            choice=2;
        switch(choice)
        {

            case 1:result1=deletion(arr);
                    f2<<result1<<" ";
                    break;
            case 2:int num;
                    f1>>num;
                    insertion(arr,num);
                    break;

        }
    }
}
