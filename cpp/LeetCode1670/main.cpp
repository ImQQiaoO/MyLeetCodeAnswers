#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class FrontMiddleBackQueue {

    vector<int> _data;

public:
    FrontMiddleBackQueue() = default;

    void pushFront(int val) {
        _data.insert(_data.begin(), val);
    }

    void pushMiddle(int val) {
        _data.insert(_data.begin() + _data.size() / 2, val);
    }

    void pushBack(int val) {
        _data.push_back(val);
    }

    int popFront() {
        if (_data.empty()) {
            return -1;
        }
        auto res = _data.front();
        _data.erase(_data.begin());
        return res;
    }

    int popMiddle() {
        if (_data.empty()) {
            return -1;
        }
        if (_data.size() % 2 == 0) {
            auto res = _data[_data.size() / 2 - 1];
            _data.erase(_data.begin() + _data.size() / 2 - 1);
            return res;
        }
        auto res = _data[_data.size() / 2];
        _data.erase(_data.begin() + _data.size() / 2);
        return res;
    }

    int popBack() {
        if (_data.empty()) {
            return -1;
        }
        auto res = _data.back();
        _data.pop_back();
        return res;
    }


    void debug() {
        cout << "Debug info: ";
        for (auto i : _data) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    auto q = new FrontMiddleBackQueue();
    q->pushFront(1);
    q->pushBack(2);
    q->pushMiddle(3);
    q->pushMiddle(4);
    q->debug();
    cout << q->popFront() << endl;
    q->debug();
    cout << q->popMiddle() << endl;
    q->debug();
    cout << q->popMiddle() << endl;
    q->debug();
    cout << q->popBack() << endl;
    cout << q->popFront() << endl;
    return 0;
}
