#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	map<string,int>state_population;
	
	state_population["MAHARSHTRA"] = 23232323;
	state_population["NAGALAND"] = 28995881;
  	state_population["SIKKIM"] = 21477737;
  	state_population["KASHMIR"] = 19862512;
  	state_population["KERALA"] = 12801989;
  	
  	cout<<"Enter a state name: ";
  	string state;
  	cin>>state;
  	
  	map<string,int>::iterator it = state_population.find(state);
  	if(it != state_population.end()){
  		cout<<"The population of the state is: "<<it->second<<endl;
	  }
	  else{
	  	cout<<"NOT FOUND";
	  }
	return 0;
}
