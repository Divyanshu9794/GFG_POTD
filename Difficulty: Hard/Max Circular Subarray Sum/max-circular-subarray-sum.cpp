class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n=(int)arr.size();
        
        int s1=0;
        int s2=0;
        int x=*min_element(arr.begin(),arr.end());
        int res=*max_element(arr.begin(),arr.end());
        if(res<0)
        return res;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            s1+=arr[i];
            s2+=arr[i];
            if(s1<0)
            s1=0;
            if(s2>0)
            s2=0;
            
            res=max(res,s1);
            x=min(x,s2);
        }
        
        res=max(res,sum-x);
        return res;
    }
};