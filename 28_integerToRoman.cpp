class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        //thousand
        int q=num/1000;
        num%=1000;
        while(q--){ans+="M";}
        //hundred
        q=num/100;
        num%=100;
        if(q/5==1){
            if(q==9){ans+="CM";}
            else{ans+="D";
            
            while(q>5){ans+="C";q--;}
            }
        }
        else{
            if(q==4){ans+="CD";}
            else{while(q--){ans+="C";}}
        }

        //tens
        q=num/10;
        num%=10;
        if(q/5==1){
            if(q==9){ans+="XC";}
            else{ans+="L";
            
            while(q>5){ans+="X";q--;}
            }
        }
        else{
            if(q==4){ans+="XL";}
            else{while(q--){ans+="X";}}
        }

        //ones;
        q=num;
        if(q/5==1){
            if(q==9){ans+="IX";}
            else{ans+="V";
            
            while(q>5){ans+="I";q--;}
            }
        }
        else{
            if(q==4){ans+="IV";}
            else{while(q--){ans+="I";}}
        }

        return ans;
    }
};
