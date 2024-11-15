class StockPrice {
    std::map<int, std::map<int, int>::iterator> timestamps;
    std::map<int, int> prices;

public:
    StockPrice() {
    
    }
    
    void update(int timestamp, int price) {
        auto priceIter = prices.find(price);
        if (priceIter == prices.end()) {
            priceIter = prices.insert({ price, 0 }).first;
        }
        priceIter->second++;

        auto timestampIter = timestamps.find(timestamp);
        if (timestampIter == timestamps.end()) {
            timestampIter = timestamps.insert({ timestamp, priceIter 
}).first;
            return;
        }
        
        if (!--timestampIter->second->second) {
            prices.erase(timestampIter->second);
        }
        timestampIter->second = priceIter;
    }
    
    int current() {
        return (--timestamps.end())->second->first;
    }
    
    int maximum() {
        return (--prices.end())->first;
    }
    
    int minimum() {
        return prices.begin()->first;
    }
};
