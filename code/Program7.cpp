#include <iostream>
#include <string>
#include <fstream>

int main()
{
  std::string filename;
  std::string word;

  std::cout << "Input a filename: ";
  std::cin >> filename;

  std::cout << "Input a word to look for: ";
  std::cin >> word;

  std::fstream file;
  // We open the file in read mode
  // (we can't use a std::string as a filename, we need to call .c_str() for technical reasons)
  file.open(filename.c_str(), std::fstream::in);
  // We need to check that the file was open correctly!
  if (! file.is_open()) {
    // If the file doesn't exist, we print an error message and exit!
    std::cout << "The file " << filename << " couldn't be found!" << std::endl;
    return 1; // Remember that main returns something other than 0 if there were errors!
  }

  std::string currentWord;
  int count = 0;
  // `>>` reads word-by-word and also returns true or false depending on whether something was read
  while (file >> currentWord) {
    if (currentWord == word) {
      count++;
    }
  }
  file.close(); // Always close your files!

  std::cout << "There are "
	    << count
	    << " occurrences of the word "
	    << word
	    << " in the file "
	    << filename
	    << std::endl;
  
  return 0;
}
