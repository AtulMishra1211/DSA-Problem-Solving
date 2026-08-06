class Solution {
public:
    vector<int> findNSE(vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        vector<int> nse(n);
        
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i] = st.empty()?n:st.top();
           st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int>& arr){
       stack<int> st;
       int n = arr.size();
       vector<int> psee(n);
       
       for(int i = 0; i<n; i++){
         while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
         }
           psee[i] = st.empty()?-1:st.top();
           st.push(i);
        }
        return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
      vector<int> nse = findNSE(arr);
      vector<int> psee = findPSEE(arr);
      int n = arr.size();
      const int MOD = 1e9 + 7;

      int total = 0;

      for(int i=0; i<n; i++){
         int R = nse[i]-i;
         int L = i-psee[i];
         total = (total + (1LL*R*L*arr[i])%MOD)%MOD;
      }
      return total;
    }
};