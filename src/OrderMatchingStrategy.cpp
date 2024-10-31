#include "OrderMatchingStrategy.h"

void FillOrKillStrategy::Execute(Order& order, std::vector<Order>& oppositeOrders, std::vector<Trade>& trades) {
    int totalMatchQuantity = 0;
    for (const auto& o : oppositeOrders) {
        totalMatchQuantity += o.GetQuantity();
        if (totalMatchQuantity >= order.GetQuantity()) {
            order.SetQuantity(0);
            break;
        }
    }
}

void MarketOrderStrategy::Execute(Order& order, std::vector<Order>& oppositeOrders, std::vector<Trade>& trades) {
    for (auto& o : oppositeOrders) {
        int matchedQty = std::min(order.GetQuantity(), o.GetQuantity());
        trades.push_back({order.GetId(), o.GetId(), o.GetPrice(), matchedQty});
        o.SetQuantity(o.GetQuantity() - matchedQty);
        order.SetQuantity(order.GetQuantity() - matchedQty);

        if (order.GetQuantity() == 0) break;
    }
}

void GoodForDayStrategy::Execute(Order& order, std::vector<Order>& oppositeOrders, std::vector<Trade>& trades) {
    for (auto& o : oppositeOrders) {
        if (o.GetQuantity() >= order.GetQuantity() && o.GetPrice() == order.GetPrice()) {
            trades.push_back({order.GetId(), o.GetId(), o.GetPrice(), order.GetQuantity()});
            o.SetQuantity(o.GetQuantity() - order.GetQuantity());
            order.SetQuantity(0);
            break;
        }
    }
}

void GoodTillCancelStrategy::Execute(Order& order, std::vector<Order>& oppositeOrders, std::vector<Trade>& trades) {
    while (order.GetQuantity() > 0) {
        for (auto& o : oppositeOrders) {
            int matchedQty = std::min(order.GetQuantity(), o.GetQuantity());
            trades.push_back({order.GetId(), o.GetId(), o.GetPrice(), matchedQty});
            o.SetQuantity(o.GetQuantity() - matchedQty);
            order.SetQuantity(order.GetQuantity() - matchedQty);

            if (order.GetQuantity() == 0) break;
        }
    }
}
