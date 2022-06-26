#pragma once

#include "../common.hpp"
#include "order_definitions.hpp"

class Order {
    public:

    Order(std::string orderId, std::string userId, order_statuses orderStatus, uint64_t orderOpenTime,
          uint64_t orderExpireTime, std::string orderPair, order_direction orderType, long double orderPrice,
          long double orderAmount);

// Getters
        const std::string &getOrderId() const;
        const std::string &getUserId() const;
        order_statuses getOrderStatus() const;
        uint64_t getOrderOpenTime() const;
        uint64_t getOrderClosedTime() const;
        uint64_t getOrderExpireTime() const;
        const std::string &getOrderPair() const;
        order_direction getOrderType() const;
        long double getOrderPrice() const;
        long double getOrderAmount() const;
        long double getOrderFilledAmount() const;
        long double getOrderFee() const;
        long double getAvgPrice() const;
        const std::vector<std::string> &getTrades() const;

        // Setters
        void setOrderStatus(order_statuses orderStatus);
        void setOrderClosedTime(uint64_t orderClosedTime);
        void setOrderFilledAmount(long double orderFilledAmount);
        void setOrderFee(long double orderFee);
        void setAvgPrice(long double avgPrice);
        void addTrades(std::string order_id);

    private:
        std::string order_id_; // use boost::uuid
        std::string user_id_;
        order_statuses order_status_;
        uint64_t order_open_time_;
        uint64_t order_closed_time_;// Closed for whatever reason, same as expire time if order closed by expiring
        uint64_t order_expire_time_;
        std::string order_pair_;
        order_direction order_type_;
        long double order_price_;   // Storing currency as double is not a great approach. Even long double is not
                                    // precise enough. Should probably implement a better approach for this later on
        long double order_amount_;
        long double order_filled_amount_;
        long double order_fee_; // The fee we charge for this order, should be incremented as we fill the order
        long double avg_price_; // avg price that this order filled for
        std::vector<std::string> trades_; // order_ids for the orders that matched with this trade
};