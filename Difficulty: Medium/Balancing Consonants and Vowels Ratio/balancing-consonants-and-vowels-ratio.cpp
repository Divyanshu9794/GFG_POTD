class Solution {
  public:
   bool isVowel(char x){
        return (x=='a' || x=='e' || x=='i' || x=='o' || x=='u');
    }
    
    int countBalanced(vector<string>& arr) {
        // code here
        unordered_map<int, int> last;
        last[0]=1;
        
        int ans=0;
        int sum=0;
        
        for(auto z: arr){
            
            int n=z.size();
            for(int i=0;i<n;i++){
                  if(isVowel(z[i])){
                      sum++;
                  }
                  else{
                      sum--;
                  }
                  
                  if(i==n-1){
                      ans += last[sum];
                      last[sum]++;
                      
                  }
                  
            }
        }
     
        return ans;   
    
    }
};