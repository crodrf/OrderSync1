#include "Order.h"

Order::Order(OrderId id, Side side, OrderType type, int price, int quantity)
    : id_(id), side_(side), type_(type), price_(price), quantity_(quantity) {}

OrderId Order::GetId() const { return id_; }
Side Order::GetSide() const { return side_; }
OrderType Order::GetType() const { return type_; }
int Order::GetPrice() const { return price_; }
int Order::GetQuantity() const { return quantity_; }
void Order::SetQuantity(int quantity) { quantity_ = quantity; }
