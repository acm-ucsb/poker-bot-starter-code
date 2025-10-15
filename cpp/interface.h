// DO NOT MODIFY
#pragma once

#include <string>
#include <vector>

using std::vector;
using std::string;

class Pot {
public:
    int value;
    vector<string> players;
};

class GameState {
public:
    size_t index_to_action;
    size_t index_of_small_blind;
    vector<string> players;
    vector<string> player_cards;
    vector<int> held_money;
    vector<int> bet_money;
    vector<string> community_cards;
    vector<Pot> pots;
    int small_blind;
    int big_blind;
};

int bet(GameState &state);