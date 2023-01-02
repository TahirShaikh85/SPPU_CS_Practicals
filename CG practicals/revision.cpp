#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct PersonalRecord {
  string name;
  string dob;
  string phone;
};

// Function for comparing two records by name
bool compareByName(const PersonalRecord &a, const PersonalRecord &b) {
  return a.name < b.name;
}

// Function for comparing two records by date of birth
bool compareByDOB(const PersonalRecord &a, const PersonalRecord &b) {
  return a.dob < b.dob;
}

// Function for comparing two records by phone number
bool compareByPhone(const PersonalRecord &a, const PersonalRecord &b) {
  return a.phone < b.phone;
}

int main() {
  // Create a vector of personal records
  vector<PersonalRecord> records;

  // Add some records to the vector // mm-dd-yyyy
  records.push_back({"Tahir Shaikh", "02/03/2003", "123-456-7890"});
  records.push_back({"Tony Stark", "03/20/1998", "234-567-8901"});
  records.push_back({"Ashish Kandekar", "07/04/1997", "345-678-9012"});
  records.push_back({"Abhishekh Varpe", "12/25/1999", "456-789-0123"});
  records.push_back({"Aditya Waghmare", "01/01/2000", "456-789-0123"});
  
  // Sort the records by name
  sort(records.begin(), records.end(), compareByName);

  // Print the records
  cout << "Records sorted by name:" << endl;
  for (vector<PersonalRecord>::const_iterator it = records.begin(); it != records.end(); ++it) {
    cout << it->name << " " << it->dob << " " << it->phone << endl;
  }

  // Sort the records by date of birth
  sort(records.begin(), records.end(), compareByDOB);

  // Print the records
  cout << "\nRecords sorted by date of birth:" << endl;
  for (vector<PersonalRecord>::const_iterator it = records.begin(); it != records.end(); ++it) {
    cout << it->name << " " << it->dob << " " << it->phone << endl;
  }

  // Sort the records by phone number
  sort(records.begin(), records.end(), compareByPhone);

  // Print the records
  cout << "\nRecords sorted by phone number:" << endl;
  for (vector<PersonalRecord>::const_iterator it = records.begin(); it != records.end(); ++it) {
    cout << it->name << " " << it->dob << " " << it->phone << endl;
  }

  return 0;
}

