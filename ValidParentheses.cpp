bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> s;
    for (auto a : expression)
    {
        if (a == '}')
        {
            if (s.size() && s.top() == '{')
                s.pop();
            else
                s.push(a);
        }
        else if (a == ')')
        {
            if (s.size() && s.top() == '(')
                s.pop();
            else
                s.push(a);
        }
        else if (a == ']')
        {
            if (s.size() && s.top() == '[')
                s.pop();
            else
                s.push(a);
        }
        else
            s.push(a);
    }
    if (s.size())
        return false;
    else
        return true;
}