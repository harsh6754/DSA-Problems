class Solution{
public:
    void solve(stack<int> &St,int X){
        if(St.empty()){
            St.push(X);
            return ;
        }
        int num = St.top();
        St.pop();
        
        solve(St,X);
        
        St.push(num);
    }

    stack<int> insertAtBottom(stack<int> &St,int X){
        solve(St,X);
        return St;
    }
};