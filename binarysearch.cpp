#include<iostream>
using namespace std;
int binarysearch(int a[],int start, int end1, int x)
{
    int mid=(start+end1)/2;
    if(x==a[mid])
        return mid;
    else if(x>mid)
        binarysearch(a,mid+1,end1,x);
    else if(x<mid)
        binarysearch(a,0,mid-1,x);
    else
        return -1;
}
int main()
{
    int n,i,x;
    cout<<"Enter no. of elements in array: ";
    cin>>n;
    int a[n];
    cout<<"Enter sorted array: ";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter element to search: ";
    cin>>x;
    if(binarysearch(a,0,n-1,x)==-1)
        cout<<"Number "<<x<<" not found in array";
    else
    cout<<"No. found at "<<binarysearch(a,0,n-1,x)+1<<" location"<<endl;

}
