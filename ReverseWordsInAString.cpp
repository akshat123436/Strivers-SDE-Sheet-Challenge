#include <stack>
string reverseString(string &str)
{
    // Write your code here.
    string temp;
    // string ans;

    // for(auto a : str){
    // 	if(a == ' '){
    // 		if(temp != ""){
    // 			ans = temp + " " + ans;
    // 			temp = "";
    // 		}
    // 	}
    // 	else{
    // 		temp.push_back(a);
    // 	}
    // }
    // if(temp != ""){
    // 	ans = temp + " " + ans;
    // 	temp = "";
    // }

    stack<string> s;

    for (char a : str)
    {
        if (a == ' ')
        {
            if (temp != "")
            {
                s.push(temp);
                temp = "";
            }
        }
        else
        {
            temp += (a);
        }
    }
    if (temp != "")
    {
        s.push(temp);
        temp = "";
    }
    string ans;
    while (!s.empty())
    {
        ans += (s.top());
        s.pop();
        if (!s.empty())
            ans += " ";
    }

    return ans;
}