#include<iostream>
#include<vector>
#include<stdexcept>
#include <bits/stdc++.h>

#include "utils.hpp"
#include "node.hpp"

std::tuple<std::vector<double>, std::vector<double>, std::vector<double>, std::vector<double>, std::vector<double>, std::vector<double>> Utils::read_points(std::string FilePath,std::ifstream &inFile)
{
    double col1, col2, col3, col4, col5, col6;
    std::vector<double> x, y, x_end, y_end, wl_, wr_;

    if (!inFile) {
        std::cerr << "Unable to open file "<<FilePath;
        exit(1);   // call system to stop
    }

    while(inFile >> col1 >> col2 >> col3 >> col4 >> col5 >> col6)
    {
        x.push_back(col1);
        y.push_back(col2);
        x_end.push_back(col3);
        y_end.push_back(col4);
        wl_.push_back(col5);
        wr_.push_back(col6);
    }

    inFile.close();

    return std::make_tuple(x, y, x_end, y_end, wl_, wr_);
}


std::vector<Node*> Utils::readFile(std::string FilePath){
    std::vector<Node*> input;
    std::vector<double> x, y, x_end, y_end, wl_, wr_;
    //std::string FilePath = "./geo_data/red_points.txt";

    std::ifstream InputFile(FilePath.c_str());
    std::tie(x, y, x_end, y_end, wl_, wr_) = read_points(FilePath,InputFile);

    ///std::cout << "Tamanho size -> " << FilePath;
    int input_size = x.size();

    for(int i = 0; i < input_size; ++i)
    {
        Node* temp = new Node(x[i],y[i],x_end[i],y_end[i],wl_[i],wr_[i],nullptr, nullptr,0);
        input.push_back(temp);
    }

    return input;
}

void Utils::retrieve(std::vector<Node*> out){
    if(out.size() == 0){
        throw std::invalid_argument("Not enough points to read");
    }

    std::cout << "{\n";
    for(int x=0; x < out.size(); ++x) {
        std::cout << "   [(" << out[x]->xb_ << "," << out[x]->yb_ << ")";
        std::cout << ",("<< out[x]->xe_ << "," << out[x]->ye_ << ")]\n";
    }
    std::cout << "}\n";
}

void Utils::startRecordTime(){
    start_ = std::chrono::high_resolution_clock::now();
}
void Utils::stopRecordTime(){
    stop_ = std::chrono::high_resolution_clock::now();
}
double Utils::showTime(){
    auto aux = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_ - start_).count();
    return aux/1e9;
}
