#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class SmallestInfiniteSet {
public:
    set<int> s;

    SmallestInfiniteSet() {
        s.clear();
        for (int i = 1; i <= 1010; i++)
            s.insert(i);
    }

    int popSmallest() {
        int x = *s.begin();
        s.erase(s.begin());
        return x;
    }

    void addBack(int num) {
        s.insert(num);
    }
};


int main() {
    SmallestInfiniteSet *s = new SmallestInfiniteSet();
    s->addBack(2);
    cout << s->popSmallest() << endl;
    cout << s->popSmallest() << endl;
    cout << s->popSmallest() << endl;
    s->addBack(1);
    cout << s->popSmallest() << endl;
    cout << s->popSmallest() << endl;
    cout << s->popSmallest() << endl;
    return 0;
}
