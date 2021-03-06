# 概念

## CPU

- 提高指令级并行能力
- 在一个时钟周期内执行更多指令
- 向量技术
- 多核
- 超线程

## 超线程技术

利用特殊硬件指令，把两个逻辑内核(CPU core)模拟成两个物理芯片，让单个处理器都能使用线程级并行计算，进而兼容多线程操作系统和软件，减少了CPU的闲置时间，提高的CPU的运行效率。

这种模拟的硬件基础是，双倍增加一些资源（PC和寄存器），减少线程的切换代价。但是执行单元只有一份，因此CPU峰值计算能力并没有提升。

可并行执行两个线程，能够在单个时针周期内在两个线程间切换。

## 并行（parallelism）

具有多个处理单元的系统上，通过将计算或数据划分为多个部分，将各个部分分配到不同的处理单元上，各处理单元相互协作，同时运行，已达到加快求解速度或者提高求解问题规模的目的。

## 并发（concurrency）

并发是指在一个处理单元上运行多个应用，各应用分时占用处理单元，是一种微观上串行、宏观上并行的模式，有时也称其为时间上串行、空间上并行。

## 代码性能优化

通过调整代码，使其生成的机器指令能够更高效地执行，通常高效是指执行时间更少、使用的存储器更少或能够计算更大规模的问题。

## 向量化

使用同一条指令同时操作多个数据。

## 多路

集成多个多核处理器。

## 指令级并行

同时对多条指令求值。

**指令级并行能够利用处理器上的不同组件同时工作**，如果程序具有类型丰富的运算，指令级并行能使处理器性能迅速提高。

# 其他

## 线程过多

- 引起缓存命中率降低
- 带来大量冗余计算和IO操作