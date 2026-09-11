class Solution {

    void merge(vector<int>& nums,int left,int mid ,int right)
    {
        int n1=mid-left+1;
        int n2=right-mid;

        vector<int> L1(n1), L2(n2);

        for(int i=0;i<n1;i++)
        {
            L1[i]=nums[left+i];
        }

        for(int i=0;i<n2;i++)
        {
            L2[i]=nums[mid+1+i];
        }

        int i=0,j=0;
        int k=left;
        while(i<n1 && j<n2)
        {
            if(L1[i]<=L2[j])
            {
                nums[k++]=L1[i++];
            }
            else
            {
                nums[k++]=L2[j++];
            }
        }

        while(i<n1)
        {
            nums[k++]=L1[i++];
        }

        while(j<n2)
        {
            nums[k++]=L2[j++];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums,left,mid,right);
        }
    }

   public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};