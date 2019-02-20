#include "Cipher.h"
#include <string>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

Cipher::Cipher(){

}

string Cipher::Encrypt(string cipherText, int keyLength, int firstWordLength){

  return "foo";
}

string Cipher::Decrypt(string cipherText, int keyLength, int firstWordLength, string key){
  //Convert cipherText into Char Array
  int n = cipherText.length();
  //string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char myText[n];
  strcpy(myText, cipherText.c_str());
  int length = key.length();
  char myKey[length];
  strcpy(myKey, key.c_str());

  int i = 0;
  while(i < n) {
    for(int j = 0; j < keyLength; j++){ //cycles through our key
      //cout << j << temp[j] << " " <<  endl;
      if(myText[i] == '\0'){
        break;
      }

      myText[i] = char(myText[i] - ((myKey[j] - 'A') % 26));

      if(myText[i] < 'A'){
        myText[i] = ('Z' - ('A' - myText[i]-1));
      }
      i++;
    }
  }
  //cout << myText << "---------------" << endl;

  cout << myText << endl;

  return myText;
}
