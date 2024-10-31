#include "Orderbook.h"
#include <algorithm>

Orderbook::Orderbook(std::shared_ptr<OrderHistoryObserver> observer)
    : observer_(observer), nextOrderId_(1) {}

OrderId Orderbook::AddOrder(Side side, OrderType type, int price, int quantity) {
    auto order = OrderFactory::CreateOrder(nextOrderId_++, side, type, price, quantity);
    auto strategy = OrderFactory::CreateStrategy(type);

    if (strategy) {
        strategy->Execute(*order, GetOppositeOrders(order->GetSide()), trades_);
        observer_->LogOrder(*order);
    }

    if (order->GetType() != OrderType::Market) {
        (order->GetSide() == Side::Buy ? buyOrders_ : sellOrders_).push_back(*order);
    }

    return order->GetId();
}

std::vector<Order>& Orderbook::GetOppositeOrders(Side side) {
    return (side == Side::Buy) ? sellOrders_ : buyOrders_;
}
