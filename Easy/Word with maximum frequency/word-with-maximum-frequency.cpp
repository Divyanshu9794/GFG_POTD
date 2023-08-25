//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;



string maximumFrequency(string s);

int main()
{
    int t;cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++)
    {

        string s;
        getline(cin,s);
        
        
        cout << maximumFrequency(s) << endl;

    }
    return 0;
}

// } Driver Code Ends


string maximumFrequency(string s){
        map<string,int> un;
        int maxi=0;
        string temp, ans;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                un[temp]++;
                temp.clear();
            }
            else{
                temp.push_back(s[i]);
            }
        }
        un[temp]++;
        temp.clear();
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(maxi<un[temp]){
                    ans=temp;
                    maxi=un[temp];
                }
                temp.clear();
            }
            else{
                temp.push_back(s[i]);
            }
        }
        if(maxi<un[temp]){
                    ans=temp;
                    maxi=un[temp];
                }
                temp.clear();
        return ans + " " + to_string(un[ans]);
}
