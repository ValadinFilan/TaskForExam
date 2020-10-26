#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreateWorkFile() {

}
void SearchingWord() {

}


string getString(string message) {
    cout << message;
    string input;
    getline(cin, input);
    return input;
}
void start() {
    string option = getString("Chose option: \t\t\t2 - creating work file \t\t\t1 - searching word in text\n");
    string chose = "";
    cin >> chose;
    switch (int(stof(chose)))
    {
    case 0:
        CreateWorkFile;
        break;
    case 1:
        SearchingWord();
        break;
    default:
        break;
    }
}
int main()
{
    start();
}

