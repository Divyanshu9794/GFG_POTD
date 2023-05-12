int arrayOperations(int n, vector<int> &arr) {
        int i = 0;
        int j = 0;
        int count = 0;
        bool isPresent = false;
        for(int index = 0 ;index < arr.size();index++){
            if(arr[index] == 0){
                isPresent = true;
                break;
            }
        }
        while(j<arr.size()){
            if(arr[j] == 0 || (j == arr.size()-1 && arr[j] != 0)){
                if(i<j || (j == arr.size()-1 && arr[j] != 0)){
                    count++;
                }
                i = j+1;
            }
            j++;
        }
        return isPresent?count:-1;
    }
