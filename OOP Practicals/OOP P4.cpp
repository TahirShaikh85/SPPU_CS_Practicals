#include <fstream>
#include <iostream>
using namespace std;

int main() {
  // Create an output file stream and open the file "output.txt" for writing
  ofstream out("output.txt");

  // Write some information to the file
  out << "This is a line of text" << endl;
  out << "This is another line of text" << endl;

  // Close the output file stream
  out.close();

  // Create an input file stream and open the file "output.txt" for reading
  ifstream in("output.txt");

  // Read the information from the file and print it to the console
  string line;
  while (getline(in, line)) {
    cout << line << endl;
  }

  // Close the input file stream
  in.close();

  return 0;
}

