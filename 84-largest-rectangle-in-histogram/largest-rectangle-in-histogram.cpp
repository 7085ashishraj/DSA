class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size(); //finding size

        int nsi[n]; //index of next smaller element

        stack<int> st;
        nsi[n-1] = n;
        st.push(n-1); //index of last next samller element

        //traverse from last
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && arr[st.top()] >= arr[i]) st.pop(); //pop

            if(st.size() == 0) nsi[i] = n;
            else nsi[i] = st.top(); //ans

            st.push(i); //push

        }


        int psi[n]; //index of previous smaller element

        stack<int> gt;
        psi[0] = -1;
        gt.push(0);  //index of first prev. smaller element

        //traverse from forward
        for(int i=1;i<n;i++){
             while(gt.size()>0 && arr[gt.top()] >= arr[i]) gt.pop(); //pop

            if(gt.size() == 0) psi[i] = -1;
            else psi[i] = gt.top(); //ans

            gt.push(i); //push
        }

        //calculating area

        int maxArea = 0;
        for(int i=0;i<n;i++){
            int height = arr[i];
            int width = nsi[i] - psi[i] - 1;
            int area = height * width;
            maxArea = max(area, maxArea);
        }
        return maxArea;

    }
};