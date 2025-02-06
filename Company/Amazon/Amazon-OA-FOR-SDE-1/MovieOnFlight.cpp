#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> movieDuration(vector<int>& movieDuration, int d){
        vector<int> result;
        int n = movieDuration.size();
        unordered_map<int,int> movieIndex;
        for(int i = 0;i<n;i++){
            movieIndex[movieDuration[i]] = i;
        }
        sort(movieDuration.begin(),movieDuration.end());
        int i = 0;
        int j = n-1;
        int maxDuration = 0;
        while(i<j){
            int sum = movieDuration[i]+movieDuration[j];
            if(sum>d-30){
                j--;
            }else{
                if(sum>maxDuration){
                    maxDuration = sum;
                    result = {movieIndex[movieDuration[i]],movieIndex[movieDuration[j]]};
                }
                i++;
            }
        }
        return result;
    }
};
int main(){
    int n;
    cout<<"Enter the number of movies: ";
    cin>>n;

    vector<int> movieDuration(n);
    for(int i = 0;i<n;i++){
        cout<<"Enter the duration of movie "<<i+1<<": ";
        cin>>movieDuration[i];
    }

    int d;
    cout<<"Enter the duration of the flight: ";
    cin>>d;

    Solution solution;
    vector<int>result = solution.movieDuration(movieDuration,d);
    cout<<"The two movies are: "<<result[0]<<" "<<result[1]<<endl;
    return 0;
}