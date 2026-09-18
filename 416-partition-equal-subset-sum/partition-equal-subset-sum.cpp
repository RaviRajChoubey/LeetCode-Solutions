class Solution {
public:
    // bool solve(vector<int>& nums,int target) {
    //     int n=val.size();
    //     vector<vet t[n+1][W+1];
        
    //     for(int i=0;i<n+1;i++) {
    //         for(int j=0;j<W+1;j++) {
    //             if(i==0 || j==0) {
    //                 t[i][j]=false;
    //             }
    //         }
    //     }
    //     for(int i=1;i<n+1;i++) {
    //         for(int j=1;j<target;j++) {
    //             if(nums[i]<=j) {
    //                 t[i][j]=t[i][j-arr[i]] || t[i+1][j];
    //             }
    //             t[i][j]=
    //         }
    //     }
    // }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
        }
        if(sum%2!=0) {
            return false;
        }
        // else {
        //     return solve(nums,sum/2);
        // }
        int target=sum/2;
        int n=nums.size();

        vector<vector<bool>> t(n+1,vector<bool>(target+1,false));

        for(int i=0;i<=n;i++) {
            t[i][0]=true;
        }

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=target;j++) {
                if(nums[i-1]<=j) {
                    t[i][j]=t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][target];
    }
};