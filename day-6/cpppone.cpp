#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>
#include <cmath>
#include <set>

std::vector<std::string> readfile(){
  std::ifstream inputdata ("./input.txt");
  std::string linedata;
  std::vector<std::string> data;
  if (inputdata.is_open()) {
    while (inputdata) {
      std::getline(inputdata, linedata);
      data.push_back(linedata);
    }
  }
  return data;
};

int find_marker(std::string message) {
  std::string check_string;
  std::set<char> check_uniques;
  for (int i = 0; i < message.size(); i++) {
    if (i > 3) {
      check_string = message.substr(i-4, 4);
      check_uniques.clear();
      for (char i: check_string) {
        check_uniques.insert(i);
      };
      // std::cout << "the check string is: " << check_string << '\n';
      // std::cout << "the uniques length is: " << check_uniques.size() << '\n';
      if (check_string.size() == check_uniques.size()) {
        return i;
      };
    };
  };
  return 0;
};


int main (int argc, char *argv[])
{
  // std::string data = "nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg";
  std::string data = readfile()[0];
  std::cout << "the marker is: " << find_marker(data);
  return 0;
}
