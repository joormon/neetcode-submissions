class Solution 
{
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& visited)
    {

        if(path.size()==visited.size())
        {
            result.push_back(path);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]) continue;

            path.push_back(nums[i]);
            visited[i]=true;

            backtrack(nums,path,visited);

            path.pop_back();
            visited[i]=false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<bool> visited(nums.size());
        vector<int> path;

        backtrack(nums,path,visited);
        return result;
    }
};
