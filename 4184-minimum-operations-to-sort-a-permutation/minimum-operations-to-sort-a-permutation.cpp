class Solution {
public:
    int minOperations(vector<int>& nums) {
        /*overall how i approached this problem is firstly i failed the test case 
        [1,0,2] that's when i thought there are two diffrent cases in each type one
        is normal bring to front or bring to back and rotate once or first reverse 
        the array and bring to back and reverse again --> this was my whole intuition
        and the part to checking inc and dec is obvious because if array is not already circular or reverse then it is obvious that we cannot make it sorted using any number or steps as it is there in example 3... this problem is not same but similar to pancake sorting i get my intuition to this type of problems from there.
        leetcode 969
        */
        int pos=0,ans=INT_MAX;
        //first we need to find the posn of 0 because it is out starting point
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)pos=i;
        }
        bool inc=true;
        int n=nums.size(); //we will check if array is sorted in inc order or not
        for(int i=0;i<n;i++){
            if(nums[(pos+i)%n]!=i){
                inc=false;break;
            }
        }
        if(inc){
            //if array is inc sorted then 2 possible ways to have answer 
            //normal ops bring 0 to front...
            int op1=pos;
            // reverse the array once then bring zero to back and rev again...
            int op2=n-pos+2;
            ans=min({ans,op1,op2});
        }
        bool dec=true;
        //this is the same thing as above just for reverse circular
         for(int i=0;i<n;i++){
             int curr=nums[i];
             int nxt=nums[(i+1)%n];
            if((nxt-curr+n)%n!=n-1){
                dec=false;break;
            }
        }
        if(dec){
            int k=n-1-pos;
            //rotate left and reverse once..
            int op1=k+1;
            //reverse first then rotate...
            int op2=n-k+1;
            ans=min({ans,op1,op2});
        }
        return ans==INT_MAX?-1:ans;
    }
};