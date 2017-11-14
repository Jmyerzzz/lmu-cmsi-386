#include <iostream>
#include <cassert>
#include <string>

using namespace std;

struct Adder {
private:
  std::string final_string = "";
public:
  Adder(std::string s = ""): final_string(s) {}

  Adder operator()(std::string value) {
    return Adder(final_string + value);
  }

  std::string operator()() {
    return final_string;
  }
};

Adder f;

int main() {
  assert(f() == "");
  assert(f("hi")("there")() == "hi there");
  assert(f("hi")("there")("billy")("bob")() == "hi there billy bob");
  cout << "All tests passed!\n";
}


// #define O(P)operator()(P){return{P+a};}int
// struct F{F O(int(m))O()a;}f;
