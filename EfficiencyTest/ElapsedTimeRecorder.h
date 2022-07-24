#ifndef ELAPSED_TIME_RECORDER
#define ELAPSED_TIME_RECORDER

#include <iostream>
#include <string>
#include <chrono>

// recording elapsed CPU time
// for efficiency test
class ElapsedTimeRecorder
{
public:
    ElapsedTimeRecorder(const std::string& str = "default") : name(str), begin(std::chrono::high_resolution_clock::now()), last(begin)
    {
    }
    ~ElapsedTimeRecorder()
    {
        // std::cout << "Destruction of recorder " << name << ", existing time: " << getTotalElapsedTimeInMs() << " ms" << std::endl;
    }
    void reset()
    {
        last = std::chrono::high_resolution_clock::now();
    }
    void showElapsedTimeInUs()
    {
        std::cout << "Elapsed time: " << getElapsedTimeInUs() << " us" << std::endl;
    }
    void showElapsedTimeInMs()
    {
        std::cout << "Elapsed time: " << getElapsedTimeInMs() << " ms" << std::endl;
    }
    void showElapsedTimeInSecond()
    {
        std::cout << "Elapsed time: " << getElapsedTimeInSecond() << " s" << std::endl;
    }
    double getElapsedTimeInUs()
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - last).count() / 1.0e3;
    }
    double getElapsedTimeInMs()
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - last).count() / 1.0e6;
    }
    double getElapsedTimeInSecond()
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - last).count() / 1.0e9;
    }
    double getTotalElapsedTimeInUs()
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - begin).count() / 1.0e3;
    }
    double getTotalElapsedTimeInMs()
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - begin).count() / 1.0e6;
    }
    double getTotalElapsedTimeInSecond()
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - begin).count() / 1.0e9;
    }
private:
    std::string name;
    std::chrono::high_resolution_clock::time_point begin;
    std::chrono::high_resolution_clock::time_point last;
};

#endif