#include "handleprocessors.h"

int main() {
    const std::string jobDataFile = "job_data.txt";

    if (!fileExists(jobDataFile)) {
        std::cout << "Job data file not found. Generating job data...\n";
        generateJobs(jobDataFile);
        std::cout << "Job data generated and written to " << jobDataFile << " successfully.\n\n";
    }
    else {
        std::cout << "Job data file found (" << jobDataFile << "). Using existing data.\n\n";
    }

    const int minProcessors = 1, maxProcessors = 8;
    std::vector<Metrics> allMetrics;

    std::ofstream metricsTable("metrics_table.txt");
    if (!metricsTable) return 1;

    metricsTable << std::left
        << std::setw(12) << "Processors"
        << std::setw(15) << "AvgQueueSize"
        << std::setw(17) << "MaxQueueLength"
        << std::setw(20) << "AvgJobWaitTime"
        << std::setw(22) << "TotalProcessingTime"
        << std::setw(15) << "TotalIdleTime" << "\n";

    metricsTable << std::left
        << std::setw(12) << "----------"
        << std::setw(15) << "------------"
        << std::setw(17) << "--------------"
        << std::setw(20) << "------------------"
        << std::setw(22) << "-------------------"
        << std::setw(15) << "------------" << "\n";

    for (int p = minProcessors; p <= maxProcessors; ++p) {
        std::cout << "Running simulation with " << p << " processor(s)...\n";
        std::string logFile = "simulation_log_" + std::to_string(p) + ".txt";
        Metrics metrics = simulateJobs(p, jobDataFile, logFile);
        allMetrics.push_back(metrics);

        metricsTable << std::left
            << std::setw(12) << p
            << std::setw(15) << std::fixed << std::setprecision(2) << metrics.averageQueueSize
            << std::setw(17) << metrics.maxQueueLength
            << std::setw(20) << metrics.averageTimeJobsInQueue
            << std::setw(22) << metrics.totalProcessingTime
            << std::setw(15) << metrics.totalIdleTime << "\n";

        std::cout << "Simulation with " << p << " processor(s) completed. Metrics recorded.\n\n";
    }

    metricsTable.close();

    std::cout << "All simulations completed. Metrics compiled in metrics_table.txt.\n";

    std::ifstream metricsInput("metrics_table.txt");
    if (metricsInput) {
        std::cout << "\n--- Metrics Table ---\n";
        std::string line;
        while (std::getline(metricsInput, line)) {
            std::cout << line << "\n";
        }
    }
    else {
        std::cerr << "Error reading metrics_table.txt.\n";
    }

    return 0;
}
