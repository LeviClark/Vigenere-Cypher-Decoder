#ifndef Cipher_H
#define Cipher_H
#include <string>
#include <vector>
using namespace std;

class Cipher{
public:
  Cipher();
  std::string Encrypt(string cipherText, int keyLength, int firstWordLength);
  std::string Decrypt(string cipherText, int keyLength, int firstWordLength, string key);
//  void Crack(vector<string> options, int keyLength, string cipherText);
private:

};
#endif
