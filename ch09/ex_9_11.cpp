#include <vector>
using std::vector;

vector<int> v1; //默认构造函数
vector<int> v2(v1); //拷贝v1元素
vector<int> v3 = v1; //如上
vector<int> v4 {2,3,4,5,1}; //列表初始化
vector<int> v5(v1.begin(), v1.end());
vector<int> v6(10); //十个int，值都为0
vector<int> v7(10, 1); //十个int，值都为1
