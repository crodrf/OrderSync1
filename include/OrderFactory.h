#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include "Order.h"
#include "OrderMatchingStrategy.h"
#include <memory>

class OrderFactory {
public:
    static std::unique_ptr<Order> CreateOrder(OrderId id, Side side, OrderType type, int price, int quantity);
    static std::unique_ptr<OrderMatchingStrategy> CreateStrategy(OrderType type);
};

#endif
