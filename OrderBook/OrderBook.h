#pragma once
#include<map>
#include<iostream>
#include<boost/optional.hpp>

class OrderBook {
    // bids -> the buy orders
    // asks -> the sell orders
    std::map<int, int> bids, asks;
    void add(int price, int amount, bool is_bid);
    void remove(int price, int amount, bool is_bid);
public:
    struct BidAsk {
        typedef boost::optional<std::pair<int, int>> Entry;
        Entry bid, ask;
        boost::optional<int> spread() const;
    };

    OrderBook::BidAsk get_bid_ask() const;

    bool is_empty() const;
    void add_bid(int price, int amount);
    void add_ask(int price, int amount);
    void remove_bid(int price, int amount);
    void remove_ask(int price, int amount);
    friend std::ostream& operator<<(std::ostream& os, const OrderBook& book);
    friend std::ostream& operator<<(std::ostream& os, const BidAsk& bidask);
};