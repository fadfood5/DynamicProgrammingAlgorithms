#include <iostream>
#include <fstream>
// #include <time.h>
// #include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "RobotStack.cpp"
using namespace std;

int main(int argc, char *argv[]){
	char x;
	if(argc != 3)
		cout << "File input error" << endl;
	else{
		ifstream file;
		file.open(argv[1]);
		if (!file) {
		    cerr << "Unable to open file.";
		    exit(1);   // call system to stop
		}else{
		    string str;
		    bool first = true;
		    int n;
		    while (getline(file, str)){
		    	if(first){
		    		n = stoi(str);
		    		first = false;
		    	}else{
		    		char temp[3];
		    		int index = 0;
		    		for(int i=0; i<str.length(); i++){
		    			if(str[i] != ',' && str[i] != ' '){
		    				temp[index] = str[i];
		    				index++;
		    			}
		    		}
		    		RobotStack robot;
		    		robot.b = temp[0];
		    		robot.n = temp[1];
		    		robot.k = temp[2];
		    		robot.printValues();
		    	}
		    }
			file.close();
		}
	}
	return 0;
}