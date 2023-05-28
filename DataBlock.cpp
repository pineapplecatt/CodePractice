#include <iostream>
#include <vector>
using namespace std;

class DataBlock {
   public:
    int* data;
    static const int blockSize = 1000;
    string str;

    DataBlock(string s)
        : data(new int[blockSize]) {
        this->str = s;
        cout << str << " Constructor being invoked!" << endl;
    }

    // Complete copy
    DataBlock(const DataBlock& db)
        : data(new int[blockSize]) {
        this->str = db.str;
        for (int i = 0; i < blockSize; i++) {
            this->data[i] = db.data[i];
        }

        cout << str << " Copy Constructor being invoked!" << endl;
    }

    // Move Constructor
    DataBlock(DataBlock&& db) noexcept {
        this->data = db.data;
        db.data = nullptr;
        cout << str << " Move Constructor being invoked!" << endl;
    }

    ~DataBlock() {
        if (this->data != nullptr) {
            delete[] data;
            data = nullptr;
        }

        cout << str << " Destructor being invoked!" << endl;
    }
};

int main() {
    vector<DataBlock> dbVec;
    dbVec.push_back(DataBlock("First"));
    cout << "=====================================" << endl;
    dbVec.push_back(DataBlock("Second"));
    cout << "=====================================" << endl;
    dbVec.push_back(DataBlock("Third"));
}