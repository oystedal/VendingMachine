#ifndef FAKECOINSLOT_H
#define FAKECOINSLOT_H

#include "CoinSlot.hpp"

class VendingTransaction;

class FakeCoinSlot : public CoinSlot
{
public:
    FakeCoinSlot(VendingTransaction& transaction);
    virtual ~FakeCoinSlot();

    void insert(int amount);

private:
    VendingTransaction& transaction;
};

#endif /* FAKECOINSLOT_H */
