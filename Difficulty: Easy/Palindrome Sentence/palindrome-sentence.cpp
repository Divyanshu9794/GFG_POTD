class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        if(s.empty())
           return 1;
        string st;
        for(int i=0;i<s.size();i++) {
        if(isalnum (s[i]))
         st+= tolower(s[i]);
        }
        if(st.empty())
          return 1;
        
        int ptr1=0,ptr2=st.size()-1;
        while(ptr1<=ptr2) {
            if(st[ptr1] != st[ptr2])
               return 0;
               
            ptr1++;
            ptr2--;
        }
        return 1;
    }
};