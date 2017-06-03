#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "FakeButtonController.hpp"
#include "FakeCoinSlot.hpp"
#include "VendingTransaction.hpp"
#include "ItemDispenser.hpp"
#include "ChangeDispenser.hpp"

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

TEST_F(VendingTransactionTest, happy_path)
{
}

