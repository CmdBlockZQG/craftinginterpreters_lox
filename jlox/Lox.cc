#include "Lox.h"

#include <iostream>
#include <sstream>
#include <vector>

void Lox::run(const std::string& source) {
  std::stringstream ss(source);
  std::vector<std::string> tokens;

  for (std::string token; ss >> token; ) {
    tokens.push_back(token);
  }

  for (const auto& token : tokens) {
    std::cout << token << std::endl;
  }
}
