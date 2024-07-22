class Solution {
public:
void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";st.pop();
    }
    cout<<endl;
}
    string words(int x,int count){
        if(x==0){return "";}
        string ans;
        vector<string> ones={"One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine "};
        vector<string> t={"Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
        vector<string> tens={"Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
        vector<string> o={"","Thousand ","Million ","Billion "};
        int hundred=x/100;
        x%=100;
        if(hundred!=0){ans+=ones[hundred-1];ans+="Hundred ";}
        int ten=x/10;
        x%=10;
        if(ten>=2){ans+=tens[ten-2];if(x!=0)ans+=ones[x-1];}
        else if(ten==1){ans+=t[x];}
        else if(x!=0){ans+=ones[x-1];}
        ans+=o[count-1];
        return ans;

    }
    string numberToWords(int num) {
        if(num==0){return "Zero";}
        stack<int> st;
        int count=0;
        while(num!=0){
            st.push(num%1000);
            num/=1000;
            count++;
        }
        // printStack(st);
        string ans="";
        while(!st.empty()){
            int x=st.top();
            ans+=words(x,count);
            // ans+=" ";
            count--;
            st.pop();
        }
        ans.pop_back();
        // ans.pop_back();

        return ans;

    }
};
