class Solution {
public:
    int days(string date) {
        int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        int m = stoi(date.substr(0,2));
        int d = stoi(date.substr(3,2));

        int total = d;

        for(int i = 0; i < m - 1; i++)
            total += month[i];

        return total;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        
        string start = max(arriveAlice, arriveBob);
        string end = min(leaveAlice, leaveBob);

        if(start > end)
            return 0;

        return days(end) - days(start) + 1;
    }
};