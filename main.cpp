#include <iostream>
#include <fstream>
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
		    exit(1);
		}else{
		    int n;
		    file >> n;
		    cout << "There are " << n << " instances." << endl;
    		RobotStack robot;
		    while (file >> robot.b >> robot.n >> robot.k){
	    		robot.printValues();
	    		robot.dyn();
    			cout << endl;
		    }
		}
		file.close();
		cout << "Done." << endl;
	}
	return 0;
}