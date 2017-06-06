#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "FakeButtonController.hpp"
#include "FakeCoinSlot.hpp"
#include "VendingTransaction.hpp"
#include "ItemDispenser.hpp"
#include "ChangeDispenser.hpp"

using testing::InSequence;
using testing::_;

class ItemDispenserMock : public ItemDispenser
{
public:
    MOCK_METHOD0(dispense, void());
};

class ChangeDispenserMock : public ChangeDispenser
{
public:
    MOCK_METHOD1(dispense_change, void(int));
};

class VendingTransactionTest : public ::testing::Test
{
protected:
    VendingTransactionTest()
        : item_dispenser()
        , change_dispenser()
        , transaction(item_dispenser, change_dispenser)
        , buttons(transaction)
        , coin_slot(transaction)
    {

    }

    ItemDispenserMock item_dispenser;
    ChangeDispenserMock change_dispenser;
    VendingTransaction transaction;
    FakeButtonController buttons;
    FakeCoinSlot coin_slot;
};

TEST_F(VendingTransactionTest, nothing_on_buy_button_pushed)
{
    EXPECT_CALL(item_dispenser, dispense())
        .Times(0);

    buttons.push_buy_button();
}

TEST_F(VendingTransactionTest, dispense_item_on_buy_button_press_when_coins_are_inserted)
{
    EXPECT_CALL(item_dispenser, dispense())
        .Times(1);
    EXPECT_CALL(change_dispenser, dispense_change(_)).Times(0);

    coin_slot.insert(10);
    buttons.push_buy_button();
}


TEST_F(VendingTransactionTest, dispense_item_on_two_buy_button_presses_when_coins_are_inserted)
{
    EXPECT_CALL(item_dispenser, dispense())
        .Times(1);
    EXPECT_CALL(change_dispenser, dispense_change(_)).Times(0);

    coin_slot.insert(10);
    buttons.push_buy_button();
    buttons.push_buy_button();
}

TEST_F(VendingTransactionTest, dispense_item_with_change) {
    EXPECT_CALL(item_dispenser, dispense())
        .Times(1);
    EXPECT_CALL(change_dispenser, dispense_change(10))
        .Times(1);

    coin_slot.insert(20);
    buttons.push_buy_button();
}


TEST_F(VendingTransactionTest, cancel_button_pushed) {
   EXPECT_CALL(change_dispenser, dispense_change(_)).Times(0);
   EXPECT_CALL(item_dispenser, dispense()).Times(0);

   buttons.push_cancel_button();
}

TEST_F(VendingTransactionTest, cancel_when_10_inserted) {
   EXPECT_CALL(change_dispenser, dispense_change(10)).Times(1);
   EXPECT_CALL(item_dispenser, dispense()).Times(0);

   coin_slot.insert(10);
   buttons.push_cancel_button();
}

TEST_F(VendingTransactionTest, cancel_twice_when_10_inserted) {
   EXPECT_CALL(change_dispenser, dispense_change(10)).Times(1);
   EXPECT_CALL(item_dispenser, dispense()).Times(0);

   coin_slot.insert(10);
   buttons.push_cancel_button();
   buttons.push_cancel_button();
}

TEST_F(VendingTransactionTest, two_consequtive_transactions)
{
    EXPECT_CALL(item_dispenser, dispense())
        .Times(2);
    EXPECT_CALL(change_dispenser, dispense_change(_)).Times(0);

    coin_slot.insert(10);
    buttons.push_buy_button();
    coin_slot.insert(10);
    buttons.push_buy_button();
}

TEST_F(VendingTransactionTest, cancel_and_new_transaction)
{
    EXPECT_CALL(item_dispenser, dispense())
        .Times(1);
    EXPECT_CALL(change_dispenser, dispense_change(_)).Times(0);

    buttons.push_cancel_button();
    coin_slot.insert(10);
    buttons.push_buy_button();
}

TEST_F(VendingTransactionTest, cancel_with_change_and_new_transaction)
{
    InSequence seq;
    EXPECT_CALL(change_dispenser, dispense_change(10)).Times(1);
    EXPECT_CALL(item_dispenser, dispense())
        .Times(1);
    EXPECT_CALL(change_dispenser, dispense_change(_)).Times(0);

    coin_slot.insert(10);
    buttons.push_cancel_button();
    coin_slot.insert(10);
    buttons.push_buy_button();
}
