#include "VendingTransaction.hpp"

#include "ItemDispenser.hpp"
#include "ChangeDispenser.hpp"

VendingTransaction::VendingTransaction(ItemDispenser& dispenser_, ChangeDispenser& change_dispenser_)
    : dispenser(dispenser_)
    , change_dispenser(change_dispenser_)
{

}

VendingTransaction::~VendingTransaction()
{

}

void VendingTransaction::on_buy_button_pushed()
{

}

void VendingTransaction::on_cancel_button_pushed()
{

}

void VendingTransaction::on_coin_inserted(int amount)
{

}
