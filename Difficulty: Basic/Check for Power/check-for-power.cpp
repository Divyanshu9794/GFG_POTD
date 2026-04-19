class Solution {
  public:
    bool isPower(int x, int y) {
        // code here
        float a = float(log2(y)/log2(x));
      return pow(x,a)==y;
      }
    
};