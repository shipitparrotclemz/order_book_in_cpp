#include "OrderBook.h"

bool OrderBook::is_empty() const
{
    return bids.empty() && asks.empty();
}

void OrderBook::remove_bid(int price, int amount) {
    return remove(price, amount, true);
}

void OrderBook::add_bid(int price, int amount) {
    return add(price, amount, true);
}

void OrderBook::remove_ask(int price, int amount) {
    return remove(price, amount, false);
}

void OrderBook::add_ask(int price, int amount) {
    return add(price, amount, false);
}


void OrderBook::add(int price, int amount, bool is_bid) {
    if (is_bid) {
        bids[price] += amount;
    } else {
        asks[price] += amount;
    }
}

void OrderBook::remove(int price, int amount, bool is_bid) {
    auto& table = is_bid ? bids : asks;
    auto it = table.find(price);

    if (it != table.end()) {
        it->second -= amount;
        if (it -> second <= 0) {
            table.erase(it);
        }
    }
}

OrderBook::BidAsk OrderBook::get_bid_ask() const {
    BidAsk bidAsk;
    // get the highest bid
    auto best_bid = bids.rbegin();

    if (best_bid != bids.rend()) {
        bidAsk.bid = *best_bid;
    }
    // get the lowest ask
    auto best_ask = asks.begin();

    if (best_ask != asks.end()) {
        bidAsk.ask = *best_ask;
    }
    return bidAsk;
}

boost::optional<int> OrderBook::BidAsk::spread() const {
    boost::optional<int> spread;
    if (bid.is_initialized() && ask.is_initialized()) {
        spread = ask.get().first - bid.get().first;
    }
    return spread;
}

std::ostream& operator<<(std::ostream& os, const OrderBook& book) {
    if (book.is_empty()) {
        std::cout << "OrderBook empty!" << std::endl;
        return os;
    } else {
        for (auto it = book.bids.rbegin(); it != book.bids.rend(); it++) {
            os << it->first << "\t" << it->second << std::endl;
        }
        os << std::endl;
        for (auto it = book.asks.rbegin(); it != book.asks.rend(); it++) {
            os << it->first << "\t" << it->second << std::endl;
        }
        return os;
    }
}

std::ostream& operator<<(std::ostream& os, const OrderBook::BidAsk& bid_ask) {
    auto print = [&](const OrderBook::BidAsk::Entry& entry, const std::string& text) {
        bool have_value = entry.is_initialized();
        if (have_value) {
            auto value = entry.get();
            std::cout << value.second <<  " " << text << "s @ " << value.first << std::endl;
        } else {
            std::cout << "NO " << text << std::endl;;
        }
    };
    print(bid_ask.bid, "bid");
    os << ", " << std::endl;
    print(bid_ask.ask, "ask");
    return os;
}