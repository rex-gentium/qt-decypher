#ifndef DECYPHER_H
#define DECYPHER_H

#include <string>
using namespace std;

class Decypher
{
public:
    static string vigenere(const string text, const string key);
private:
    virtual void thisClassIsAbstract() = 0;
};

#endif // DECYPHER_H
