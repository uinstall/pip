#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Card structure
struct Card {
    string rank;
    string suit;
};

// Function to generate a deck of cards
vector<Card> generateDeck() {
    vector<string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    vector<Card> deck;

    for (const string& suit : suits) {
        for (const string& rank : ranks) {
            deck.push_back(Card{rank, suit});
        }
    }
    return deck;
}

// Function to shuffle the deck
void shuffleDeck(vector<Card>& deck) {
    srand(time(0));
    random_shuffle(deck.begin(), deck.end());
}

// Function to check if a hand is a Royal Flush using recursion
bool isRoyalFlush(vector<Card>& hand, int index = 0, const string& suit = "") {
    // Base case: if we've checked all cards and they're all in the Royal Flush
    vector<string> royalFlush = {"10", "J", "Q", "K", "A"};
    if (index == hand.size()) {
        for (const Card& card : hand) {
            if (find(royalFlush.begin(), royalFlush.end(), card.rank) == royalFlush.end() || card.suit != suit) {
                return false;
            }
        }
        return true;
    }

    // Recursive case: set the suit if it's the first card and check for Royal Flush
    if (index == 0) {
        return isRoyalFlush(hand, index + 1, hand[index].suit);
    } else {
        return isRoyalFlush(hand, index + 1, suit);
    }
}

// Function to draw a poker hand
vector<Card> drawHand(vector<Card>& deck) {
    vector<Card> hand(deck.begin(), deck.begin() + 5);
    deck.erase(deck.begin(), deck.begin() + 5);
    return hand;
}

// Function to display a hand of cards
void displayHand(const vector<Card>& hand) {
    for (const Card& card : hand) {
        cout << card.rank << " of " << card.suit << endl;
    }
}

int main() {
    vector<Card> deck = generateDeck();
    shuffleDeck(deck);

    vector<Card> hand = drawHand(deck);

    cout << "Your hand is:\n";
    displayHand(hand);

    if (isRoyalFlush(hand)) {
        cout << "\nCongratulations! You have a Royal Flush!\n";
    } else {
        cout << "\nSorry, you do not have a Royal Flush.\n";
    }

    return 0;
}
