/*
Author: Rodolfo Reynoso
Name: Code Generator
Purpose: This program will generate random codes based on consonants and numbers 1-9   
*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

string getCode(char codeChoices[], int lengthOfCode);

bool checkSubString(string code, char first, char second, char third);

//Pre: Takes in the string length as an integer
//Returns random code


int main(int argc, char const *argv[]) {
    
    srand(time(NULL));

    string code;

    ofstream myfile ("sample.txt");
    ifstream codeReader ("sample.txt");

    int lengthOfCode = 0;
    char codeChoices[29] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 
                             'a' , 'b' , 'c', 'd', 'f', 'g', 'h', 'j', 'k',
                             'l', 'm', 'n', 'p', 'q', 'r', 's', 't' ,'v', 'w', 'x' };


    cout << "What length should the code be?: " ;
    cin  >> lengthOfCode;


    if (myfile.is_open()) {
        for (int i = 1; i <= 20000000; i++) {  //20 million
            
            code = getCode(codeChoices, lengthOfCode);

            // myfile << code << endl;

            if (checkSubString(code, 'b', 'c', 'd')) {

	            myfile << code << endl;

            } else {    

                i--;
            }
        }
    }

    myfile.close();
    return 0;
}   


string getCode(char codeChoices[], int lengthOfCode) {

    string code = "";

    for (int i = 0; i < lengthOfCode; i++) {
        
        code += codeChoices[rand() % 29];
    }
    return code;
}

bool checkSubString(string code, char first, char second, char third) {

    bool checkValue = true;

    for (int i = 0; i < code.length(); i++) {

        if ( (first == code[i]) && (second == code[i+1]) && (third == code[i+2])  ) {

            checkValue = false;
            break;
        }
    }

    return checkValue;
}




