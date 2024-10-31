#ifndef ORDER_HISTORY_OBSERVER_H
#define ORDER_HISTORY_OBSERVER_H

#include "Order.h"
#include <fstream>
#include <memory>

class OrderHistoryObserver {
public:
    virtual void LogOrder(const Order& order) = 0;
    virtual void LogTrade(const Trade& trade) = 0;
    virtual ~OrderHistoryObserver() = default;
};

class ConsoleLogger : public OrderHistoryObserver {
public:
    void LogOrder(const Order& order) override;
    void LogTrade(const Trade& trade) override;
};

class FileLogger : public OrderHistoryObserver {
public:
    explicit FileLogger(const std::string& filename);
    ~FileLogger();
    void LogOrder(const Order& order) override;
    void LogTrade(const Trade& trade) override;

private:
    std::ofstream logFile_;
};

#endif
