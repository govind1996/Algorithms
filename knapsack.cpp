#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n);
int max(int a, int b);
int main(int argc, char const *argv[]) {
  int value,weight,capacity,i=0,n;
  int w[1000],v[1000];
  ifstream file1;
  ofstream file2;
  file1.open(argv[1]);
  file2.open("out.txt");
  file1>>capacity;
  while (file1>>weight>>value) {
    w[i]=weight;
    v[i]=value;
    i++;
  }
  n=i;
  file1.close();
  int answer=0;
  answer=knapSack(capacity,w,v,n);
  file2<<answer;
  file2.close();
  return 0;
}
int max(int a, int b) { return (a > b)? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}
