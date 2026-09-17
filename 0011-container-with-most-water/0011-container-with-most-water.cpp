class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0;
        int ans=0;
        int high=height.size()-1;
        while(low<=high){
            int water=min(height[low],height[high])*(high-low);
            ans=max(ans,water);

            if(height[low]<height[high]){
                low+=1;
            }
            else{
                high-=1;
            }
        }
        return ans;
    }
};