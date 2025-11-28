#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int countLetters(const string& sentence)
{
    int count = 0;
    for (char c : sentence)
    {
        if (isalpha(c))  // ¼ì²éÊÇ·ñÎª×ÖÄ¸
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string sentence;

    cout << "Enter an English sentence: ";
    getline(cin, sentence);

    int letterCount = countLetters(sentence);
    cout << "Number of letters in the sentence: " << letterCount << endl;

    return 0;
}