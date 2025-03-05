#include <iostream>
#include <vector>
#include "rocksdb/db.h"
#include <faiss/IndexFlat.h>
#include <boost/asio/thread_pool.hpp>


int main() {
    boost::asio::thread_pool pool(10);
    std::cout <<"213";
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


// ----------------------------------faiss----------------------------
    // 定义向量的维度（例如：128维）
    int d = 128;

    // 创建一个Flat索引（最简单的索引类型）
    faiss::IndexFlat index(d);

    // 准备一些要添加到索引中的向量（这里使用随机向量作为示例）
    int nb = 10000;  // 向量数量
    std::vector<float> xb(d * nb);
    for (int i = 0; i < xb.size(); i++) {
        xb[i] = static_cast<float>(rand()) / RAND_MAX;
    }

    // 将向量添加到索引中
    index.add(nb, xb.data());

    // 准备查询向量
    int nq = 5;  // 查询向量数量
    std::vector<float> xq(d * nq);
    for (int i = 0; i < xq.size(); i++) {
        xq[i] = static_cast<float>(rand()) / RAND_MAX;
    }

    // 执行搜索
    int k = 4;  // 返回最相似的k个向量
    std::vector<faiss::idx_t> I(nq * k); // 修正这里
    std::vector<float> D(nq * k);
    index.search(nq, xq.data(), k, D.data(), I.data());

    // 输出搜索结果
    for (int i = 0; i < nq; i++) {
        std::cout << "查询向量 " << i << " 的最相似向量是：" << std::endl;
        for (int j = 0; j < k; j++) {
            std::cout << "  ID: " << I[i * k + j] << ", 距离: " << D[i * k + j] << std::endl;
        }
    }

// ----------------------------------faiss----------------------------

    return 0;
}
