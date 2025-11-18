#include "struct.h"
#include <mutex>
#include <sstream>

int DataStorage::getField0() const {
    std::shared_lock lock(mutex0);  
    return field0;
}

void DataStorage::setField0(int value) {
    std::unique_lock lock(mutex0);
    field0 = value;
}

int DataStorage::getField1() const {
    std::shared_lock lock(mutex1);
    return field1;
}

void DataStorage::setField1(int value) {
    std::unique_lock lock(mutex1);
    field1 = value;
}

DataStorage::operator std::string() const {
    std::scoped_lock locks(mutex0, mutex1);
    
    std::ostringstream stream;
    stream << "[" << field0 << ", " << field1 << "]";
    return stream.str();
}