#include <iostream>
#include "rocksdb/db.h"

int main() {
    rocksdb::DB* db;
    rocksdb::Options options;
    options.create_if_missing = true;

    // 打开数据库（路径建议使用绝对路径）
    rocksdb::Status status = rocksdb::DB::Open(options, "/tmp/testdb", &db);
    if (!status.ok()) {
        std::cerr << "DB open failed: " << status.ToString() << std::endl;
        return 1;
    }

    // 写入数据
    status = db->Put(rocksdb::WriteOptions(), "key1", "Hello RocksDB");
    if (!status.ok()) {
        std::cerr << "Put failed: " << status.ToString() << std::endl;
    }

    // 读取数据
    std::string value;
    status = db->Get(rocksdb::ReadOptions(), "key1", &value);
    if (status.ok()) {
        std::cout << "Get value: " << value << std::endl;
    } else {
        std::cerr << "Get failed: " << status.ToString() << std::endl;
    }

    delete db;
    return 0;
}