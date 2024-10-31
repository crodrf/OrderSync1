#ifndef ORDER_MATCHING_STRATEGY_H
#define ORDER_MATCHING_STRATEGY_H

#include "Order.h"
#include <vector>

class OrderMatchingStrategy {
public:
    virtual void Execute(Order& order, std::vector<Order>& oppositeOrders, std::vector<Trade>& trades) = 0;
    virtual ~OrderMatchingStrategy() = default;
};

class FillOrKillStrategy : public OrderMatchingStrategy {
public:
    void Execute(Order& order, std::vector<Order>& oppositeOrders, std::vector<Trade>& trades) override;
};

class MarketOrderStrategy : public OrderMatchingStrategy {
public:
    void Execute(Order& order, std::vector<Order>& oppositeOrders, std::vector<Trade>& trades) override;
};

class GoodForDayStrategy : public OrderMatchingStrategy {
public:
    void Execute(Order& order, std::vector<Order>& oppositeOrders, std::vector<Trade>& trades) override;
};

class GoodTillCancelStrategy : public OrderMatchingStrategy {
public:
    void Execute(Order& order, std::vector<Order>& oppositeOrders, std::vector<Trade>& trades) override;
};

#endif
