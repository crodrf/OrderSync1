#include "OrderHistoryObserver.h"
#include <iostream>

void ConsoleLogger::LogOrder(const Order& order) {
    std::cout << "Order logged: ID " << order.GetId() << "\n";
}

void ConsoleLogger::LogTrade(const Trade& trade) {
    std::cout << "Trade executed: Buy ID " << trade.buyOrderId << " Sell ID " << trade.sellOrderId << "\n";
}

FileLogger::FileLogger(const std::string& filename) {
    logFile_.open(filename, std::ios::out | std::ios::app);
}

FileLogger::~FileLogger() {
    if (logFile_.is_open()) logFile_.close();
}

void FileLogger::LogOrder(const Order& order) {
    if (logFile_.is_open()) {
        logFile_ << "Order logged: ID " << order.GetId() << " Price: " << order.GetPrice()
                 << " Quantity: " << order.GetQuantity() << "\n";
    }
}

void FileLogger::LogTrade(const Trade& trade) {
    if (logFile_.is_open()) {
        logFile_ << "Trade executed: Buy ID " << trade.buyOrderId << " Sell ID " << trade.sellOrderId
                 << " Price: " << trade.price << " Quantity: " << trade.quantity << "\n";
    }
}
