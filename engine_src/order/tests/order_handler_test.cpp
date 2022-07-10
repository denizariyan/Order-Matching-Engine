#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include "../OrderHandler.hpp"

using ::testing::AtLeast;
using ::testing::Return;

TEST(OrderHandlerQueues, CheckQueueCorrectness) {
    OrderHandler order_handler;

    Order test_order1("1d025759-8725-4572-a19e-0d4ba6c12827", "9b69c307-7b94-45a6-9f70-475fb10c59d9",
                      order_statuses::pending, 1656271002,1956243061,
                      "BTCUSDT",order_direction::buy, 20000.0, 30.025);

    Order test_order2("2d025759-8725-4572-a19e-0d4ba6c12827", "9b69c307-7b94-45a6-9f70-475fb10c59d9",
                      order_statuses::pending, 1656271002,1956243061,
                      "BTCUSDT",order_direction::buy, 10000.0, 30.025);

    order_handler.addBid(std::move(test_order1));
    order_handler.addBid(std::move(test_order2));

    order_handler.addAsk(std::move(test_order1));
    order_handler.addAsk(std::move(test_order2));

    ASSERT_EQ(order_handler.topAsk().getOrderPrice(), 10000.0);
    ASSERT_EQ(order_handler.topBid().getOrderPrice(), 20000.0);

}
