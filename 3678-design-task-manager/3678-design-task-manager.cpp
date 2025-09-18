// class TaskManager {
// private:
//     map<int, int> priority_task;
//     unordered_map<int, int> task_priority;
//     unordered_map<int, int> task_user;

// public:
//     TaskManager(vector<vector<int>>& tasks) {
//         for (auto& it : tasks) {
//             int user = it[0];
//             int task = it[1];
//             int prior = it[2];
//             priority_task[-prior] = task;
//             task_priority[task] = prior;
//             task_user[task] = user;
//         }
//     }
    
//     void add(int userId, int taskId, int priority) {
//         priority_task[-priority] = taskId;
//         task_priority[taskId] = priority;
//         task_user[taskId] = userId;
//     }
    
//     void edit(int taskId, int newPriority) {
//         int oldprior = task_priority[taskId];
//         priority_task.erase(-oldprior);
//         priority_task[-newPriority] = taskId;
//         task_priority[taskId] = newPriority;
//     }
    
//     void rmv(int taskId) {
//         int priority = task_priority[taskId];
//         priority_task.erase(-priority);
//         task_priority.erase(taskId);
//         task_user.erase(taskId);
//     }
    
//     int execTop() {
//         if (priority_task.empty()) return -1;
//         auto it = priority_task.begin();
//         return task_user[it->second];
//     }
// };

class TaskManager {
private:
unordered_map<int , pair<int,int>> index_to;
priority_queue<pair<int,int>> pq;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& it : tasks) {
            int user = it[0];
            int task = it[1];
            int prior = it[2];
            index_to[task] = {prior , user};
            pq.push({prior , task});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        index_to[taskId] = {priority , userId};
        pq.push({priority , taskId});
    }
    
    void edit(int taskId, int newPriority) {
        index_to[taskId].first = newPriority;
        pq.push({newPriority , taskId});
    }
    
    void rmv(int taskId) {
        index_to[taskId].first=-1;
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [p, i] = pq.top();
            if (index_to.count(i) && index_to[i].first == p) {
                pq.pop();
                int u=index_to[i].second;
                index_to.erase(i);
                return u;
            }
            pq.pop();
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */