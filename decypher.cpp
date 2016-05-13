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

string Decypher::caesar(string text, const int key)
{
    for (int i = 0; i < text.length(); i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (char)(((text[i] - key - 'A' + 26) % 26) + 'A');
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (char)(((text[i] - key - 'a' + 26) % 26) + 'a');
        }
     }
    return text;
}
