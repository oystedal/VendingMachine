
.PHONY: test

test: test/test
	./test/test

SRC = src/CoinChanger.cpp src/VendingTransaction.cpp
TESTS = test/main.cpp test/test_coinchanger.cpp test/test_vendingtransaction.cpp
DOUBLES = test/doubles/FakeButtonController.cpp test/doubles/FakeCoinSlot.cpp

test/test: $(TESTS) $(SRC) $(DOUBLES)
	g++ -Itest/doubles/include -Isrc/include -lpthread -lgmock -lgtest $(TESTS) $(SRC) $(DOUBLES) -o test/test
