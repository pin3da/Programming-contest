class Solution {
    public boolean isValid(String s) {
        if(s.length()==0)
            return true;
        Stack<Character> stk = new Stack<>();
        boolean ans = true;
        
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(ch=='(' || ch=='{' || ch=='[')
                stk.push(ch);
            else{
                if(stk.size()==0){
                    ans = false;
                    break;
                }      
                if(ch==')'){
                    if(stk.pop()!='('){
                        ans = false;
                        break;
                        
                    }
                }
                if(ch==']'){
                    if(stk.pop()!='['){
                        ans = false;
                        break;
                        
                    }
                }
                if(ch=='}'){
                    if(stk.pop()!='{'){
                        ans = false;
                        break;
                        
                    }
                }
            }
        }
        if(stk.size()!=0){
            ans=false;
        }
        return ans;
    }
}
