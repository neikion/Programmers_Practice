//https://school.programmers.co.kr/learn/courses/30/lessons/42627

#include <string>
#include <vector>
#include <queue>

namespace DiskController {
    using namespace std;

    class Job {
    public:
        int Id;
        int AddTime;
        int WorkTime;
        int EndTime;
        int WorkingTIme;
        Job() = default;
        Job(int id, vector<int> list) : Id(id), AddTime(list[0]), WorkTime(list[1]),EndTime(0),WorkingTIme(0) {
        }
    };

    struct waitingCompare {
        bool operator()(const Job& value1, const Job& value2) {
            if (value1.AddTime != value2.AddTime) {
                return value1.AddTime > value2.AddTime;
            }
            return value1.Id > value2.Id;
        }
    };
    struct processCompare {
        bool operator()(const Job& value1, const Job& value2) {
            if (value1.WorkTime != value2.WorkTime) {
                return value1.WorkTime > value2.WorkTime;
            }
            if (value1.AddTime != value2.AddTime) {
                return value1.AddTime > value2.AddTime;
            }
            return value1.Id > value2.Id;
        }
    };


    int solution(vector<vector<int>> jobs) {
        int answer = 0;
        priority_queue<Job,vector<Job>, waitingCompare> waitingQueue;
        priority_queue<Job, vector<Job>, processCompare> processQueue;
        int processTime = 0;
        Job workingJob{};
        for (int i = 0; i < jobs.size(); i++) {
            waitingQueue.push(Job(i,jobs[i]));
        }
        while (processQueue.size() > 0 || waitingQueue.size()>0) {
            while (waitingQueue.size()>0 && waitingQueue.top().AddTime <= processTime) {
                processQueue.push(waitingQueue.top());
                waitingQueue.pop();
            }
            if (workingJob.EndTime <= processTime) {
                answer += workingJob.WorkingTIme;
                if (processQueue.size() > 0) {
                    workingJob = processQueue.top();
                    processQueue.pop();
                    workingJob.EndTime = processTime + workingJob.WorkTime;
                    workingJob.WorkingTIme = workingJob.EndTime - workingJob.AddTime;
                    processTime = workingJob.EndTime;
                    if (processQueue.size() == 0 && waitingQueue.size() == 0) {
                        answer += workingJob.WorkingTIme;
                    }
                    continue;
                }
                else {
                    workingJob.WorkingTIme = 0;
                }
            }
            processTime = waitingQueue.top().AddTime;
        }
        answer /= jobs.size();
        return answer;
    }
}