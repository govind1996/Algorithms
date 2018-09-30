#include<iostream>
using namespace std;
void merge(int a[], int p,int q,int r); //forward declaration
void mergesort(int a[], int p,int r);
int main()
{
int n,i,j;
cout<<"Enter total number of elements/size: ";
cin>>n;
int a[n];
cout<<"Enter numbers: ";
for(i = 0;i< n; i++)// to input the numbers into an array
cin>>a[i];
for(i = 0;i< n; i++)
cout<< a[i]<<" ";
mergesort(a,0,n-1);
cout<<"Array sorted in increasing order: "<< endl;
for(i = 0;i< n; i++)
cout<< a[i]<<" ";
return 0;
}

void mergesort(int a[], int p, int r)
{

if(p < r) {
int q=(p+r)/2; //middle point
mergesort(a,p,q);
mergesort(a,q+1,r);
merge(a,p,q,r);
}
}

//first subarray is a[p,p+1,...,q]
//second subarray is a[q+1,...,r]
void merge(int a[],int p,int q,int r) //merges a[p,p+1,...q] and a[q+1,....r] in sorted form
{
int i,j,k,n1,n2;
n1= q-p+1;
n2= r-q;
cout<<"n2 is"<<n2<<"r is"<<r<<"p is "<<p<<endl;//n1 and n2 are size of first and second subarray resp.
int L[n1],R[n2];
cout<<"L part"<<endl;
for(i = 0 ; i< n1; i++) //copying into left subarray
{L[i]= a[p+i];cout<<L[i]<<"";}
cout<<"R part"<<endl;
for(j = 0 ; j< n2; j++) //copying into left subarray
{R[j]= a[(q+1)+j];cout<<R[j]<<",";}
cout<<endl;

i=0; //initial value of L subarray
j=0; //initial value of R aubarray
k=p; //initial value of a array
while (i < n1 && j < n2 )
{
//put the smaller among L[i] or R[j] in a[k]
if(L[i] <= R[j]) {
a[k]=L[i];
i++;
}
else {
a[k]=R[j];
j++;
}
cout<<"hi"<<a[k]<<endl;
k++; //to place a new number at next position
}
cout<<"hello"<<a[1]<<endl;
while (i < n1 ) /*Invoked for copying remaining items, for ex: L=[7,8] and R=[1,2]*/
{
a[k]=L[i];
i++;
k++;
}
cout<<"hello"<<a[1]<<endl;
while (j < n2 )/*Invoked for copying remaining items, for ex: L=[1,2] and R=[7,8] */
{
a[k]=R[j];
j++;
k++;
}
cout<<"hello"<<a[1]<<endl;
}
//The second function is mergesort which divides the array into two parts and
// calls the merge function to merge them
