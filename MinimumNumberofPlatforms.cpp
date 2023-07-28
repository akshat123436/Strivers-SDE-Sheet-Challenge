int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    vector<int> timeFrame(2401);

    for (int i = 0; i < n; i++)
    {
        // int arrivalMinutes = (at[i] % 100) + ((at[i] / 100) * 60);
        // int departureMinutes = (dt[i] % 100) + ((dt[i] / 100) * 60);

        timeFrame[at[i]] += 1;
        timeFrame[dt[i] + 1] += -1;
    }

    int ans = timeFrame[0];
    for (int i = 1; i < 2401; i++)
    {
        timeFrame[i] += timeFrame[i - 1];
        ans = max(ans, timeFrame[i]);
    }
    // for(int i = 0;i<1440;i++){
    //     if(timeFrame[i]) cout << timeFrame[i] << " ";
    // }
    // cout << endl;
    return ans;
}