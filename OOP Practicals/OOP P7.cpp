#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
  // Create a map of strings (states) to ints (populations)
  map<string, int> state_populations;

  // Insert some key-value pairs into the map
  state_populations["MAHARASHTRA"] = 39557045;
  state_populations["NAGALAND"] = 28995881;
  state_populations["SIKKIM"] = 21477737;
  state_populations["KASHMIR"] = 19862512;
  state_populations["KERALA"] = 12801989;

  // Prompt the user to enter a state name
  cout << "Enter a state name: ";
  string state;
  cin >> state;

  // Look up the population of the state
  
  map<string, int>::iterator it = state_populations.find(state);
  if (it != state_populations.end()) {
    cout << "The population of " << state << " is " << it->second <<endl;
  } else {
    cout << "Sorry, I couldn't find the population for that state." <<endl;
  }

  return 0;
}

