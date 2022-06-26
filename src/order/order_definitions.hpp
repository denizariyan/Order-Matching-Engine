#pragma once

// We could have a couple more options here such as "partially_filled" etc. but that can be calculated on front-end
// And I see no benefit of having that info directly
enum order_statuses {
    pending, // Order price is so far from actual price it is waiting in t2 order books to enter the t1 book
    open, // Order is open on the t1 book
    filled, // Order is filled, all done
    cancelled, // Order got cancelled for whatever reason other than expiring by time
    expired, // Order expired due to expire time
    UNKNOWN // Something is wrong, and we don't know what to do. Fail-safe enum
};

enum order_direction {
    buy,
    sell
};

// For the start we only support limit and market
enum order_type {
    limit,
    market
};
