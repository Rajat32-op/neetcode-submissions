class Solution {
public:
    void eval(char op,stack<int>&st){
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        if(op=='+')st.push(a+b);
        else if(op=='-')st.push(b-a);
        else if(op=='*')st.push(b*a);
        else st.push(b/a);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string s:tokens){
            if(s=="+")eval('+',st);
            else if(s=="-")eval('-',st);
            else if(s=="*")eval('*',st);
            else if(s=="/")eval('/',st);
            else st.push(stoi(s));
        }
        return st.top();
    }
};
