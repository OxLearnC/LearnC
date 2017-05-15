#include <iostream>
#include <map>
#include <fstream>

std::map<std::string, int> countWords()
{
    std::map<std::string, int> words;

    std::fstream file;
    file.open("example.txt", std::fstream::in); // Replace example.txt with whatever file name you want!
    if (! file.is_open())
    {
        std::cout << "The file could not be found!" << std::endl;
        return words;
    }

    std::string currentWord;
    while (file >> currentWord)
    {
        // To check if some key appears in a map or not, we use map.count(key)
        // It will return 0 (if key doesn't appear in map) or 1 otherwise
        if (words.count(currentWord) == 0) {
	    // Fill this in!
        } else {
	    // And this!
        }
    }
    return words;
}

int main()
{
    std::map<std::string, int> wordCounts = countWords();

    // Since we don't access elements based on index, we can't iterate with the usual for (int i = 0...)
    // Instead, we have to use iterators
    // An iterator is a bit like an arrow that points to some element in a vector or map
    for (std::map<std::string, int>::iterator i = wordCounts.begin(); i != wordCounts.end(); i++)
    {
        // The iterator i represents a pair of a key and a value
        // We can access the key with (i->first), and the value with (i->second)
        std::cout << "The word '" << (i->first) << "' appears " << (i->second) << " times" << std::endl;
    }

    return 0;
}
