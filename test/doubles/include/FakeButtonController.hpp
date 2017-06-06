#ifndef FAKEBUTTONCONTROLLER_H
#define FAKEBUTTONCONTROLLER_H

#include "ButtonController.hpp"

class VendingTransaction;

class FakeButtonController : public ButtonController
{
public:
    FakeButtonController(VendingTransaction& transaction);
    virtual ~FakeButtonController();

    void push_buy_button();
    void push_cancel_button();
private:
    VendingTransaction& transaction;
};

#endif /* FAKEBUTTONCONTROLLER_H */
