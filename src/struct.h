#pragma once
#include <shared_mutex>
#include <string>

class DataStorage {
    private:
        int field0 = 0;
        int field1 = 0;
        
        mutable std::shared_mutex mutex0;
        mutable std::shared_mutex mutex1;
        
    public:
        DataStorage() = default;
        DataStorage(const DataStorage&) = delete;
        DataStorage& operator=(const DataStorage&) = delete;
        ~DataStorage() = default;
        
        int getField0() const;
        void setField0(int value);
        
        int getField1() const;
        void setField1(int value);
        
        operator std::string() const;
};