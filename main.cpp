#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <unistd.h>

using std::string, std::vector, std::cout, std::cin, std::endl;

void print(vector<int> const &hand);
int card_sum(vector<int> const &hand);

int main (){
    cout << "Welcome to Blackjack!" << endl;

    bool game_continue {true};

    while (game_continue){
        // Initialize variables
        const vector<int> cards {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
        vector<int> dealer_hand {};
        int dealer_sum {};
        vector<int> player_hand {};
        int player_sum {};
        char player_answer{};
        bool player_hit {true};
        string new_game {};

        // Random seeding
        std::random_device rd;
        std::mt19937_64 mt(rd());
        std::uniform_int_distribution<int> dist(0, cards.size()-1);

        // Give cards to player and dealer
        for (int i {0}; i < 2; i++){

            player_hand.push_back(cards[dist(mt)]);
            dealer_hand.push_back(cards[dist(mt)]);

        }

        // Show cards
        cout << "Dealer hand:" << endl;
        cout << "[ X " << dealer_hand[0] << " ]" << endl;
        cout << "Player hand:" << endl;
        print(player_hand);
        cout << endl;

        // Initial sum of hands
        dealer_sum = card_sum(dealer_hand);
        player_sum = card_sum(player_hand);

        // Check if dealer starts with 21
        if (dealer_sum == 21){
            cout << "Dealer blackjack!" << endl;
            cout << "Dealer hand:" << endl;
            print(dealer_hand);
            cout << "Player hand:" << endl;
            print(player_hand);
            cout << endl;

        }
            // Check if player stars with 21
        else if (player_sum == 21){
            cout << "Player blackjack!" << endl;
            cout << "Dealer hand:" << endl;
            print(dealer_hand);
            cout << "Player hand:" << endl;
            print(player_hand);
            cout << endl;

        }
        else {
            // Player adds cards until pass or >= 21
            while (player_hit) {

                cout << "Hit or pass?\nType h to hit or p to pass: ";
                cin >> player_answer;
                // Player passes
                if (player_answer != 'h')
                    player_hit = false;
                    // Player hits
                else {
                    player_hand.push_back(cards[dist(mt)]);
                    print(player_hand);

                    // Check if past 21
                    player_sum = card_sum(player_hand);
                    if (player_sum > 21){
                        // Check for aces
                        for (size_t i {0}; i < player_hand.size(); i++){
                            if (player_hand[i] == 11){
                                player_hand[i] = 1;
                            }
                        }
                        // Recheck sum
                        player_sum = card_sum(player_hand);
                        // Check if still a bust
                        if (player_sum >= 21){
                            player_hit = false;
                        }
                    }

                }
                cout << endl;
            }

            // Check if player got 21
            if (player_sum == 21){
                cout << "Blackjack!\nYou won!!" << endl;
                cout << "You win!" << endl;
                cout << "Dealer hand:" << endl;
                print(dealer_hand);
                cout << "Player hand:" << endl;
                print(player_hand);
                cout << endl;
            }
                //Check if player bust
            else if (player_sum > 21){
                cout << "Bust!\nSorry, you lost this round." << endl;
                cout << "Dealer hand:" << endl;
                print(dealer_hand);
                cout << "Player hand:" << endl;
                print(player_hand);
                cout << endl;
            }
                // Player has < 21 and dealers turn
            else{
                // Dealer gets cards until sum >= 18
                while (dealer_sum < 18){
                    dealer_hand.push_back(cards[dist(mt)]);
                    dealer_sum = card_sum(dealer_hand);
                    for (size_t i {0}; i < player_hand.size(); i++){
                        if (dealer_hand[i] == 11){
                            dealer_hand[i] = 1;
                        }
                    }
                    dealer_sum = card_sum(dealer_hand);
                    print(dealer_hand);
                    sleep(1);
                }
                cout << endl;
                // Check for dealer blackjack
                if (dealer_sum == 21){
                    cout << "Dealer blackjack!\nSorry, you lost this round." << endl;
                    cout << "Dealer hand:" << endl;
                    print(dealer_hand);
                    cout << "Player hand:" << endl;
                    print(player_hand);
                    cout << endl;
                }
                    // check if dealer bust
                else if (dealer_sum > 21){
                    cout << "Dealer bust!\nYou won this round!" << endl;
                    cout << "Dealer hand:" << endl;
                    print(dealer_hand);
                    cout << "Player hand:" << endl;
                    print(player_hand);
                    cout << endl;

                }
                else{
                    if (dealer_sum > player_sum){
                        cout << "Dealer wins!" << endl;
                        cout << "Dealer hand:" << endl;
                        print(dealer_hand);
                        cout << "Player hand:" << endl;
                        print(player_hand);
                        cout << endl;
                    }
                    else if (dealer_sum == player_sum){
                        cout << "It's a tie!" << endl;
                        cout << "Dealer hand:" << endl;
                        print(dealer_hand);
                        cout << "Player hand:" << endl;
                        print(player_hand);
                        cout << endl;
                    }
                    else{
                        cout << "You win!" << endl;
                        cout << "Dealer hand:" << endl;
                        print(dealer_hand);
                        cout << "Player hand:" << endl;
                        print(player_hand);
                        cout << endl;
                    }
                }
            }
        }
        cout << "New game?\nType y or yes to continue, or n or no to cash out: ";
        cin >> new_game;
        if (new_game == "n" || new_game =="no"){
            game_continue = false;
            cout << endl;
        }
    }


    return 0;
}

void print(vector<int> const &hand){
    cout << "[ ";
    for (int i{0}; i < hand.size(); i++)
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