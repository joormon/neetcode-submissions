class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>> cars(n);
        for(int i=0;i<n;i++){
            cars[i]={position[i],speed[i]};
        }
        //sort the cars based on position in descending order
        sort(cars.begin(),cars.end(),[](pair<int,int>& a, pair<int,int>& b){
            return a.first>b.first;
        });

        //declaring a stack to store time monotonically decreasing order;
        stack<double> st;
        for(auto car:cars){
            double time=(double)(target-car.first)/car.second;
            if(st.empty() || st.top()<time){
                st.push(time);
            }
        }

        return st.size();
    }
};
