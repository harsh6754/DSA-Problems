#include<iostream>
#include<vector>
using namespace std;

vector<string>prettyJSON(string A) {
    auto r = 0; 
    vector<string> result(1, "");
    int brace = 1;
    for (auto i = 0; i<A.length(); ++i)
    {
        switch(A[i])
        {
            case ' ':
                continue;
                
            case '{':
            case '[':
                if(brace==1 && r==0)
                    result[r] += A[i];
                else
                {
                    result.push_back("");
                    result[++r] += string(brace, '\t');
                    result[r] += A[i];
                    ++brace;
                }
                result.push_back("");
                result[++r] += string(brace, '\t');
                break;
                
            case '}':
            case ']':
                if (brace>1)
                {
                    result.push_back("");
                    result[++r] += string(brace-1, '\t');
                    result[r] += A[i];
                    --brace;
                }
                else
                {
                    result.push_back("");
                    result[++r] += A[i];
                    --brace;
                }
                break;
                
            case ',':
                result[r] += A[i];
                if (A[i+1]=='{' || A[i+1]=='[')
                    continue;
                else
                {
                    result.push_back("");
                    result[++r] += string(brace, '\t');
                }
                break;
                
            case ':':
                result[r] += A[i];
                if (A[i+1]=='{' || A[i+1]=='[')
                {
                    result.push_back("");
                    result[++r] += string(brace, '\t');
                    result[r] += A[++i];
                    ++brace;
                    if(A[i+1]!='{' && A[i+1]!='[')
                    {
                        result.push_back("");
                        result[++r] += string(brace, '\t');
                        result[r] += A[++i];
                    }
                }
                break;
                
            default:
                result[r] += A[i];
                break;
        }
    }
    return result;
}
 