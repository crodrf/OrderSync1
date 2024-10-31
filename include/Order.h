#ifndef ORDER_H
#define ORDER_H

#include <iostream>

enum class OrderType { GoodTillCancel, FillOrKill, Market, GoodForDay };
enum class Side { Buy, Sell };

using OrderId = int;

class Order {
public:
    Order(OrderId id, Side side, OrderType type, int price, int quantity);
    OrderId GetId() const;
    Side GetSide() const;
    OrderType GetType() const;
    int GetPrice() const;
    int GetQuantity() const;
    void SetQuantity(int quantity);

private:
    OrderId id_;
    Side side_;
    OrderType type_;
    int price_;
    int quantity_;
};

struct Trade {
    OrderId buyOrderId;
    OrderId sellOrderId;
    int price;
    int quantity;
};

#endif
