#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include "../Order.hpp"

using ::testing::AtLeast;
using ::testing::Return;

TEST(OrderObjectDefaults, CheckDefaults) {
    Order order("0d025759-8725-4572-a19e-0d4ba6c12827", "9b69c307-7b94-45a6-9f70-475fb10c59d9",
                order_statuses::pending, 1656271002,1956243061,
                "BTCUSDT",order_direction::buy, 21259.66, 30.025);

    ASSERT_EQ(order.getAvgPrice(), 0);
    ASSERT_EQ(order.getOrderClosedTime(), 0);
    ASSERT_EQ(order.getOrderFee(), 0);
    ASSERT_EQ(order.getOrderFilledAmount(), 0);
    ASSERT_EQ(order.getOrderStatus(), order_statuses::pending);
}

TEST(OrderObjectSetterGetter, CheckSetterGetter) {
    Order order("0d025759-8725-4572-a19e-0d4ba6c12827", "9b69c307-7b94-45a6-9f70-475fb10c59d9",
                order_statuses::pending, 1656271002,1956243061,
                "BTCUSDT",order_direction::buy, 21259.66, 30.025);

    order.setAvgPrice(25.52);
    order.setOrderClosedTime(123);
    order.setOrderFee(10.45845);
    order.setOrderFilledAmount(1.2);
    order.setOrderStatus(order_statuses::filled);

    ASSERT_EQ(order.getAvgPrice(), 25.52);
    ASSERT_EQ(order.getOrderClosedTime(), 123);
    ASSERT_EQ(order.getOrderFee(), 10.45845);
    ASSERT_EQ(order.getOrderFilledAmount(), 1.2);
    ASSERT_EQ(order.getOrderStatus(), order_statuses::filled);
}