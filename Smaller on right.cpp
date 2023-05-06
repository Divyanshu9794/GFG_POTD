#include <iostream>
using namespace std;

#include<set>

int main() {
//code
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c=0;
    set<int>s;
    for(int i=n-1;i>=0;i--){
        s.insert(a[i]);
        int d=distance(s.begin(),s.find(a[i]));
        c=max(c,d);
}
cout<<c<<endl;
}
return 0;
}