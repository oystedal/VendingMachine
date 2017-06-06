#include "FakeCoinSlot.hpp"
#include "VendingTransaction.hpp"

FakeCoinSlot::FakeCoinSlot(VendingTransaction& transaction_)
    : transaction(transaction_)
{

}

FakeCoinSlot::~FakeCoinSlot()
{

}

void FakeCoinSlot::insert(int amount)
{
    transaction.on_coin_inserted(amount);
}
