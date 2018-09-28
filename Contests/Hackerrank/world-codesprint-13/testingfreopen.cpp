#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool getFileContent (std::string fileName, std::vector<std::string>& vecOfStrs) {

    // Open the File
    std::ifstream in (fileName.c_str ());

    // Check if object is valid
    if (!in) {
        std::cerr << "Cannot open the File : " << fileName << std::endl;
        return false;
    }

    std::string str;
    // Read the next line from File untill it reaches the end.
    while (std::getline (in, str)) {
        // Line contains string of length > 0 then save it in vector
        if (str.size () > 0)
            vecOfStrs.push_back (str);
    }
    // Close The File
    in.close ();
    return true;
}

int main () {
    std::vector<std::string> vecOfStr;

    // Get the contents of file in a vector
    bool result = getFileContent ("test.txt", vecOfStr);

    if (result) {
        // Print the vector contents
        for (std::string& line : vecOfStr)
            std::cout << line << std::endl;
    }

    std::vector<std::string> vecOfStr1;

    // Get the contents of file in a vector
    result = getFileContent ("test1.txt", vecOfStr1);

    if (result) {
        // Print the vector contents
        for (std::string& line : vecOfStr1)
            std::cout << line << std::endl;
    }

    return 0;
}