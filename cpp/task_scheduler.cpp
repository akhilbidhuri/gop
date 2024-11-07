/*
    Question - https://leetcode.com/problems/task-scheduler/description/
*/
class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
    //     lemon chus le code -
    //     int index = 0;
    //     priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> nextValue;
    //     unordered_map<char, int> taskCount;
    //     for(char c: tasks) {
    //         if (taskCount.find(c) == taskCount.end()) {
                
                
    //             .push({-1, c});
    //         }
    //         taskCount[c]++;
    //     }
    //     int time = 0;
    //     while(index < tasks.size()) {
    //         pair<int, char> task = nextValue.top();
    //         nextValue.pop();
    //         if (taskCount[task.second] > 0) {
    //             taskCount[task.second]--;
    //             cout<<task.second<<" "<<task.first<<" "<<time<<" "<<endl;
    //             if (time > 0 && task.first > -1 && time <= n + task.first) {
    //                 time += n - (time - task.first);
    //             }
    //             time++;
    //             index++;
    //             nextValue.push({time, task.second});
    //         }
    //     }
    //     return time; 
    // better code -
        unordered_map<char, int> freq;
        int maxFreq = 0;
        for (char c: tasks) 
        {
            freq[c]++;
            maxFreq = max(maxFreq, freq[c]);
        }

        int time = (maxFreq - 1) * (n + 1);
        for (auto taskFreq : freq) if (taskFreq.second == maxFreq) time++;
        return max((int)tasks.size(), time);
    }
};