# DynamicSymbols C++实现动态类型管理

## 学习了部分Python源码后，尝试自己实现一个动态类型的变量管理
## 主要用于本人正在维护的一款解释器

目前具备 bool, byte, int, double, string, struct类型功能，每种类型都有自己对应的内存池

VarBase  
|  
|—BoolObject  
|—ByteObject  
|—IntObject  
|—DoubleObject  
|—StringObject  
|—StructObject  
|—(todo ArrayObject)  
    
除了StringObject、StructObject、ArrayObject，其余类型都重载了基本能直接通过VarBase的运算接口与其他类型进行运算（包括四则运算、逻辑运算、大小比较等）

TODO List
+ [ ] 1.ArrayList
+ [ ] 2.错误回收机制
