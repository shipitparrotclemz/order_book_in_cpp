#include<OrderBook.h>
#include<iostream>

int main() {
    OrderBook order_book;

    order_book.add_ask(100, 200);
    order_book.add_bid(100, 100);

    OrderBook::BidAsk bid_ask = order_book.get_bid_ask();

    // print out the best bid (highest buy offer), and the best ask (lowest sell offer)
    std::cout << bid_ask << std::endl;

    // get the bid ask spread
    // print -1 if there is no bid ask spread
    std::cout << "Bid Ask Spread:" << bid_ask.spread().get_value_or(-1) << std::endl;
}