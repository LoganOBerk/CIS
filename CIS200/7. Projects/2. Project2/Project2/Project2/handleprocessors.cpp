#include "handleprocessors.h"
#include <iostream> // Added for logging

void generateJobs(const std::string& filename) {
    // Initialize random number generator with current time as seed
    std::mt19937 rng(static_cast<unsigned int>(time(0)));

    // Define job types and their characteristics
    struct JobType {
        char type;
        int baseArrival;
        int arrivalVar;
        int baseProcessing;
        int processingVar;
        int quantity;
        int priority;
    };

    std::vector<JobType> jobTypes = {
        {'A', 5, 1, 3, 2, 2400, 1},
        {'B', 7, 1, 5, 3, 1650, 1},
        {'C', 11, 7, 9, 3, 1100, 1},
        {'D', 9, 5, 12, 10, 1200, 2} // Highest priority
    };

    std::vector<Job> allJobs;
    int overallJobCounter = 1;

    // Generate jobs for each type
    for (const auto& jt : jobTypes) {
        int currentTime = 0;
        for (int i = 1; i <= jt.quantity; ++i) {
            // Calculate arrival interval using X ± Y
            int arrivalInterval = jt.baseArrival - jt.arrivalVar + (rng() % (2 * jt.arrivalVar + 1));
            currentTime += std::max(arrivalInterval, 0); // Ensure non-negative arrival times

            // Calculate processing time using X ± Y
            int procTimeMin = std::max(jt.baseProcessing - jt.processingVar, 1);
            int procTimeMax = jt.baseProcessing + jt.processingVar;
            int processingTime = procTimeMin + (rng() % (procTimeMax - procTimeMin + 1));

            // Create Job
            Job job = {}; // Zero-initialize to avoid uninitialized data
            job.type = jt.type;
            job.arrivalTime = currentTime;
            job.processingTime = std::max(processingTime, 1); // Ensure processing time is at least 1
            job.remainingTime = job.processingTime;
            job.overallJobNumber = overallJobCounter++;
            job.jobTypeNumber = i;
            job.priority = jt.priority;

            allJobs.push_back(job);
        }
    }

    // Sort all jobs by arrival time
    std::sort(allJobs.begin(), allJobs.end(), [&](const Job& a, const Job& b) -> bool {
        if (a.arrivalTime == b.arrivalTime) {
            return a.priority > b.priority;
        }
        return a.arrivalTime < b.arrivalTime;
        });

    // Write to file with aligned columns
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening " << filename << " for writing.\n";
        exit(1);
    }

    // Define column widths
    const int widthType = 10;
    const int widthArrival = 15;
    const int widthProcessing = 20;

    // Write header with fixed-width columns
    outFile << std::left
        << std::setw(widthType) << "JobType"
        << std::setw(widthArrival) << "ArrivalTime"
        << std::setw(widthProcessing) << "ProcessingTime"
        << "\n";

    // Write a separator line
    outFile << std::left
        << std::setw(widthType) << "-------"
        << std::setw(widthArrival) << "-----------"
        << std::setw(widthProcessing) << "--------------"
        << "\n";

    // Write job data with aligned columns
    for (const auto& job : allJobs) {
        outFile << std::left
            << std::setw(widthType) << job.type
            << std::setw(widthArrival) << job.arrivalTime
            << std::setw(widthProcessing) << job.processingTime
            << "\n";
    }

    outFile.close();
}


Metrics simulateJobs(int numProcessors, const std::string& jobDataFile, const std::string& logFile) {
    Metrics metrics;
    metrics.numberOfProcessors = numProcessors;

    // Initialize processors
    std::vector<Processor> processors(numProcessors);

    // Read job data from file
    std::ifstream inFile(jobDataFile);
    if (!inFile) {
        std::cerr << "Error opening " << jobDataFile << " for reading.\n";
        exit(1);
    }

    std::string line;
    // Skip header
    std::getline(inFile, line);

    std::vector<Job> allJobs;
    int overallJobCounter = 1;
    std::unordered_map<char, int> typeCounters; // To track jobTypeNumber for each type

    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        Job job = {}; // Zero-initialize to avoid uninitialized data
        iss >> job.type >> job.arrivalTime >> job.processingTime;
        job.remainingTime = std::max(job.processingTime, 1); // Ensure remaining time is non-negative
        job.overallJobNumber = overallJobCounter++;

        // Assign jobTypeNumber based on type
        typeCounters[job.type]++;
        job.jobTypeNumber = typeCounters[job.type];

        // Assign priority
        job.priority = (job.type == 'D') ? 2 : 1;

        allJobs.push_back(job);

        // Increment arrived jobs count
        switch (job.type) {
        case 'A': metrics.totalJobsArrived_A++; break;
        case 'B': metrics.totalJobsArrived_B++; break;
        case 'C': metrics.totalJobsArrived_C++; break;
        case 'D': metrics.totalJobsArrived_D++; break;
        }
    }
    inFile.close();

    // Initialize custom queue for waiting jobs
    CustomQueue<Job> jobQueue;

    // Open log file
    std::ofstream logStream(logFile);
    if (!logStream) {
        std::cerr << "Error creating " << logFile << " for writing.\n";
        exit(1);
    }

    // Write log file header
    logStream << "----- Simulation Log -----\n";
    logStream << "Number of Processors: " << numProcessors << "\n\n";

    // Simulation parameters
    int currentTime = 0;
    const int simulationEndTime = 10000;
    size_t jobIndex = 0;

    // For average queue size calculation
    double cumulativeQueueSize = 0.0;

    // Metrics tracking
    int maxQueueLength = 0;  // Track maximum queue length
    double totalJobWaitTime = 0;  // Track total job wait time
    long long totalProcessingTime = 0;  // Track total processing time
    long long totalIdleTime = 0;  // Track total idle time

    // Simulation loop
    while (currentTime <= simulationEndTime) {
        // 1. Handle job completions
        for (size_t p = 0; p < processors.size(); ++p) {
            if (processors[p].isBusy) {
                Job& currentJob = processors[p].currentJob;

                // Check if the job completes at this time
                if ((currentTime - currentJob.startTime) >= currentJob.remainingTime) {
                    // Job completed
                    logStream << "Time " << currentTime << ": Complete Processing Job: "
                        << currentJob.overallJobNumber << ", Job " << currentJob.type
                        << ":" << currentJob.jobTypeNumber << ";\n";

                    // Update metrics
                    metrics.totalJobsCompleted++;
                    totalProcessingTime += currentJob.processingTime; // Add to total processing time

                    switch (currentJob.type) {
                    case 'A': metrics.totalJobsCompleted_A++; break;
                    case 'B': metrics.totalJobsCompleted_B++; break;
                    case 'C': metrics.totalJobsCompleted_C++; break;
                    case 'D': metrics.totalJobsCompleted_D++; break;
                    }

                    // Calculate job wait time (queue enter time to start time)
                    totalJobWaitTime += (currentTime - currentJob.queueEnterTime);

                    // Processor becomes idle
                    processors[p].isBusy = false;
                    processors[p].currentJob = Job(); // Clear the current job

                    // Assign next job from queue if available
                    if (!jobQueue.empty()) {
                        Job nextJob = jobQueue.top();
                        jobQueue.pop();
                        nextJob.queueLeaveTime = currentTime;
                        metrics.totalTimeJobsInQueue += (nextJob.queueLeaveTime - nextJob.queueEnterTime);

                        logStream << "Time " << currentTime << ":  Begin Processing Job: "
                            << nextJob.overallJobNumber << ", Job " << nextJob.type
                            << ":" << nextJob.jobTypeNumber << " in CPU " << (p + 1) << ";\n";

                        processors[p].isBusy = true;
                        processors[p].currentJob = nextJob;
                        processors[p].currentJob.startTime = currentTime;
                        processors[p].currentJob.isInterrupted = false;
                    }
                }
            }
        }

        // 2. Handle job arrivals at currentTime
        while (jobIndex < allJobs.size() && allJobs[jobIndex].arrivalTime == currentTime) {
            Job arrivingJob = allJobs[jobIndex];
            logStream << "Time " << currentTime << ": Arrival: Overall Job: "
                << arrivingJob.overallJobNumber << ", Job " << arrivingJob.type
                << ":" << arrivingJob.jobTypeNumber
                << ", Processing Time:" << arrivingJob.processingTime << ";\n";

            // Check for available processor
            bool assigned = false;
            for (size_t p = 0; p < processors.size(); ++p) {
                if (!processors[p].isBusy) {
                    // Assign job to processor
                    processors[p].isBusy = true;
                    processors[p].currentJob = arrivingJob;
                    processors[p].currentJob.startTime = currentTime;
                    processors[p].currentJob.isInterrupted = false;
                    logStream << "Time " << currentTime << ":  Begin Processing Job: "
                        << arrivingJob.overallJobNumber << ", Job " << arrivingJob.type
                        << ":" << arrivingJob.jobTypeNumber << " in CPU " << (p + 1) << ";\n";
                    assigned = true;
                    break;
                }
            }

            if (!assigned) {
                // If arriving job is highest priority (Type D), try to interrupt a lower priority job
                if (arrivingJob.priority == 2) {
                    bool interrupted = false;
                    for (size_t p = 0; p < processors.size(); ++p) {
                        if (processors[p].isBusy && processors[p].currentJob.priority < arrivingJob.priority) {
                            // Interrupt the current job
                            Job interruptedJob = processors[p].currentJob;
                            int elapsedTime = currentTime - interruptedJob.startTime;
                            interruptedJob.remainingTime -= elapsedTime;

                            // Ensure remainingTime is not negative
                            if (interruptedJob.remainingTime < 0) {
                                interruptedJob.remainingTime = 0;
                            }

                            interruptedJob.isInterrupted = true;
                            // Re-add to the queue with updated remaining time
                            interruptedJob.queueEnterTime = currentTime;
                            jobQueue.push(interruptedJob);
                            logStream << "Time " << currentTime << ":  Interrupting Job: "
                                << interruptedJob.overallJobNumber << ", Job " << interruptedJob.type
                                << ":" << interruptedJob.jobTypeNumber
                                << " from CPU " << (p + 1) << ";\n";

                            // Assign arriving high priority job to this processor
                            processors[p].currentJob = arrivingJob;
                            processors[p].currentJob.startTime = currentTime;
                            processors[p].currentJob.isInterrupted = false;
                            logStream << "Time " << currentTime << ":  Begin Processing Job: "
                                << arrivingJob.overallJobNumber << ", Job " << arrivingJob.type
                                << ":" << arrivingJob.jobTypeNumber
                                << " in CPU " << (p + 1) << ";\n";
                            interrupted = true;
                            break;
                        }
                    }
                    if (!interrupted) {
                        // No lower priority job to interrupt, add to queue
                        arrivingJob.queueEnterTime = currentTime;
                        jobQueue.push(arrivingJob);
                    }
                }
                else {
                    // Add to queue
                    arrivingJob.queueEnterTime = currentTime;
                    jobQueue.push(arrivingJob);
                }
            }

            // Track max queue length
            maxQueueLength = std::max(maxQueueLength, static_cast<int>(jobQueue.size()));
            jobIndex++;
        }

        // 3. Track queue size for average calculation
        cumulativeQueueSize += jobQueue.size();

        // 4. Track total idle time
        for (size_t p = 0; p < processors.size(); ++p) {
            if (!processors[p].isBusy) {
                totalIdleTime++;
            }
        }

        // Increment time
        currentTime++;
    }

    // Compute the average queue size
    metrics.averageQueueSize = cumulativeQueueSize / simulationEndTime;

    // Compute the average wait time per job
    if (metrics.totalJobsCompleted > 0) {
        metrics.averageTimeJobsInQueue = totalJobWaitTime / metrics.totalJobsCompleted;
    }

    // Set metrics for total processing time, total idle time, etc.
    metrics.totalProcessingTime = totalProcessingTime;
    metrics.totalIdleTime = totalIdleTime;
    metrics.maxQueueLength = maxQueueLength;

    return metrics;
}





bool fileExists(const std::string& filename) {
    return fs::exists(filename);
}
