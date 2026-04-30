
class Solution{
    public:
    bool isMaxHeap(vector<int> &arr)
    {
        int n = arr.size();
         for(int i = 0; i < (n/2); i++)
                if((i*2+1 < n && arr[i] < arr[i*2+1]) || (i*2+2 < n && arr[i] < arr[i*2+2]))
                    return false;
        return true;
    }
};