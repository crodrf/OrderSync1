#include "Order.h"
#include "OrderFactory.h"
#include <gtest/gtest.h>

TEST(OrderMatchingStrategyTest, TestFillOrKillStrategy) {
    auto strategy = OrderFactory::CreateStrategy(OrderType::FillOrKill);
    Order buyOrder(1, Side::Buy, OrderType::FillOrKill, 100, 10);
    std::vector<Order> sellOrders = {Order(2, Side::Sell, OrderType::GoodTillCancel, 100, 10)};
    std::vector<Trade> trades;

    strategy->Execute(buyOrder, sellOrders, trades);
    ASSERT_EQ(buyOrder.GetQuantity(), 0);
}

TEST(OrderMatchingStrategyTest, TestMarketOrderStrategy) {
    auto strategy = OrderFactory::CreateStrategy(OrderType::Market);
    Order buyOrder(1, Side::Buy, OrderType::Market, 100, 10);
    std::vector<Order> sellOrders = {Order(2, Side::Sell, OrderType::GoodTillCancel, 100, 5)};
    std::vector<Trade> trades;

    strategy->Execute(buyOrder, sellOrders, trades);
    ASSERT_EQ(buyOrder.GetQuantity(), 5);
    ASSERT_EQ(trades.size(), 1);
}



