class Solution {
public:
    void print(stack<char> s){
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
    bool isValid(string s) {
        stack<char> st;
for(int i=0;i<s.size();i++){
            char x=s[i];
            if(x=='[' or x=='{' or x=='(' or st.empty()){st.push(x);}
            char t=st.top();
            if(t==')' or t=='}' or t==']'){return 0;}
            else if(x==')' and t!='('){return 0;}
            else if(x==')' and t=='('){st.pop();}
            
            else if(x=='}' and t!='{'){return 0;}
            else if(x=='}' and t=='{'){st.pop();}

            else if(x==']' and t!='['){return 0;}
            else if(x==']' and t=='['){st.pop();}

            // print(st);
        }
        return st.empty();
    }
};
