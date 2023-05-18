class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
         vector<int>ans;
         sort(range.begin(),range.end());
         vector<vector<int>>merged=overlappedInterval(range);
         
         for(int i=0;i<queries.size();i++)
         {
             int k=queries[i];
             bool flag=false;
             for(int i=0;i<merged.size();i++)
             {
                 int diff=merged[i][1]-merged[i][0]+1;
                 if(diff>=k)
                 {
                     ans.push_back(merged[i][0]+k-1);
                     flag=true;
                     break;
                 }
                 else
                 k-=diff;
             }
             if(flag==true)
             flag=false;
             else
             ans.push_back(-1);
         }
         return ans;
    } 
    vector<vector<int>> overlappedInterval(vector<vector<int>>& in) {
        
         vector<vector<int>>ans;
         if(in.size()==0)
         return ans;
         
         sort(in.begin(),in.end());
         vector<int>temp=in[0];
         for(auto it:in)
         {
            if(it[0]<=temp[1])
            {
                temp[1]=max(it[1],temp[1]);
            }
            else 
            {
                ans.push_back(temp);
                temp= it;
            }
    }
     ans.push_back(temp);
     return ans;
    }
    
};
