#include "order.hpp"

Order::Order(std::string orderId, std::string userId, order_statuses orderStatus, uint64_t orderOpenTime,
             uint64_t orderExpireTime, std::string orderPair, order_direction orderType, long double orderPrice,
             long double orderAmount) :
                order_id_(std::move(orderId)),
                user_id_(std::move(userId)),
                order_status_(orderStatus),
                order_open_time_(orderOpenTime),
                order_closed_time_(0),
                order_expire_time_(orderExpireTime),
                order_pair_(std::move(orderPair)),
                order_type_(orderType),
                order_price_(orderPrice),
                order_amount_(orderAmount),
                order_filled_amount_(0),
                order_fee_(0),
                avg_price_(0),
                trades_() {}


const std::string &Order::getOrderId() const {
    return order_id_;
}

const std::string &Order::getUserId() const {
    return user_id_;
}

order_statuses Order::getOrderStatus() const {
    return order_status_;
}

uint64_t Order::getOrderOpenTime() const {
    return order_open_time_;
}

uint64_t Order::getOrderClosedTime() const {
    return order_closed_time_;
}

uint64_t Order::getOrderExpireTime() const {
    return order_expire_time_;
}

const std::string &Order::getOrderPair() const {
    return order_pair_;
}

order_direction Order::getOrderType() const {
    return order_type_;
}

long double Order::getOrderPrice() const {
    return order_price_;
}

long double Order::getOrderAmount() const {
    return order_amount_;
}

long double Order::getOrderFilledAmount() const {
    return order_filled_amount_;
}

long double Order::getOrderFee() const {
    return order_fee_;
}

long double Order::getAvgPrice() const {
    return avg_price_;
}

const std::vector<std::string> &Order::getTrades() const {
    return trades_;
}

void Order::setOrderStatus(order_statuses orderStatus) {
    order_status_ = orderStatus;
}

void Order::setOrderClosedTime(uint64_t orderClosedTime) {
    order_closed_time_ = orderClosedTime;
}

void Order::setOrderFilledAmount(long double orderFilledAmount) {
    order_filled_amount_ = orderFilledAmount;
}

void Order::setOrderFee(long double orderFee) {
    order_fee_ = orderFee;
}

void Order::setAvgPrice(long double avgPrice) {
    avg_price_ = avgPrice;
}

void Order::addTrades(std::string order_id) {
    trades_.emplace_back(order_id);
}

Order::~Order() {

}
