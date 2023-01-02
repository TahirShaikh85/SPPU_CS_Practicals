#include <iostream>
#include <string>

using namespace std;

class publication {
 protected:
  string title;
  float price;
};

class book : public publication {
 public:
  int pageCount;

  void getData() {
    try {
      cout << "Enter the title of the book: ";
      cin >> title;
      cout << "Enter the price of the book: ";
      cin >> price;
      cout << "Enter the page count of the book: ";
      cin >> pageCount;
    } catch (...) {
      title = "";
      price = 0.0;
      pageCount = 0;
      cout << "Exception caught. Data members set to zero values." << endl;
    }
  }

  void displayData() {
    cout << "Title: " << title << endl;
    cout << "Price: $" << price << endl;
    cout << "Page count: " << pageCount << endl;
  }
};

class tape : public publication {
 public:
  float playingTime;

  void getData() {
    try {
      cout << "Enter the title of the audio cassette: ";
      cin >> title;
      cout << "Enter the price of the audio cassette: ";
      cin >> price;
      cout << "Enter the playing time of the audio cassette (in minutes): ";
      cin >> playingTime;
    } catch (...) {
      title = "";
      price = 0.0;
      playingTime = 0.0;
      cout << "Exception caught. Data members set to zero values." << endl;
    }
  }

  void displayData() {
    cout << "Title:
	  cout << "Title: " << title << endl;
  cout << "Price: $" << price << endl;
  cout << "Playing time: " << playingTime << " minutes" << endl;
}
};

int main() {
  book b;
  cout << "Enter data for a book:" << endl;
  b.getData();
  cout << "\nBook data:" << endl;
  b.displayData();

  cout << "\nEnter data for an audio cassette:" << endl;
  tape t;
  t.getData();
  cout << "\nAudio cassette data:" << endl;
  t.displayData();

  return 0;
}

