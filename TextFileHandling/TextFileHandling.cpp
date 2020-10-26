#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string getString(string message) {
    cout << message;
    string input;
    getline(cin, input);
    return input;
}
void CreateWorkFile() {
    string fileAdress = "file.txt";
    ofstream WorkFile(fileAdress);
    WorkFile << getString("Enter file text: ") + " ";
    WorkFile.close();
}
void SearchingWord() {
    bool finding = false;
    string yourWord = getString("Enter word what you want to found: ");
    string fileAdress = "file.txt";
    ifstream workFile(fileAdress);
    string content;
    getline(workFile, content);
    string word = "";
    for (auto i : content)
        if (i != ' ') {
            word += i;
        }
        else if (word == yourWord)
        {
            finding = true;
            word = "";
        }
        else
            word = "";
    if (finding)
        cout << "This word was found in file" << endl;
    else cout << "This word wasn`t found in file" << endl;
  }
void start() {
    setlocale(LC_ALL, "Rus");
    bool doing = true;
    while (doing) {
        string option = getString("Chose option: \n\t0 - creating work file \n\t1 - searching word in text\n\t100 - close program\n");
        switch (int(stof(option)))
        {
        case 0:
            CreateWorkFile();
            break;
        case 1:
            SearchingWord();
            break;
        default:
            doing = false;
            break;
        }
    }
}
int main()
{
    start();
}

