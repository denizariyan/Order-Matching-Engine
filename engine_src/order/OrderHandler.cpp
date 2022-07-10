#include "OrderHandler.hpp"


OrderHandler::OrderHandler() {}

OrderHandler::~OrderHandler() {}

void OrderHandler::addBid(Order &&order) {
    bids_.push(order);
}

void OrderHandler::addAsk(Order &&order) {
    asks_.push(order);
}

void OrderHandler::popBid() {
    return bids_.pop();
}

void OrderHandler::popAsk() {
    return asks_.pop();
}

Order OrderHandler::topBid() {
    return bids_.top();
}

Order OrderHandler::topAsk() {
    return asks_.top();
}