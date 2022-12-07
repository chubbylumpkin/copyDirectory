#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
using namespace std;


// reads filepath from sourceFiles.txt and returns it as a string
string getSource() {

    string line;

    fstream source;

    source.open("sourceFiles.txt");

    getline(source, line);

    return line;

}

// reads filepath from destinationFiles.txt and returns it as a string
string getDestination() {

    string line;

    fstream destination;

    destination.open("destinationFiles.txt");

    getline(destination, line);

    return line;

}

//copies all files from source to destination, updating the already existing files if possible
void duplicate(string source, string destination) {
    namespace fs = std::filesystem;

    fs::directory_iterator iterateMe(source);

    fs::path pathB;

    pathB.assign(destination);

    //iterate through each file from source and copies to destination
    while (iterateMe.operator->()) {

        fs::copy(iterateMe.operator*().path(), pathB, fs::copy_options::update_existing);

        iterateMe.operator++();

    }
 
}


int main()
{
    duplicate(getSource(), getDestination());

}
