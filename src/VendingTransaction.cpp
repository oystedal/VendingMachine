#include "VendingTransaction.hpp"
#include "ItemDispenser.hpp"
#include "ChangeDispenser.hpp"

VendingTransaction::VendingTransaction(ItemDispenser& dispenser_, ChangeDispenser& change_dispenser_)
    : dispenser(dispenser_)
    , change_dispenser(change_dispenser_)
    , total(0)
{

}

VendingTransaction::~VendingTransaction()
{

}

void VendingTransaction::on_buy_button_pushed()
{
    if(total >= 10){
        dispenser.dispense();
        total -= 10;

        if(total)
            change_dispenser.dispense_change(total);

        total = 0;
    }
}

void VendingTransaction::on_cancel_button_pushed()
{
    if(total){
        change_dispenser.dispense_change(total);
        total = 0;
    }
}

void VendingTransaction::on_coin_inserted(int amount)
{
    total = amount;
}
