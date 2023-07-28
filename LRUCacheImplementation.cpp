#include <unordered_map>
#include <set>

class LRUCache
{
private:
    unordered_map<int, int> val, recentNumber;
    set<pair<int, int>> s;
    int capacity;
    int recency;

public:
    LRUCache(int capacity)
    {
        // Write your code here
        this->capacity = capacity;
        recency = 0;
    }

    int get(int key)
    {
        // Write your code here
        recency++;
        if (!val[key])
            return -1;
        s.erase({recentNumber[key], key});
        recentNumber[key] = recency;
        s.insert({recency, key});
        if (val[key])
            return val[key];
    }

    void put(int key, int value)
    {
        // Write your code here
        recency++;
        if (val[key])
        {
            val[key] = value;
            s.erase({recentNumber[key], key});
            recentNumber[key] = recency;
            s.insert({recency, key});
        }
        else
        {
            if (s.size() == capacity)
            {
                auto topMost = *(s.begin());
                val[topMost.second] = 0;
                s.erase({recentNumber[topMost.second], topMost.second});
                val[key] = value;
                recentNumber[key] = recency;
                s.insert({recency, key});
            }
            else
            {
                val[key] = value;
                recentNumber[key] = recency;
                s.insert({recency, key});
            }
        }
    }
};
