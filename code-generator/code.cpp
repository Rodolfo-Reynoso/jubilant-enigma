/*
Author: Rodolfo Reynoso
Name: Code Generator
Purpose: This program will generate random codes based on consonants and numbers 1-9   
*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>


std::string getCode(char codeChoices[], int lengthOfCode);

bool checkSubString(std::string code, char first, char second, char third);

//Pre: Takes in the string length as an integer
//Returns random code


int main(int argc, char const *argv[]) {
    
    srand(time(NULL));

    std::string code;

    std::ofstream myfile ("sample.csv");
    std::ifstream codeReader ("sample.csv");

    int lengthOfCode = 0;
    char codeChoices[27] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 
                             'B' , 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'M',
                              'N', 'P', 'Q', 'R', 'S', 'T' ,'V', 'W', 'X' };


    std::cout << "What length should the code be?: " ;
    std::cin  >> lengthOfCode;


    if (myfile.is_open()) {
        for (int i = 1; i <= 150; i++) { //150 codes
            
            do {
               
                code = getCode(codeChoices, lengthOfCode);

            } 
            while ( checkSubString(code, 'w', 't', 'f') || checkSubString(code, 'k', 'm', 's') );

            myfile << code << std::endl;
        }
    }

    myfile.close();
    return 0;
}   


std::string getCode(char codeChoices[], int lengthOfCode) {

    std::string code = "";

    for (int i = 0; i < lengthOfCode; i++) {
        
        code += codeChoices[rand() % 27];
    }
    return code;
}

bool checkSubString(std::string code, char first, char second, char third) {

    bool checkValue = false;

    for (int i = 0; i < code.length(); i++) {

        if ( (first == code[i]) && (second == code[i+1]) && (third == code[i+2])  ) {

            checkValue = true;
            break;
        }
    }

    return checkValue;
}




