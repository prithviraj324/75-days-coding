#include<bits/stdc++.h>
using namespace std;
//good solution, but TLE due to moving elements back and forth from heap to vector temp
class Solution {
public:
    struct compare {
        bool operator()(pair<char, int>& p, pair<char, int>& q) {
            return p.second < q.second;
        }
    };  //custom comparator
    
    
    void deduct(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] > 0)
                arr[i]--;
            else arr[i] = 0;
        }
    }   //O(1) time operation
    
    
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();
        int sz = tasks.size(), time = 0;
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> maxh; //most frequent element on top of heap
        vector<int> arr(26, 0);
        
        for(auto c: tasks)  //calculate count of tasks
            arr[c - 'A']++;
        for(int i=0;i<26;i++) {    //push tasks with count onto max heap
            if(arr[i] == 0) continue;
            maxh.push({ (char)(i+(int)'A') , arr[i]});
        }
        arr=vector<int>(26, 0);    //repurpose count array as `time till next duplicate` array
        //time = -1 implies task can be performed immediately
        vector<pair<char, int>> temp;   //stores heap top's temporarily while searching for task with no wait time

        pair<char, int> top;
        while(!maxh.empty()/* && maxh.top().second > 0*/) {
            top=maxh.top();
            
            if(arr[top.first - 'A'] == 0) {    //execute top task first iff it doesnt have wait timer
                //executing top.first
                maxh.pop();
                top.second--;   //task exectues, decrement number of tasks by 1
                deduct(arr);    //1 unit of time passes, all tasks wait time reduces by 1
                arr[top.first - 'A'] = n;   //add waiting time
                if(top.second > 0)
                    maxh.push(top);
                time++;
            }
            
            else if(arr[top.first - 'A'] != 0) {   //some waiting time is there
                while(arr[top.first - 'A'] > 0) {     //pop elements till task with no wait time is found
                    temp.push_back(top);
                    maxh.pop();
                    if(maxh.empty()) break;
                    top=maxh.top();
                }   //stops at task with 0 wait time
                if(maxh.size() == 0) {  //no task can be executed instantly, all have wait timers
                    for(auto pr: temp)  //push all tasks onto heap
                        maxh.push(pr);
                    temp.clear();
                    time++; //1 unit of time passes
                    deduct(arr);    // wait time reduces by 1
                    continue;
                }
                else {
                    maxh.pop();
                    if(top.second - 1 > 0)
                        maxh.push({top.first, top.second - 1});
                    time++;    //1 unit of time passes
                    deduct(arr);    // wait time reduces by 1
                    arr[top.first - 'A'] = n;
                    for(auto pr: temp)     //push all tasks onto heap
                        maxh.push(pr);
                    temp.clear();
                }
            }
        }
        
        return time;
    }
};

//same approach, better solution
//need to come up with a rigorous solution
class Solution2 {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26];
        fill(cnt, cnt + 26, 0);
        for (char c : tasks) {
            ++cnt[c - 'A'];
        }
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0) pq.push(cnt[i]);
        }
        int res = 0;
        for (int time = 1; ; ++time) {
            if (!q.empty() && q.front().second <= time) {
                pq.push(q.front().first);
                q.pop();
            }
            if (!pq.empty()) {
                int top = pq.top();
                pq.pop();
                --top;
                if (top > 0) {
                    q.push(make_pair(top, time + n + 1));
                }
            }
            if (q.empty() && pq.empty()) {
                res = time;
                break;
            }
        }
        return res;
    }
};