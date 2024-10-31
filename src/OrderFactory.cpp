#include "OrderFactory.h"
#include "OrderMatchingStrategy.h"

std::unique_ptr<Order> OrderFactory::CreateOrder(OrderId id, Side side, OrderType type, int price, int quantity) {
    return std::make_unique<Order>(id, side, type, price, quantity);
}

std::unique_ptr<OrderMatchingStrategy> OrderFactory::CreateStrategy(OrderType type) {
    switch (type) {
        case OrderType::FillOrKill:
            return std::make_unique<FillOrKillStrategy>();
        case OrderType::Market:
            return std::make_unique<MarketOrderStrategy>();
        case OrderType::GoodForDay:
            return std::make_unique<GoodForDayStrategy>();
        case OrderType::GoodTillCancel:
            return std::make_unique<GoodTillCancelStrategy>();
        default:
            return nullptr;
    }
}
