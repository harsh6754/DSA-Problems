class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>s;
        for(int i = 0;i<x.length();i++)
        {
            char ch  = x[i];
            if(ch == '(' || ch == '{' || ch=='['){
                s.push(ch);
            }
            else{
                if(!s.empty()){
                    char top = s.top();
                    if(
                        (ch == ')' && top == '(') ||
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[') ){
                        s.pop();
                    }
                    else {
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(s.empty()){
            return true;
        }
        else {
            return false;
        }
    }

};