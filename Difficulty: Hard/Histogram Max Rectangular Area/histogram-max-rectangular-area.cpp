class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // code here
        stack<int>st;
        int maxi = 0;
        int n  = arr.size();
        for(int i = 0 ; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                
            int element =  st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()?-1:st.top();
                maxi = max(maxi, (arr[element]*(nse-pse-1)));
            }
            st.push(i);
            
        }
        while(!st.empty()){
     int  nse = n;
    int element = st.top();
    st.pop();
    
    int pse = st.empty()?-1:st.top();
    maxi = max(maxi, (arr[element]*(nse-pse-1)));
        }
        return maxi;
    }
};
