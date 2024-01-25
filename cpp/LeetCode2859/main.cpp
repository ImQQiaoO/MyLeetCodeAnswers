#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
	int sumIndicesWithKSetBits(vector<int> &nums, int k) {
		int res = 0;
		for (size_t i = 0; i < nums.size(); ++i) {
			bitset<10> binary(i);
			if (binary.count() == static_cast<size_t>(k)) {
				res += nums[binary.to_ulong()];
			}
		}
		return res;
	}
};

int main() {
	// nums = [5, 10, 1, 5, 2], k = 1
	Solution s0;
	vector<int> nums0 = {5, 10, 1, 5, 2};
	int k0 = 1;
	int ans0 = s0.sumIndicesWithKSetBits(nums0, k0);
	cout << ans0 << endl;

	// nums = [4,3,2,1], k = 2
	Solution s1;
	vector<int> nums1 = {4, 3, 2, 1};
	int k1 = 2;
	int ans1 = s1.sumIndicesWithKSetBits(nums1, k1);
	cout << ans1 << endl;

	return 0;
}
