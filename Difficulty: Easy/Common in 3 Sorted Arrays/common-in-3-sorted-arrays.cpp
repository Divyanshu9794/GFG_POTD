class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        int m=a.size();
        int n=b.size();
        int o=c.size();
        int x=0;
        int y=0;
        int z=0;
        vector<int>ans;
        while(x<m && y<n && z<o)
        {
            if(a[x]==b[y] && b[y]==c[z])
            {
                if(ans.size()==0 || ans.back()!=a[x])
                {
                    ans.push_back(a[x]);
                }
                x++;
                y++;
                z++;
            }
            else if(a[x]<=b[y] && a[x]<=c[z])
            {
                x++;
            }
            else if(b[y]<=a[x] &&b[y]<=c[z])
            {
                y++;
            }
            else if(c[z]<=a[x] && c[z]<=b[y])
            {
                z++;
            }
        }
        return ans;
        
    }
};