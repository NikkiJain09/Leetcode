/*
* Problem: 845. Longest Mountain in Array
* Link: https://leetcode.com/problems/longest-mountain-in-array/
*/
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int len = A.size();
        if(len < 3)
            return 0;
        
        int maxLen = 0;
        vector<int> down(len, 0);
        vector<int> up(len, 0);
        
        for(int i= len-2; i>=0; i--)
        {
            if(A[i] > A[i+1])
                down[i] = down[i+1] +1;
        }
        
        for(int i= 0; i<len; i++)
        {
            if(i>0 && A[i] > A[i-1])
                up[i] = up[i-1] +1;
            
            if(up[i] && down[i]) // if imp for case [2,2,2]..ie when up n down are zero
                maxLen = max(up[i]+down[i]+1, maxLen);
        }
        
        return maxLen;
    }
};