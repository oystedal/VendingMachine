#include "FakeButtonController.hpp"
#include "VendingTransaction.hpp"

FakeButtonController::FakeButtonController(VendingTransaction& transaction_)
    : transaction(transaction_)
{

}

FakeButtonController::~FakeButtonController()
{

}

void FakeButtonController::push_buy_button()
{
    transaction.on_buy_button_pushed();
}

void FakeButtonController::push_cancel_button()
{
    transaction.on_cancel_button_pushed();
}
