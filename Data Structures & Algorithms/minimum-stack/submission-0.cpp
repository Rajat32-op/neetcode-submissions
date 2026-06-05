class MinStack {
public:
    stack<int>st;
    stack<int>pref;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(pref.empty())pref.push(val);
        else pref.push(min(pref.top(),val));
    }
    
    void pop() {
        st.pop();
        pref.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return pref.top();
    }
};
