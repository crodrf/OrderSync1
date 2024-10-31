#include "Orderbook.h"
#include "OrderHistoryObserver.h"
#include <memory>

int main() {
    auto consoleLogger = std::make_shared<ConsoleLogger>();
    auto fileLogger = std::make_shared<FileLogger>("trade_log.txt");
    Orderbook orderbook(fileLogger);

    orderbook.AddOrder(Side::Buy, OrderType::GoodTillCancel, 100, 10);
    orderbook.AddOrder(Side::Sell, OrderType::GoodTillCancel, 95, 5);

    return 0;
}
