#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

int rowInput;
int colInput;
string flag;
//This function gets which of the flags the user wants to print out. Then checks that it is a valid choice 
string FlagType() {
    
    for (int check = 0; check < 1; check++) {
        cout << "Which Flag would you like to print out? ";
        cin >> flag;
    if (flag == "Italy" || flag == "italy" || flag == "Poland" || flag == "poland"
     || flag == "Finland" || flag == "finland" || flag == "France" || flag == "france"
     || flag == "Russia" || flag == "russia") {
        
        cout << "You Chose " << flag << "!\n";
        return(flag);
	}
    else{
	cout << "Sorry " << flag << " is not a valid choice\n";
	} check--;
    }
}
int drawItaly (){
    ofstream myfile;
    myfile.open("italy.ppm");
    myfile << "P3\n";
    myfile << colInput << " " << rowInput << endl;
    myfile << "255\n";
 for (int row = 0; row < rowInput; row++) {
    for (int col = 0; col < colInput; col++) {//Prints out based on columns after checking the rows or height that they want
        if (col < colInput / 3) {//says that anytime it is in the first third of the flag print the color green
            myfile << "0 255 0 ";
	}
	else if (col < 2 * colInput / 3) {//says that anytime it is in the second third of the flag print the second color which is white
            myfile << "255 255 255 ";
	}
	else {// anytime it does not fit the other constraints prints the final color red
            myfile << "255 0 0 ";
	}
    }
            cout << endl;
 } 
    myfile.close();
}

int drawFrance(){
    ofstream myfile;
    myfile.open("france.ppm");
    myfile << "P3\n";
    myfile << colInput << " " << rowInput << endl;
    myfile << "255\n";
    for (int row = 0; row < rowInput; row++) {//This loop is the same as the one for Italy
        for (int col = 0; col < colInput; col++) {
            if (col < colInput / 3) {//Prints out the first color blue
                myfile << "0 0 255 ";
            }
            else if (col < 2 * colInput / 3) {//Prints out the middle color white
		myfile << "255 255 255 ";
            }
            else {//Prints out the final color red
		myfile << "255 0 0 ";
            }
	}
                cout << endl;
    }
    myfile.close();
}

int drawRussia(){
    ofstream myfile;
    myfile.open("russia.ppm");
    myfile << "P3\n";
    myfile << colInput << " " << rowInput << endl;
    myfile << "255\n";
    for(int row = 0; row < rowInput; row++){
       for (int col =0; col < colInput; col++){
           if(row < rowInput/3){
               myfile << " 255 255 255 ";//prints the first third white
           }
           else if(row < 2*rowInput/3) {//prints the middle third blue
               myfile << "0 0 255 ";
           }
           else {
               myfile << "255 0 0 ";// prints the final third red
           }
       }
       cout << endl;
    }
    myfile.close();
}

int drawFinland(){
    ofstream myfile;
    myfile.open("finland.ppm");
    myfile << "P3\n";
    myfile << colInput << " " << rowInput << endl;
    myfile << "255\n";
    for (int row = 0; row < rowInput; row++) {
	for (int col = 0; col < colInput; col++){
           if (abs(row-(rowInput/2))<(rowInput/10) || abs(col-5*(colInput/12))<(colInput/12)) {
                myfile <<  "0 0 255 ";
            }
            else {
                myfile << "255 255 255 ";
            }    
		}
        cout << endl;
    }
    myfile.close();
}

int drawPoland(){
    ofstream myfile;
    myfile.open("poland.ppm");
    myfile << "P3\n";
    myfile << colInput << " " << rowInput << endl;
    myfile << "255\n";
    for (int row = 0; row < rowInput; row++) {   
        for (int col = 0; col < colInput; col++){
            if (row < rowInput / 2) {
                myfile <<  "255 255 255 ";
            }
            else {
                myfile << ("255 0 0 ");
            }
	}
                cout << endl;	
    }
    myfile.close();
}

//Grabs the dimensions from the user and then sees what flag they chose. The design is printed out from the loops set up
int Dimensions() {
	
	cout << "What is your width in the X direction? ";
	cin >> colInput;
	while (colInput <= 99 || colInput >= 1000) {
		cout << "Invalid value! Must be between 100 and 1000.\n";
		cout << "What is your width in the X direction? ";
		cin >> colInput;
	}
	cout << "What is your Height in the Y direction? ";
	cin >> rowInput;
        
	while (rowInput <= 99 || rowInput >= 1000) {
		cout << "Invalid value! Must be between 100 and 1000.\n";
		cout << "What is your Height in the Y direction? ";
		cin >> rowInput;
	}
	if (flag == "Italy" || flag == "italy") {//Runs the drawItaly function if they chose Italy
            drawItaly();
	}
        else if (flag == "Russia" || flag == "russia"){//Runs the drawRussia function if they chose Russia
            drawRussia();
        }
	else if (flag == "France" || flag == "france") {//Runs the drawFrance function if they chose France
            drawFrance();
	}
        else if (flag == "Poland" || flag == "poland"){//Runs the drawPoland function if they chose Poland
            drawPoland();
        }
        else if (flag == "Finland" || flag == "finland"){//Runs the drawFinland function if they chose Finland
            drawFinland();
        }
}
int main() {
    
	cout << "Welcome to the Flag Printing Program!\n";
	cout << "We have a limited amount of choices\n";
	cout << "Your Choices are Italy, Poland, Finland, France, and Russia.\n";
	FlagType();
	Dimensions();
        
        system("pause");/*This code is only to prevent the command prompt terminal 
        from closing to see the output at the end of the program*/
}


