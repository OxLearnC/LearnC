#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

// This keeps track of the numbers we have already generated
// Vectors are like lists in Python, but they can only contain values of one type
std::vector<int> deck;

// This reshuffles the deck from numbers from beginning to end
void shuffle(int beginning, int end)
{
  deck.resize(end - beginning + 1);

  for (int i = beginning; i <= end; i++) {
    deck[i - beginning] = i;
  }

  for (int i = 0; i < deck.size(); i++) {
    int new_location = rand() % (end - beginning + 1);
    int temp = deck[i];
    deck[i] = deck[new_location];
    deck[new_location] = temp;
  }
}

// deal() returns a random element from the deck, or -1 if the deck is empty
int deal()
{
  if (!deck.empty()) {
    int element = deck.back();
    deck.pop_back();
    return element;
  } else {
    return -1;
  }
}

// random(a, b) returns a random number in the range [a, b]
int random(int beginning, int end)
{
  return rand() % (end - beginning + 1) + beginning;
}

int main()
{
  srand(time(NULL)); // This sets up the random number generator

  // 0 = Ace
  // 11 = J
  // 12 = Q
  // 13 = K
  shuffle(0, 13);

}
