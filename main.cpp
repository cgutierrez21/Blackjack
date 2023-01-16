#include <iostream>
#include <vector>
//#include <string>
#include <random>

using std::string, std::vector, std::cout, std::cin, std::endl;

void print(vector<int> const &hand);

int main() {
    const vector<int> cards {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    vector<int> dealer_hand {};
    vector<int> exposed_dealer_hand {};
    vector<int> player_hand {};

    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_int_distribution<int> dist(0, cards.size());

    for(int i {0}; i < 2; i++){
        dealer_hand.push_back(cards[dist(mt)]);
    }

    for(int i {0}; i < 2; i++){
        player_hand.push_back(cards[dist(mt)]);
    }

    print(dealer_hand);
    print(player_hand);



    return 0;
}

void print(vector<int> const &hand){
    cout << "[ ";
    for(int i{0}; i < hand.size(); i++)
        cout << hand.at(i) << " ";
    cout << "]" << endl;
}