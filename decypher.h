#ifndef DECYPHER_H
#define DECYPHER_H

#include <string>
using namespace std;

class Decypher
{
    static const unsigned alphabetSize = 26;
public:
    static string vigenere(const string text, const string key);
    static char vigenere(const char c, const char keyC);
    static string caesar(const string text, const int key);
};

#endif // DECYPHER_H
