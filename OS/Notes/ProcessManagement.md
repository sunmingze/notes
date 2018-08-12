---
title: 进程管理
tags:
	- 进程管理
categories:
	- 操作系统
---

# 并发

- 程序并发执行的特征
  - 间断性
  - 失去封闭性
    - 一个程序在运行时，其环境会受到其他程序的影响
  - 不可再现性

# 进程

## 定义

- 进程是程序的一次执行
- 进程是一个程序及其数据在处理机上顺序执行时所发生的活动
- 进程是具有独立功能的程序在一个数据集合上运行的过程，它是系统进行资源分配和调度的一个独立单位

## 进程控制块

为了使参与并发执行的每个程序（含数据）都能独立地运行，在操作系统中必须为之配置一个专门的数据结构，称为**进程控制块（Process Control Block，PCB）**。

系统利用PCB来描述进程的基本情况和活动过程，进而控制和管理进程。

## 进程实体

进程实体（又称进程映像）构成：

- 程序段
- 相关数据段
- PCB

所谓创建/撤销进程，实质上是创建/撤销进程实体中的PCB。

## 特征

- 动态性
  - 进程的实质是进程实体的执行过程
  - 体现
    - 由创建而产生
    - 由调度而执行
    - 由撤销而消亡
- 并发性
- 独立性
  - 进程实体是一个独立的单位参与运行和独立接受调度的基本单位
- 异步性
  - 进程按各自独立的、不可预测的速度向前推进

# 状态及转换

## 状态

- 就绪（Ready）状态
  - 进程准备好运行的状态，即已分配到处CPU以外的所有必要资源
- 执行状态
- 阻塞状态
  - 正在执行的进程由于发生某事件（I/O请求、申请缓冲区失败等）暂时无法继续执行时的状态
  - 即进程执行收到阻塞
  - 会引起进程调度
- 创建状态
  - **进程创建步骤**
    - 由进程申请空白PCB
    - 向PCB中填写用于控制和管理进程的信息
    - 为该进程分配运行时所必须的资源
    - 把该进程转入就绪状态并插入就绪队列中
  - 如果在创建过程中不能满足所需的资源，则创建工作无法完成，此时的状态称为创建状态
- 终止状态
  - 进程终止的步骤
    - 等待操作系统进行善后处理
    - 将其PCB清零，并将PCB空间返还系统
  - 当一个进程到达了自然结束点或出现了无法克服的错误，或被操作系统终结，或被其他进程所终结，将进入终止状态

![](imgs/01.jpg)

## 挂起操作

挂起状态是指进程处于静止状态，不接受调度。引入挂起操作的原因：

- 终端用户的需要
- 父进程的需要
- 负荷调度的需要
- 操作系统的需要

引入挂起原语（Suspend）和激活原语（Active）后，进程状态的转换：

- 活动就绪 -> 静止就绪
- 活动阻塞 -> 静止阻塞
- 静止就绪 -> 活动就绪
- 静止阻塞 -> 活动阻塞

![](imgs/02.jpg)
