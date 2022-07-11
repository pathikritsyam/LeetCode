// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n=cardPoints.size();
//         // vector<vector<vector<int>>>dp(k+1,vector<vector<int>>(n+1,vector<int>(n+1,0)));
//         vector<vector<int>>prev(n+1,vector<int>(n+1,0)),curr(n+1,vector<int>(n+1,0));
//         for(int i=n;i>=0;i--){
//             for(int j=0;j<=n;j++){
//                 prev[i][j]=0;
//             }
//         }
//         for(int l=1;l<=k;l++){
//             for(int i=n-1;i>=0;i--){
//                 for(int j=1;j<n;j++){
//                     int leftmax=cardPoints[i]+prev[i+1][j];
//                     int rightmax=cardPoints[j]+prev[i][j-1];
//                     curr[i][j]=max(leftmax,rightmax);
//                 }
//             }
//             prev=curr;
//         }
//         return prev[0][n-1];
//     }
// };
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0,mini=1e9,j=0,n=cardPoints.size(),window=0;
        for(int i=0;i<n;i++)sum+=cardPoints[i];
        for(int i=0;i<n-k;i++){
            window+=cardPoints[i];
        }
        mini=min(mini,window);
        for(int i=n-k;i<n;i++){
            window+=(cardPoints[i]-cardPoints[j++]);
            mini=min(mini,window);
        }
        return (sum-mini);
    }
};