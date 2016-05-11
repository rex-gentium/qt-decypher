#include "decypher.h"

string Decypher::vigenere(const string text, const string key)
{
    if (text.empty() || key.empty())
        return text;

    string decyphered;
    for (int i = 0; i < text.length(); i++)
        decyphered += (isalpha(text[i]))
            ? vigenere(text[i], key[i % key.length()])
            : text[i];

    return decyphered;
}

char Decypher::vigenere(const char c, const char keyC)
{
    char decyphered = 'a' + (tolower(c) - keyC + alphabetSize) % alphabetSize;
    return (isupper(c)) ? toupper(decyphered) : decyphered;
}
