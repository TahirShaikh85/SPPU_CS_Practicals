#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
	map<string,int> state_populations;
	
	// insert some key-value pairs into the map
	state_populations["MAHARASHTRA"] = 39557045;
  	state_populations["NAGALAND"] = 28995881;
  	state_populations["SIKKIM"] = 21477737;
  	state_populations["KASHMIR"] = 19862512;
  	state_populations["KERALA"] = 12801989;
  	
  	// prompt user for state name
  	cout<<"Enter a state name: ";
  	string state;
  	cin>>state;
  	
  	// look up the population of the state
  	map<string,int>::iterator it = state_populations.find(state);
  	if(it != state_populations.end()){
  		cout<<"The population of "<<state<<" is "<<it->second<<endl;
  		
	  }
	  else{
	  	cout<<"Sorry, i couldn't find the population of the state"
	  }
}
