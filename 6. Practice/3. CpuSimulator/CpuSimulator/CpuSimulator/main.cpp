#include <iostream>
#include <vector>

struct Job {
	char type = 0; // Job Type: 'A', 'B', 'C', 'D'
	int arrivalTime = 0; // Arrival time
	int processingTime = 0; // Total processing time
	int remainingTime = 0; // Remaining processing time
	int overallJobNumber = 0; // Sequential number across all jobs
	int jobTypeNumber = 0; // Sequential number within job type
	int priority = 0; // Priority level
	int startTime = 0; // Time when job starts processing
	int queueEnterTime = 0; // Time when job enters the queue
	int queueLeaveTime = 0; // Time when job leaves the queue
	bool isInterrupted = 0; // Flag to indicate if job was interrupted
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
struct Node {
	Job job;
	int priority;
	Node* next;

	Node(Job j, int p) : job(j), priority(p), next(nullptr) {}
};

class PriorityQueue {
private:
	Node* head;

public:
	PriorityQueue() : head(nullptr){}

	bool isEmpty() {
		return !head;
	}

	void enqueue(Job& jobToAdd) {
		Node* node = new Node(jobToAdd, jobToAdd.priority);
		if (!head || node->job.priority < head->job.priority) {
			node->next = head;
			head = node;
		}
		else {
			Node* current = head;
			while (current->next && current->next->job.arrivalTime <= node->job.arrivalTime) {
				current = current->next;
			}
			node->next = current->next;
			current->next = node;
		}
		
	}
	void display(int& testNum) {
		Node* current = head;
		while (current) {
			std::cout << current->job.type << "|" << current->job.arrivalTime << std::endl;
			current = current->next;
			testNum++;
		}
		std::cout << testNum;
	}
};
void generateJobs(std::vector<Job>& jobs) {

	srand(time(0));
	int overallJobs = 0;
	int numA = 0;
	int numB = 0;
	int numC = 0;
	int numD = 0;
	int arrivalA = 0;
	int arrivalB = 0;
	int arrivalC = 0;
	int arrivalD = 0;
	bool jobRun = false;

	while (true) {
		Job job;
		job.type = 'A' + rand() % 4;
		if (job.type == 'A' && numA < 2400) {
			job.arrivalTime = arrivalA + 4 + rand() % 3;
			job.processingTime = 1 + rand() % 5;
			job.remainingTime = job.processingTime;
			job.priority = 1;
			job.jobTypeNumber = ++numA;

			arrivalA = job.arrivalTime;
			jobRun = true;
		}
		if (job.type == 'B' && numB < 1650) {
			job.arrivalTime = arrivalB + 6 + rand() % 3;
			job.processingTime = 2 + rand() % 7;
			job.remainingTime = job.processingTime;
			job.priority = 1;
			job.jobTypeNumber = ++numB;

			arrivalB = job.arrivalTime;
			jobRun = true;
		}
		if (job.type == 'C' && numC < 1100) {
			job.arrivalTime = arrivalC + 4 + rand() % 15;
			job.processingTime = 6 + rand() % 7;
			job.remainingTime = job.processingTime;
			job.priority = 1;
			job.jobTypeNumber = ++numC;

			arrivalC = job.arrivalTime;
			jobRun = true;
		}
		if (job.type == 'D' && numD < 1200) {
			job.arrivalTime = arrivalD + 4 + rand() % 11;
			job.processingTime = 2 + rand() % 21;
			job.remainingTime = job.processingTime;
			job.priority = 2;
			job.jobTypeNumber = ++numD;

			arrivalD = job.arrivalTime;
			jobRun = true;
		}
		if (jobRun) {
			job.overallJobNumber = ++overallJobs;
			jobs.push_back(job);
			jobRun = false;
		}
		if (numA + numB + numC + numD == 2400 + 1650 + 1100 + 1200) {
			break;
		}
		
	}
};
void writeJobsToFile();
void readJobData();
void initializeProcessors();
void processCompletedJobs();
void handleJobArrivals(std::vector<Job> jobs, PriorityQueue& myQueue) {
	for (auto job : jobs) {
		myQueue.enqueue(job);
	}
};
void assignJobsFromQueue();
void updateMetrics();
void displayMetrics();
int main() {
	// Ask user for the number of processors to be used
	/*
	... write your code
	*/
	// Initialize simulation data
	std::vector<Job> jobs;
	PriorityQueue myQueue;
	generateJobs(jobs);
	handleJobArrivals(jobs, myQueue);
	int testNum = 0;
	myQueue.display(testNum);
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
