#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#include <vector>
#include <fstream>
#include <tuple>
#include <bits/stdc++.h>
#include <chrono>

#include "node.hpp"

class Utils{
    public :
        std::tuple<std::vector<double>, std::vector<double>, std::vector<double>, std::vector<double>, std::vector<double>, std::vector<double>> read_points(std::string FilePath, std::ifstream &inFile);
        std::vector<Node*> readFile(std::string FilePath);
        void retrieve(std::vector<Node*> out);
        void startRecordTime();
        void stopRecordTime();
        double showTime();
    private:
        std::chrono::high_resolution_clock::time_point start_;
        std::chrono::high_resolution_clock::time_point stop_;
        double total_time_;
};

#endif // UTILS_HPP_INCLUDED
