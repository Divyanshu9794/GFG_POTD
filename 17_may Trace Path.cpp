class Solution{
public:
        int isPossible(int n, int m, string s){
        int h=0,v=0,minh=0,maxh=0,maxv=0,minv=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                h--;
                minh=min(minh,h);
            }
            if(s[i]=='R'){
                h++;
                maxh=max(maxh,h);
            }
            if(s[i]=='U'){
                v--;
                minv=min(minv,v);
            }
            if(s[i]=='D'){
                v++;
                maxv=max(maxv,v);
            }
        }
        return maxh-minh+1<=m && maxv-minv+1<=n;
    }
};
