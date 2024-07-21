class Solution {
public:
  void parenthesis(vector<string> &v, string temp,int open,int close){
        if(open<=0 and close<=0){v.push_back(temp);return;}
        if(open>close or open<0){return;}
       if(open==close){temp+='(';open--;}
        // string temp1=temp,temp2=temp;
        // temp1+='(';
        // open--;
        parenthesis(v,temp+'(',open-1,close);
        // temp2+=')';
        // close--;
        parenthesis(v,temp+')',open,close-1);

    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        parenthesis(v,"",n,n);
        return v;
    }
};
