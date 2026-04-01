class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        int n = positions.size();
        vector<int> actual_idx(n); // 0 1 2 3 ... n-1
        for(int i=0;i<n;i++){
            actual_idx[i] = i;
        }

        //using lambda function
        auto lambda = [&](int &i, int &j){
            if(positions[i]<positions[j]){
                return true;
            }
            return false;
        };

        sort(begin(actual_idx),end(actual_idx), lambda);

        vector<int> result;
        stack<int> st;
        for(int &currIdx : actual_idx){ //Any index will be visited atmost twice
            if(directions[currIdx] == 'R'){
                st.push(currIdx);
            } else{ //towards left
                while(!st.empty() && healths[currIdx] > 0){
                    int top_idx = st.top();
                    st.pop();

                    if(healths[top_idx] > healths[currIdx]){
                        healths[top_idx] -=1;
                        healths[currIdx] = 0;
                        st.push(top_idx);
                    } else if(healths[top_idx] < healths[currIdx]){
                        healths[currIdx] -=1;
                        healths[top_idx] = 0;
                    } else{
                        healths[currIdx] = 0;
                        healths[top_idx] = 0;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            if(healths[i]>0){
                result.push_back(healths[i]);
            }
        }

        return result;



        
    }
};