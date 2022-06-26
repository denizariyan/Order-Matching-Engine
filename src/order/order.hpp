#pragma once

#include "../common.hpp"
#include "order_definitions.hpp"

class Order {
public:
        Order(std::string orderId, std::string userId, order_statuses orderStatus, uint64_t orderOpenTime,
                uint64_t orderExpireTime, std::string orderPair, order_direction orderType, long double orderPrice,
                long double orderAmount);
        virtual ~Order();

        // Getters
        virtual const std::string &getOrderId() const;
        virtual const std::string &getUserId() const;
        virtual order_statuses getOrderStatus() const;
        virtual uint64_t getOrderOpenTime() const;
        virtual uint64_t getOrderClosedTime() const;
        virtual uint64_t getOrderExpireTime() const;
        virtual const std::string &getOrderPair() const;
        virtual order_direction getOrderType() const;
        virtual long double getOrderPrice() const;
        virtual long double getOrderAmount() const;
        virtual long double getOrderFilledAmount() const;
        virtual long double getOrderFee() const;
        virtual long double getAvgPrice() const;
        virtual const std::vector<std::string> &getTrades() const;

        // Setters
        virtual void setOrderStatus(order_statuses orderStatus);
        virtual void setOrderClosedTime(uint64_t orderClosedTime);
        virtual void setOrderFilledAmount(long double orderFilledAmount);
        virtual void setOrderFee(long double orderFee);
        virtual void setAvgPrice(long double avgPrice);
        virtual void addTrades(std::string order_id);


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