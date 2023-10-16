## Here‘s what yuuki did：

### In feature：

1. **多种食物**：在原来基础上增加了两种不同分数的食物类型。
2. \***多个食物**：每次刷新出三个食物，只有在场所有食物吃完之后才会进行刷新（同时刷新障碍）。



#### In code:

1. **多种食物**：printfood函数中，更改了flag为not_permitted，添加了一些注释，增强了可读性。
2. \***多个食物**：大幅改动了printfood和movesnake函数，将char foodTypes[]数组放到全局，头文件定义#define FOOD_COUNT 3  等





注：带”\*“标识表示此任务在书本给出要求范围之外。