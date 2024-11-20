#ifndef HANDLEPROCESSORS_H
#define HANDLEPROCESSORS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <filesystem>

namespace fs = std::filesystem;

struct Job {
    char type;              // Job Type: 'A', 'B', 'C', 'D'
    int arrivalTime;        // Cumulative Arrival Time
    int processingTime = 0;     // Processing Time
    int remainingTime;      // Remaining Processing Time
    int overallJobNumber;   // Sequential number across all jobs
    int jobTypeNumber;      // Sequential number within job type
    int priority;           // Priority level (Higher number = higher priority)
    int startTime;          // Time when job starts processing
    int queueEnterTime;     // Time when job enters the queue
    int queueLeaveTime;     // Time when job leaves the queue
    bool isInterrupted;     // Flag to indicate if job was interrupted

    Job() : remainingTime(0), overallJobNumber(0), jobTypeNumber(0), priority(1),
        startTime(-1), queueEnterTime(-1), queueLeaveTime(-1), isInterrupted(false) {
    }
};

struct Processor {
    bool isBusy = false;
    Job currentJob;
    int runTime = 0;   // Time processor has been running current job
    int idleTime = 0;  // Time processor has been idle
};

// Struct to hold Metrics
struct Metrics {
    int numberOfProcessors = 0;
    int currentQueueSize = 0;
    double averageQueueSize = 0.0;
    int maxQueueLength = 0;
    long long totalTimeJobsInQueue = 0; // Using long long to prevent overflow
    double averageTimeJobsInQueue = 0.0;
    int totalJobsArrived_A = 0;
    int totalJobsCompleted_A = 0;
    int totalJobsArrived_B = 0;
    int totalJobsCompleted_B = 0;
    int totalJobsArrived_C = 0;
    int totalJobsCompleted_C = 0;
    int totalJobsArrived_D = 0;
    int totalJobsCompleted_D = 0;
    int totalJobsCompleted = 0;
    long long totalProcessingTime = 0; // Using long long to prevent overflow
    long long totalIdleTime = 0;       // Using long long to prevent overflow
};

struct CompareJob {
    bool operator()(const Job& a, const Job& b) {
        if (a.priority == b.priority) {
            // If priorities are equal, earlier arrival time has higher priority
            return a.arrivalTime > b.arrivalTime;  // FIFO for equal priority
        }
        return a.priority < b.priority;  // Higher priority jobs are processed first
    }
};

void generateJobs(const std::string&);
Metrics simulateJobs(int, const std::string&, const std::string&);
bool fileExists(const std::string&);

// Custom Queue to maintain job priorities using heap for better performance
template <typename T>
class CustomQueue {
private:
    std::vector<T> container;  // Internal container (using vector)

public:
    // Push an element to the queue
    void push(const T& value) {
        container.push_back(value);
        // Maintain the highest priority job at the front
        std::push_heap(container.begin(), container.end(), CompareJob()); // Using heap to maintain order
    }

    // Pop the front element
    void pop() {
        if (!container.empty()) {
            std::pop_heap(container.begin(), container.end(), CompareJob());
            container.pop_back();
        }
    }

    // Get the front element (highest priority)
    T top() const {
        if (!container.empty()) {
            return container.front();
        }
        throw std::runtime_error("Queue is empty");
    }

    // Check if the queue is empty
    bool empty() const {
        return container.empty();
    }

    // Get the current size of the queue
    size_t size() const {
        return container.size();
    }
};

#endif // HANDLEPROCESSORS_H
