#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "Order.h"
#include "OrderHistoryObserver.h"
#include "OrderFactory.h"
#include <memory>
#include <vector>

class Orderbook {
public:
    Orderbook(std::shared_ptr<OrderHistoryObserver> observer);
    OrderId AddOrder(Side side, OrderType type, int price, int quantity);

private:
    std::vector<Order>& GetOppositeOrders(Side side);
    std::vector<Order> buyOrders_;
    std::vector<Order> sellOrders_;
    std::vector<Trade> trades_;
    OrderId nextOrderId_;
    std::shared_ptr<OrderHistoryObserver> observer_;
};

#endif
