#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class vertex {
private:
	int num, weight;
public:
	vertex(int n, int w) { num = n; weight = w; }
	int get_num() { return num; }
	int get_weight() { return weight; }
};

struct cmp
{
	bool operator()(vertex &a, vertex &b) const
	{
		//因为优先出列判定为!cmp，所以反向定义实现最小值优先
		return a.get_weight() > b.get_weight();
	}
};

int main() {
	priority_queue<vertex, vector<vertex>, cmp> pq;
	vertex v1(1, 2);
	vertex v2(2, 4);
	vertex v3(3, 1);
	vertex v4(4, 7);
	vertex v5(5, 5);
	vertex v6(6, 6);
	pq.push(v1);
	pq.push(v2);
	pq.push(v3);
	pq.push(v4);
	pq.push(v5);
	pq.push(v6);
	for (int i = 0; i < 6; ++i) {
		vertex temp = pq.top();
		cout << temp.get_weight() << endl;
		pq.pop();
	}
	return 0;
}