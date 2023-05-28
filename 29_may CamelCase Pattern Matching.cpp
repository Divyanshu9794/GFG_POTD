 vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        // code here
        vector<string> final;
        for(int i=0;i<N;i++){
            string t="";
            for(int j=0;j<Dictionary[i].size();j++){
                if( Dictionary[i][j]>= 'A' && Dictionary[i][j] <= 'Z'){
                    t+=Dictionary[i][j];
                    if(t==Pattern){
                        final.push_back(Dictionary[i]);
                    }
                }
                
            }
            // if(t==Pat)
        }
        sort(final.begin(),final.end());
        if(final.size()==0){
            return {"-1"};
        }
        return final;
    }
