#ifndef VENDINGTRANSACTION_H
#define VENDINGTRANSACTION_H

class ItemDispenser;
class ChangeDispenser;

class VendingTransaction
{
public:
    VendingTransaction(ItemDispenser& dispenser, ChangeDispenser& change_dispenser);
    virtual ~VendingTransaction();

    void on_buy_button_pushed();
    void on_cancel_button_pushed();
    void on_coin_inserted(int amount);

private:
    int total;
    ItemDispenser& dispenser;
    ChangeDispenser& change_dispenser;
};

#endif /* VENDINGTRANSACTION_H */
