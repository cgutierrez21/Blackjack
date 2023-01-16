#include <iostream>
#include <vector>
//#include <string>
#include <random>

using std::string, std::vector, std::cout, std::cin, std::endl;

void print(vector<int> const &hand);
int card_sum(vector<int> const &hand);

int main() {
    // Initialize variables
    const vector<int> cards {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    vector<int> dealer_hand {};
    int dealer_sum {};
    vector<int> player_hand {};
    int player_sum {};
    char player_answer{};
    bool player_hit {true};
    bool game_continue {true};

    // Random seeding
    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_int_distribution<int> dist(0, cards.size()-1);

    // Give cards to player and dealer
    for(int i {0}; i < 2; i++){

        player_hand.push_back(cards[dist(mt)]);
        dealer_hand.push_back(cards[dist(mt)]);

    }

    // Start game
    cout << "Welcome to Blackjack!" << endl;

    while(game_continue) {

        cout << "Dealer hand:" << endl;
        cout << "[ X " << dealer_hand[0] << " ]" << endl;
        cout << "Player hand:" << endl;
        print(player_hand);

        // Initial sum of hands
        dealer_sum = card_sum(dealer_hand);
        player_sum = card_sum(player_hand);

        // Check for 21
        if(dealer_sum == 21) {

            game_continue = false;

        }
        else if(player_sum == 21){

            game_continue = false;

        }
        else {

            while (player_hit) {

                cout << "Hit or pass?\nType h to hit or p to pass: ";
                cin >> player_answer;

                if (player_answer != 'h')

                    player_hit = false;

                else {

                    player_hand.push_back(cards[dist(mt)]);
                    print(player_hand);

                }
            }
            game_continue = false;
        }
    }

    return 0;
}

void print(vector<int> const &hand){
    cout << "[ ";
    for(int i{0}; i < hand.size(); i++)
        cout << hand.at(i) << " ";
    cout << "]" << endl;
}

int card_sum(vector<int> const &hand){
    int sum{0};
    for (int i {0}; i < hand.size(); i++){
        sum += hand.at(i);
    }
    return sum;
}