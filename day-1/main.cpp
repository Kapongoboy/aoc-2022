#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

std::vector<std::string> readfile(){
  std::ifstream inputdata ("./input.txt");
  std::string linedata;
  std::vector<std::string> calories;
  if (inputdata.is_open()) {
    while (inputdata) {
      std::getline(inputdata, linedata);
      calories.push_back(linedata);
    }
  }
  return calories;
};

std::vector<int> sumcalories(std::vector<std::string> args){
  std::vector<int> summed;
  int sumbuf = 0;
  for (auto i: args) {
    try {
      sumbuf += std::stoi(i);
    } catch(std::invalid_argument) {
      summed.push_back(sumbuf);
      sumbuf = 0;
      continue;
    }
  }
  return summed;
}

std::tuple<int, int> maxelf(std::vector<int> data, int topthree=0, int topone=0) {
  std::vector<int>::iterator highest;
  for (int i = 0; i < 3; i++) {
    highest = std::max_element(data.begin(), data.end());
    if (i == 0) {
      topone += *highest;
    }
    topthree += *highest;
    data.erase(std::remove(data.begin(), data.end(), *highest), data.end());
  }
  return std::make_tuple(topthree, topone);
}

int main (int argc, char *argv[])
{
  std::vector<std::string> elfcalories = readfile();
  std::vector<int> elfindividuals = sumcalories(elfcalories);
  int mostcalories, topthreecalories;
  std::tie(topthreecalories, mostcalories) = maxelf(elfindividuals);
  std::cout << "top three total = " << topthreecalories << ", top individual calories = " << mostcalories << std::endl; 
  return 0;
}
