class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size(),res=0,up=0,down=0;
        for(int i=1;i<n;i++){
            if(down>0&&arr[i-1]<arr[i]||arr[i]==arr[i-1])up=down=0;
            if(arr[i]<arr[i-1])down++;
            if(arr[i]>arr[i-1])up++;
            if(up&&down)res=max(res,up+down+1);
        }
        return res;
    }
};