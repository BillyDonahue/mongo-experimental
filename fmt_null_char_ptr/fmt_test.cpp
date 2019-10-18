
#include <iostream>
#include <fmt/format.h>

int main(){
      std::cout << fmt::format("{}", "hi") << "\n";
      std::cout << fmt::format("{}", (char*)nullptr) << "\n";
      // std::cout << fmt::format("{:s}", (const char*)"hello") << "\n";
}

