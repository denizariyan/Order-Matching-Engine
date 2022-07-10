#pragma once

#include "Order.hpp"

struct CompareBids {
    bool operator()(Order const & p1, Order const & p2) {
        // return "true" if "p1" is ordered before "p2", for example:
        return p1.getOrderPrice() < p2.getOrderPrice();
    }
};

struct CompareAsks {
    bool operator()(Order const &p1, Order const &p2) {
        // return "true" if "p1" is ordered before "p2", for example:
        return p1.getOrderPrice() > p2.getOrderPrice();
    }
};