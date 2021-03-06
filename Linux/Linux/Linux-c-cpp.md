# fork

- **fork()给子进程返回一个零值，而给父进程返回一个非零值**

  fork()是一个分叉函数， 返回值： 若成功调用一次则返回两个值，子进程返回0，父进程   返回子进程标记；否则，出错返回-1

  ```c
  int main{
      fork() || fork()
  }

  // 共创建了3个进程
  ```

  ​


- 一个进程，包括代码、数据和分配给进程的资源。fork（）函数通过系统调用创建一个与原来进程几乎完全相同的进程，也就是两个进程可以做完全相同的事，但如果初始参数或者传入的变量不同，两个进程也可以做不同的事。
- 一个进程调用fork（）函数后，系统先给新的进程分配资源，例如存储数据和代码的空间。然后把原来的进程的所有值都复制到新的新进程中，只有少数值与原来的进程的值不同。相当于克隆了一个自己。
- 使用fork函数得到的子进程从父进程的继承了整个进程的地址空间，包括：
  - 用户号UIDs和用户组号GIDs
  - 环境Environment
  - 堆栈
  - 共享内存
  - 打开文件的描述符
  - 执行时关闭（Close-on-exec）标志
  - 信号（Signal）控制设定
  - 进程组号
  - 当前工作目录
  - 根目录
  - 文件方式创建屏蔽字
  - 资源限制
  - 控制终端
- 与父进程的区别:
  - 父进程设置的锁，子进程不继承（因为如果是排它锁，被继承的话，矛盾了）
  - 各自的进程ID和父进程ID不同
  - 子进程的未决告警被清除；
  - 子进程的未决信号集设置为空集。
- 子进程独有:
  - 进程号PID
  - 不同的父进程号
  - 自己的文件描述符和目录流的拷贝
  - 子进程不继承父进程的进程正文（text），数据和其他锁定内存（memory locks）
  - 不继承异步输入和输出
- 父进程和子进程拥有独立的地址空间和PID参数
- 子进程无法读取父进程的数据
- 经过fork()以后，父进程和子进程拥有相同内容的代码段、数据段和用户堆栈，就像父进程把自己克隆了一遍。事实上，父进程只复制了自己的PCB块。而代码段，数据段和用户堆栈内存空间并没有复制一份，而是与子进程共享。只有当子进程在运行中出现写操作时，才会产生中断，并为子进程分配内存空间。由于父进程的PCB和子进程的一样，所以在PCB中断中所记录的父进程占有的资源，也是与子进程共享使用的。这里的“共享”一词意味着“竞争”

## 示例

```c
//// 1
#include <stdio.h>
int main()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        fork();
        printf("*\n");
    }
    return 0;
}
// 输出: 14个 *

//// 2
#include <stdio.h>
int main()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        fork();
        printf("*\n");
    }
    return 0;
}
// 输出: 14个*

//// 3
#include <stdio.h>

int main()
{
    int i;
    for (i = 0; i < 3; ++i)
    {
        printf("*\n");
        fork();
    }
    return 0;
}
// 输出: 7个*
```

## 参考

- [参考一](http://blog.csdn.net/myarrow/article/details/8995091)
- [参考二](https://www.nowcoder.com/questionTerminal/553c29f704434152b2e2ebacb979a211)
- [参考三](http://www.cnblogs.com/bastard/archive/2012/08/31/2664896.html)




# clone

- clone是fork的升级版本，不仅可以创建进程或者线程，还可以指定创建新的命名空间（namespace）、有选择的继承父进程的内存、甚至可以将创建出来的进程变成父进程的兄弟进程等等



# 文件

linux下面，一切都是文件

## 读写

Linux下对文件操作有两种方式：

- 系统调用(system call)

- 库函数调用(Library  functions)


系统调用实际上就是指最底层的一个调用，在linux程序设计里面就是底层调用的意思。面向的是硬件。而库函数调用则面向的是应用开发的，相当于应用程序的api。 

函数库调用是语言或应用程序的一部分，而系统调用是操作系统的一部分。

## 文件系统函数

| 函数       | 描述              |
| -------- | --------------- |
| fcntl    | 文件控制            |
| open     | 打开文件            |
| creat    | 创建新文件           |
| close    | 关闭文件描述字         |
| read     | 读文件             |
| write    | 写文件             |
| readv    | 从文件读入数据到缓冲数组中   |
| writev   | 将缓冲数组里的数据写入文件   |
| pread    | 对文件随机读          |
| pwrite   | 对文件随机写          |
| lseek    | 移动文件指针          |
| _llseek  | 在64位地址空间里移动文件指针 |
| dup      | 复制已打开的文件描述字     |
| dup2     | 按指定条件复制文件描述字    |
| flock    | 文件加/解锁          |
| poll     | I/O多路转换         |
| truncate | 截断文件            |
| umask    | 设置文件权限掩码        |
| fsync    | 把文件在内存中的部分写回磁盘  |

## 文件库函数

| 函数      | 描述           |
| ------- | ------------ |
| fwrite  | 将数据写入文件流     |
| putc    | 将一个字符写入文件流中  |
| putchar | 向终端输出一个字符    |
| getline | 从输入流中读入一个字符串 |
| scanf   | 格式输入函数       |



# 数据类型

| 数据类型          | 占用空间                             | 范围   |
| ------------- | -------------------------------- | ---- |
| char          | 1字节                              |      |
| * (指针变量)      | 等于系统字长(32位操作系统为4字节; 64位操作系统为8字节) |      |
| short int     | 2字节                              |      |
| int           | 4字节                              |      |
| unsigned int  | 4字节                              |      |
| float         | 4字节                              |      |
| double        | 8字节                              |      |
| long          | 8字节                              |      |
| unsigned long | 8字节                              |      |
| long long     | 8字节                              |      |

# sizeof

```c
#include <stdio.h>

int main()
{
	int intValue = 1024;
	char str[] = "hello";
	const char* ch = str;
	printf("%d\n", sizeof(intValue));	// 4
	printf("%d\n", sizeof(str));		// 6
	printf("%d\n", sizeof(ch));			// 8
	return 0;
}

// 输出:
4
6
8
```



# new/delete/malloc/free

- malloc/free 是C/C++语言的标准库函数，new/delete是C++的运算符

- new 能自动分配空间大小

- new初始化对象，调用对象的构造函数，malloc仅仅分配内存

- new、delete返回的是所分配类型变量（对象）的指针，malloc、free返回的是void指针

- 对于用户自定义的对象而言，用malloc/free无法满足动态管理对象的要求对象在创建的时候会自动调用构造函数，对象在消亡之前自动执行析构函数由于malloc/free是库函数而不是运算符，不在编译器的控制范围，不能把构造函数和析构函数的任务强加于malloc/free 。一次C++需要一个能够对对象完

  成动态分配内存和初始化工作的运算符new，以及一个释放内存的运算符delete。简单来说就是new/delete能完成跟家详细的对内存的操作，而malloc/

  free不能。

# END