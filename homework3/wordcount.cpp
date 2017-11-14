#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

template <class KTy, class Ty>
void PrintMap(map<KTy, Ty> map){
    typedef typename std::map<KTy, Ty>::iterator iterator;
    for (iterator p = map.begin(); p != map.end(); p++)
        cout << p->first << " " << p->second << endl;
}

int main(void){
    static const char* fileName;
    cout << "Enter a file name: " << endl;
    cin >> fileName;
    map<string, unsigned int> wordsCount;

    ifstream fileStream(fileName);

    if (fileStream.is_open())
        while (fileStream.good())
        {
            string word;
            fileStream >> word;
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);

            if (wordsCount.find(word) == wordsCount.end())
                wordsCount[word] = 1;
            else
                wordsCount[word]++;
        }
    else
    {
        cerr << "Couldn't open the file." << endl;
        return EXIT_FAILURE;
    }

    PrintMap(wordsCount);

    return 0;
}
