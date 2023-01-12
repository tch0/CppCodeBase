# 测试组件

## [TestUtil.hpp](TestUtil.hpp)

- `parseDetailFlag`，`-all`选项输出所有通过与未通过的测试用例结果，`-fo`只输出未通过的测试用例结果，不带选项则只输出最终通过与未通过的测试用例数量统计。
- `TestUtil`用于测试类。
- 需要支持C++20。
- 用法：
```C++
#include "TestUtil.hpp"
int main(int argc, char const *argv[])
{
    auto detail = parseDetailFlag(argc, argv); // -all for passed and failed details, -fo for failed details only
    TestUtil util(detail, "infomation");
    {
        ...
        util.assertEqual(xxx, yyy);
        util.assertSequenceEqual(s1, s2);
        util.assertSorted(begin, end, comp);
        ...
    }
    util.showFinalResults();
    std::cout << std::endl;
    return 0;
}
```