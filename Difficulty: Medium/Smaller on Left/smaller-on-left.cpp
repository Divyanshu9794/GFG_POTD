vector<int> Smallestonleft(int arr[], int n) {
    vector<int>ans;
    
    ans.push_back(-1);
    
    set<int>s;
    
    for(int i=1;i<n;i++){
        
        s.insert(arr[i-1]);
        
        int maxi=-1;
        
        for(auto it=s.begin();it!=s.end();it++){
            
            if(arr[i]>*it)
            maxi=max(maxi,*it);
           
        }
        
        ans.push_back(maxi);
    }
    return ans;
}
