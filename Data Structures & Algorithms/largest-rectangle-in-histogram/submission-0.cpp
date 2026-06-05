class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int>r(n);
        vector<int>l(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&h[st.top()]>=h[i]){
                st.pop();
            }
            if(!st.empty())l[i]=st.top();
            else l[i]=-1;
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&h[st.top()]>=h[i])st.pop();
            if(!st.empty())r[i]=st.top();
            else r[i]=n;
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            cout<<l[i]<<" "<<r[i]<<endl;
            ans=max(ans,h[i]*(r[i]-l[i]-1));
        }
        return ans;
    }
};
