#include <iostream>
#include <vector>
#include <deque>

struct Job {
	char type; // Job Type: 'A', 'B', 'C', 'D'
	int arrivalTime; // Arrival time
	int processingTime; // Total processing time
	int remainingTime; // Remaining processing time
	int overallJobNumber; // Sequential number across all jobs
	int jobTypeNumber; // Sequential number within job type
	int priority; // Priority level
	int startTime; // Time when job starts processing
	int queueEnterTime; // Time when job enters the queue
	int queueLeaveTime; // Time when job leaves the queue
	bool isInterrupted; // Flag to indicate if job was interrupted
};
struct Processor {
	bool isBusy = false;
	Job currentJob;
	int runTime = 0; // Time processor has been running current job
	int idleTime = 0; // Time processor has been idle
};
struct Metrics {
	int totalJobsProcessed = 0;
	int totalWaitTime = 0;
	int totalProcessingTime = 0;
	int totalInterruptions = 0;
	int maxQueueLength = 0;
	int totalQueueLength = 0;
	int timeUnits = 0;
	std::vector<int> processorBusyTime;
	std::vector<int> processorIdleTime;
	// Job counts per type
	int totalJobsArrived_A = 0;
	int totalJobsCompleted_A = 0;
	int totalJobsArrived_B = 0;
	int totalJobsCompleted_B = 0;
	int totalJobsArrived_C = 0;
	int totalJobsCompleted_C = 0;
	int totalJobsArrived_D = 0;
	int totalJobsCompleted_D = 0;
};
void generateJobs();
void writeJobsToFile();
void readJobData();
void initializeProcessors();
void processCompletedJobs();
void handleJobArrivals();
void assignJobsFromQueue();
void updateMetrics();
void displayMetrics();
int main() {
	// Ask user for the number of processors to be used
	/*
	... write your code
	*/
	// Initialize simulation data
	std::deque<Job> jobQueue;
	int currentTime = 0;
	const int simulationEndTime = 10000;
	const int initialMetricsTime = 500;
	size_t jobIndex = 0;
	// Simulation loop
	while (currentTime <= simulationEndTime) {
		/*
		... write your code
		*/
		currentTime++;
	}
	/*
	... write your code
	*/
	return 0;
}