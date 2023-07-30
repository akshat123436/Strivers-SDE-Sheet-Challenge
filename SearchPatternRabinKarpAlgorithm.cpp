#define totalCharacters 256

vector<int> stringMatch(string text, string pattern)
{
    int textLength = text.length();
    int patternLength = pattern.length();
    int maxBit = 1;
    int primeNumber = 11;
    for (int i = 0; i < patternLength - 1; i++)
    {
        maxBit = (totalCharacters * maxBit) % primeNumber;
    }

    int patternHash = 0;
    int textHash = 0;

    for (int i = 0; i < patternLength; i++)
    {
        patternHash = (totalCharacters * patternHash + pattern[i]) % primeNumber;
        textHash = (totalCharacters * textHash + text[i]) % primeNumber;
    }
    vector<int> ans;
    for (int i = 0; i <= textLength - patternLength; i++)
    {
        if (patternHash == textHash)
        {
            bool same = true;
            for (int j = 0; j < patternLength; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    same = false;
                    break;
                }
            }
            if (same)
            {
                ans.push_back(i + 1);
            }
        }
        if (i < textLength - patternLength)
        {
            textHash = (totalCharacters * (textHash - text[i] * maxBit) + text[i + patternLength]) % primeNumber;
            if (textHash < 0)
                textHash += primeNumber;
        }
    }

    return ans;
}
