#ifndef BUTTONCONTROLLER_H
#define BUTTONCONTROLLER_H

class VendingTransaction;

class ButtonController
{
public:
    virtual void push_buy_button() = 0;
    virtual void push_cancel_button() = 0;
};

#endif /* BUTTONCONTROLLER_H */
