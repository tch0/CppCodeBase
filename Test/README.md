# 测试组件

## [TestUtil.hpp](TestUtil.hpp)

- `parseDetailFlag`，`-d`选项输出详细信息。
- `TestUtil`用于测试类。
- 需要支持C++20。
- 用法：
```C++
#include "TestUtil.hpp"
int main(int argc, char const *argv[])
{
    bool showDetails = parseDetailFlag(argc, argv); // -d for detail informations
    TestUtil util(showDetails, "infomation");
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