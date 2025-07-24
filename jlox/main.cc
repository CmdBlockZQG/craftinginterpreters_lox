#include <iostream>
#include <fstream>
#include <sstream>

#include "Lox.h"

static Lox lox;

static void run_file(const std::string& path) {
  std::ifstream file(path);
  if (!file) {
    std::cerr << "Could not open file: " << path << std::endl;
    return;
  }
  std::stringstream buffer;
  buffer << file.rdbuf();
  lox.run(buffer.str());
}

static void run_prompt() {
  std::string line;
  while (true) {
    std::cout << "> ";
    if (!std::getline(std::cin, line)) {
      break;
    }
    lox.run(line);
  }
}

int main(int argc, char *argv[]) {
  if (argc > 2) {
    std::cout << "Usage: jlox [script]" << std::endl;
    return 1;
  }

  if (argc == 2) {
    run_file(argv[1]);
  } else {
    run_prompt();
  }

  return 0;
}
