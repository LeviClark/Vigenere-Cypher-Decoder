
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include <chrono>
#include <unordered_map>
#include "Cipher.h"

using namespace std::chrono;
using namespace std;

string WHITESPACE = " \n\r\t\f\v";

void printOptions() {
  cout << "\n\nPlease choose one of the following commands: \n";
  cout << "1 - Decrypt\n";
  cout << "2 - Exit\n\n";
}

void printPickText() {
  cout << "\n\nPlease choose one of the following ciphers to crack: \n";
  cout << "1: MSOKKJCOSXOEEKDTOSLGFWCMCHSUSGX" << endl;
  cout << "2: OOPCULNWFRCFQAQJGPNARMEYUODYOUNRGWORQEPVARCEPBBSCEQYEARAJUYGWWYACYWBPRNEJBMDTEAEYCCFJNENSGWAQRTSJTGXNRQRMDGFEEPHSJRGFCFMACCB" << endl;
  cout << "3: MTZHZEOQKASVBDOWMWMKMNYIIHVWPEXJA" << endl;
  cout << "4: HUETNMIXVTMQWZTQMMZUNZXNSSBLNSJVSJQDLKR" << endl;
  cout << "5: LDWMEKPOPSWNOAVBIDHIPCEWAETYRVOAUPSINOVDIEDHCDSELHCCPVHRPOHZUSERSFS" << endl;


}

string trim(string& s){
  size_t end = s.find_last_not_of(WHITESPACE);
  return (end == string::npos) ? "" : s.substr(0, end+1);
}

int main() {

  Cipher* myCipher = new Cipher();
  int action = 0;
  int cipherOption;
  printPickText();
  int keyLength, firstWordLength;
  string cipherText;
  cin >> cipherOption;
  if(cipherOption == 1){
    cipherText = "MSOKKJCOSXOEEKDTOSLGFWCMCHSUSGX";
    keyLength = 2;
    firstWordLength = 6;
  }
  else if(cipherOption == 2){
    cipherText = "OOPCULNWFRCFQAQJGPNARMEYUODYOUNRGWORQEPVARCEPBBSCEQYEARAJUYGWWYACYWBPRNEJBMDTEAEYCCFJNENSGWAQRTSJTGXNRQRMDGFEEPHSJRGFCFMACCB";

    keyLength = 3;
    firstWordLength = 7;
  }
  else if(cipherOption == 3){
    cipherText = "MTZHZEOQKASVBDOWMWMKMNYIIHVWPEXJA";
    keyLength = 4;
    firstWordLength = 10;
  }
  else if(cipherOption == 4){
    cipherText = "HUETNMIXVTMQWZTQMMZUNZXNSSBLNSJVSJQDLKR";
    keyLength = 5;
    firstWordLength = 11;
  }
  else if(cipherOption == 5){
    cipherText = "LDWMEKPOPSWNOAVBIDHIPCEWAETYRVOAUPSINOVDIEDHCDSELHCCPVHRPOHZUSERSFS";
    keyLength = 6;
    firstWordLength = 13;
  }

  cout << "DECIPHERING..." << endl;
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  vector<string> possibilities;
  vector<string> decipheredText;

  /////////////////////////// STORE DICT.TXT TO VECTOR FOR COMPARING///////////////////////////////
  ifstream infile("dict.txt");
  string line;
  unordered_map<string, int> myDictionary;

  //import in dict.txt and trim out whitespaces
  string stringToTrim;
  while(getline(infile, line)){

    stringToTrim = trim(line);
    myDictionary[stringToTrim] = line.length()-1;
  }

  //messy messy messy, clean this up if you get time
  if(keyLength > 6){
    cout << "SORRY, YOU'RE GOING TO CRASH YOUR COMPUTER, KEY LENGTH WOULD CONTAIN OVER 300 MILLION POSSIBILITIES" << endl;
  }
  else{
    for(int a = 0; a < 26; a++){
      for(int b = 0; b < 26; b++){ //size 2
        if(keyLength > 2){
          for(int c = 0; c < 26; c++){ //size 3
            if(keyLength > 3){
              for(int d = 0; d < 26; d++){ //size 4
                if(keyLength > 4){
                  for(int e = 0; e < 26; e++){ //size 5
                    if(keyLength > 5){
                      for(int f = 0; f < 26; f++){
                        string possibleKeyA, possibleKeyB, possibleKeyC, possibleKeyD, possibleKeyE, possibleKeyF, possibleKeyConcat;
                        possibleKeyA = alphabet[a];
                        possibleKeyB = alphabet[b];
                        possibleKeyC = alphabet[c];
                        possibleKeyD = alphabet[d];
                        possibleKeyE = alphabet[e];
                        possibleKeyF = alphabet[f];
                        possibleKeyConcat = possibleKeyA + possibleKeyB + possibleKeyC + possibleKeyD + possibleKeyE + possibleKeyF;
                        possibilities.push_back(possibleKeyConcat);
                      }
                    }
                    else{
                      string possibleKeyA, possibleKeyB, possibleKeyC, possibleKeyD, possibleKeyE, possibleKeyConcat;
                      possibleKeyA = alphabet[a];
                      possibleKeyB = alphabet[b];
                      possibleKeyC = alphabet[c];
                      possibleKeyD = alphabet[d];
                      possibleKeyE = alphabet[e];
                      possibleKeyConcat = possibleKeyA + possibleKeyB + possibleKeyC + possibleKeyD + possibleKeyE;
                      possibilities.push_back(possibleKeyConcat);
                    }
                  }
                }
                else{
                  string possibleKeyA, possibleKeyB, possibleKeyC, possibleKeyD, possibleKeyConcat;
                  possibleKeyA = alphabet[a];
                  possibleKeyB = alphabet[b];
                  possibleKeyC = alphabet[c];
                  possibleKeyD = alphabet[d];
                  possibleKeyConcat = possibleKeyA + possibleKeyB + possibleKeyC + possibleKeyD;
                  possibilities.push_back(possibleKeyConcat);
                }
              }
            }
            else{
              string possibleKeyA, possibleKeyB, possibleKeyC, possibleKeyConcat;
              possibleKeyA = alphabet[a];
              possibleKeyB = alphabet[b];
              possibleKeyC = alphabet[c];
              possibleKeyConcat = possibleKeyA + possibleKeyB + possibleKeyC;
              possibilities.push_back(possibleKeyConcat);
            }
          }
        }
        else {
          string possibleKeyA, possibleKeyB, possibleKeyConcat;
          possibleKeyA = alphabet[a];
          possibleKeyB = alphabet[b];
          possibleKeyConcat = possibleKeyA + possibleKeyB;
          possibilities.push_back(possibleKeyConcat);
          //cout << possibleKeyConcat<< endl;

        }
      }
    }
  }

  while(action != 2){
    printOptions();
    cin >> action;
    switch(action){
      case 1: {
        //start clock
        high_resolution_clock::time_point t1 = high_resolution_clock::now();

        for(int x = 0; x < pow(26, keyLength); x++){
          cout << possibilities[x] << ":   ";
          string key;
          key = possibilities[x];
          decipheredText.push_back(myCipher -> Decrypt(cipherText, keyLength, firstWordLength, key));
        }

        string match, trimmed, temp;
        for(unsigned int z = 0; z < decipheredText.size(); z++){
          //cout << decipheredText[z] << endl;
          temp = decipheredText[z];
          trimmed = temp.erase(firstWordLength, temp.length()-firstWordLength);

          if(myDictionary.find(trimmed) == myDictionary.end()){
            //do nothing
          }else{
            match = decipheredText[z];
          }
        }

        cout << endl <<"POTENTIAL MATCH: " << match << endl;
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(t2-t1).count();
        cout << endl << "TOTAL TIME TO CALCULATE: " << duration << "ms" << endl;
        action = 2;
        break;
      }
      case 2:
        cout << "EXITING PROGRAM..." << endl;
        break;
      default:
        cout << "INVALID INPUT, PLEASE ENTER A VALUE BETWEEN 1-3" << endl;
        break;
    }
  }





}
