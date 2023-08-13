//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


void printKAlmostPrimes(int k, int n);

int main() {
	// your code goes herei
int t;
cin>>t;
while(t--){
	int n,k;
	cin>>n>>k;
    printKAlmostPrimes(n,k);
    cout<<endl;
}


	return 0;
}
// } Driver Code Ends


/*You are required to complete this function*/
void printKAlmostPrimes(int k, int n)
{
//Your code here
int c=0,m=0;
   for(int i=2;i<40000;i++){
       int a=i;
       for(int j=2;j<=sqrt(i);j++){
           while(a%j==0){
               c++;
               a/=j;
           }
       }
       if(a!=1){
          c++; 
       }
       if(c==k){
           cout<<i<<" ";
           m++;
       }
       if(m==n){
           break;
       }
       c=0;
   }
   
}