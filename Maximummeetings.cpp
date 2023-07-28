int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int n = start.size();
    stack<int> meetings;
    vector<pair<int, int>> sortedMeetings;
    for (int i = 0; i < n; i++)
    {
        sortedMeetings.push_back({start[i], end[i]});
    }

    sort(sortedMeetings.begin(), sortedMeetings.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int s = sortedMeetings[i].first;
        int e = sortedMeetings[i].second;
        if (meetings.empty())
        {
            meetings.push(e);
        }
        else
        {
            int firstEndingTime = meetings.top();
            if (firstEndingTime < s)
            {
                meetings.push(e);
            }
            else
            {
                meetings.pop();
                meetings.push(min(e, firstEndingTime));
            }
        }
        ans = max(ans, int(meetings.size()));
    }

    return ans;
}