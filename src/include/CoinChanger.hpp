#ifndef COINCHANGER_H
#define COINCHANGER_H

#include <vector>

class CoinChanger
{
public:
    CoinChanger();
    virtual ~CoinChanger();

    std::vector<int> change(int difference);

private:

};

#endif /* COINCHANGER_H */
