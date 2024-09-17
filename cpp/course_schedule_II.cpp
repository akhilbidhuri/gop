/*
    Question: https://leetcode.com/problems/course-schedule-ii/

    Solution using Kahn's Algorithm
    Author: Akhil Bidhuri
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> inDegree(numCourses, 0);

        for (vector<int> pre: prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        queue<int> nextCourse;
        for (int i=0;i<numCourses;i++) {
            if (inDegree[i] == 0) 
                nextCourse.push(i);
        }

        vector<int> courseSchedule;
        while(!nextCourse.empty()) {
            int course = nextCourse.front();
            nextCourse.pop();
            for (int relatedCourse: graph[course]) {
                if (--inDegree[relatedCourse] == 0) {
                    nextCourse.push(relatedCourse);
                }
            } 
            courseSchedule.push_back(course);   
        }
        
        for (int inDegVal: inDegree) {
            if (inDegVal != 0) {
                courseSchedule.clear();
                break;
            }
        }

        return courseSchedule;
    }
};