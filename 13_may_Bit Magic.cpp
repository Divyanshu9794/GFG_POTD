class Solution {
  public:
    int bitMagic(int n, vector<int> &arr) {
         int cnt=0,i;
        for(i=0,n--;i<=n;i++,n--)
            if(arr[i]!=arr[n])cnt++;
          if(cnt%2)cnt++;
        return cnt/2;
    }
};
