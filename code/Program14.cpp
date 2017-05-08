#include <iostream>
#include <vector>
#include <fstream>

// This struct stores a word and the number of times it appears in a text
struct WordCount
{
    std::string word;
    int times;
};

std::vector<WordCount> countWords()
{
    std::vector<WordCount> words;

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
        // We check if currentWord is already in the vector of words
        bool alreadySeen = false;
        for (int i = 0; i < words.size(); i++)
        {
            if (currentWord == words[i].word) {
                // Complete this!
            }
        }

        if (!alreadySeen) {
	    WordCount word;
            // Complete this part!
        }
    }
}

int main()
{
    std::vector<WordCount> wordCounts = countWords();

    for (int i = 0; i < wordCounts.size(); i++) {
        std::cout << "The word '" << wordCounts[i].word << "' appears " << wordCounts[i].times << " times" << std::endl;
    }

    return 0;
}

