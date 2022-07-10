#pragma once

#include <queue>
#include "Order.hpp"
#include "comparators.hpp"

class OrderHandler {
public:
    OrderHandler();
    virtual ~OrderHandler(); //TODO: Dump the remaining orders to a permanent storage

    virtual void addBid(Order &&order);
    virtual void addAsk(Order &&order);
    virtual void popBid();
    virtual void popAsk();


    virtual Order topBid();
    virtual Order topAsk();

private:
    std::priority_queue<Order, std::vector<Order>, CompareBids> bids_;
    std::priority_queue<Order, std::vector<Order>, CompareAsks> asks_;

};
