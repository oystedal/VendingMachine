#include "CoinChanger.hpp"

CoinChanger::CoinChanger()
{

}

CoinChanger::~CoinChanger()
{

}

std::vector<int> CoinChanger::change(int difference)
{
    std::vector<int> change;

    auto coins = {10, 5, 1};

    int remaining_difference = difference;

    for(auto coin : coins) {
        while (remaining_difference >= coin){
            change.push_back(coin);
            remaining_difference -= coin;
        }
    }

    return change;
}
