1 2 3 4
1 
2 
3 
4
1 2
2 3
3 4
1 2 3
2 3 4
1 2 3 4

1:- 4 :- 4*1 :- 0 :- (4-0)*(0+1) :- (n-i)*(i+1)
2:- 6 :- 3*2 :- 1 :- (4-1)*(1+1) 
3:- 6 :- 2*3 :- 2 :- (4-2)*(2+1)
4:- 4 :- 1*4 :- 3 :- (4-3)*(3+1)


1 1 3 3 1
1 1 1 3 3


int countStudents(vector<int>height){
    vector<int>temp=height;
    sort(temp.begin(),temp.end());
    int n=height.size();
    int ans=0;
    for(int i=0;i<n;i++){
        if(height[i]!=temp[i]) ans++;
    }
    return ans;
}


1 2 3 4

1 
2 
3 
4
1 2
1 3
1 4
2 3
2 4
3 4
1 2 3
1 2 4
1 3 4
2 3 4
1 2 3 4


1:- 8 :-  
2:- 8 :- 
3:- 8 :- 
4:- 8 :-  2 * 2 * 2


1 
2 
3 
1 2
2 3
1 3
1 2 3


1:- 4
2:- 4
3:- 4  2 * 2 :-(2^(n-1)


