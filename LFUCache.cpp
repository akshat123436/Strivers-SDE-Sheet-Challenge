#include <bits/stdc++.h>
class LFUCache
{
private:
    int recency;
    int capacity;
    set<pair<pair<int, int>, int>> s;
    vector<int> arr, freq, recent;

public:
    LFUCache(int capacity)
    {
        // Write your code here.
        arr.resize(1001);
        freq.resize(1001);
        recent.resize(1001);
        recency = 0;
        this->capacity = capacity;
        for (auto &a : arr)
            a = -1;
    }

    int get(int key)
    {

        int val = arr[key];
        if (val == -1)
            return val;
        recency++;
        auto a = s.find({{freq[key], recent[key]}, key});
        s.erase(a);
        freq[key]++;
        recent[key] = recency;
        s.insert({{freq[key], recent[key]}, key});
        return val;
    }

    void put(int key, int value)
    {
        recency++;
        if (arr[key] == -1)
        {
            if (s.size() == capacity)
            {
                auto topMost = *(s.begin());
                int elementKey = topMost.second;
                freq[elementKey] = 0;
                recent[elementKey] = 0;
                arr[elementKey] = -1;
                s.erase(topMost);
                freq[key]++;
                recent[key] = recency;
                arr[key] = value;
                s.insert({{freq[key], recency}, key});
            }
            else
            {
                freq[key]++;
                recent[key] = recency;
                arr[key] = value;
                s.insert({{freq[key], recency}, key});
            }
        }
        else
        {
            auto a = s.find({{freq[key], recent[key]}, key});
            s.erase(a);
            freq[key]++;
            recent[key] = recency;
            arr[key] = value;
            s.insert({{freq[key], recency}, key});
        }
    }
};
