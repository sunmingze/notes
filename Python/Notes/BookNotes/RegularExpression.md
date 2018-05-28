[TOC]

# 正则表达式

## 简介

-   **正则表达式** 是包含文本和特殊字符的字符串, 为高级的文本模式匹配, 抽取, 与文本形式的搜索和替换功能提供了基础
-   `Python`通过标准库`re`模块来支持正则表达式
-   模式匹配的两种方法完成**匹配(模式匹配)**
    -   搜索(`search()`)
    -   匹配(`match()`)

## 元字符(特殊符号和字符)

### 符号

| 符号          | 描述                                                         | 示例                     |
| ------------- | ------------------------------------------------------------ | ------------------------ |
| *`literal`*   | 匹配文本字符串的字面值*literal*                              | foo                      |
| `re1\|re2`    | 匹配正则表达式`re1`和`re2`                                   | foo\|bar                 |
| `.`           | 匹配任何字符(除`\n`之外)                                     | f.o                      |
| `^`           | 匹配字符串起始部分                                           | ^foo                     |
| `$`           | 匹配字符串终止部分                                           | bar$                     |
| `*`           | 匹配0次或者多次前面出现的正则表达式                          | [A-Za-z0-9]*             |
| `+`           | 匹配1次或者多次前面出现的正则表达式                          | [a-z]+\\.com             |
| `?`           | 匹配0次或者1次前面出现的正则表达式                           | goo?                     |
| `{N}`         | 匹配N次前面出现的正则表达式                                  | [0-9]{3}                 |
| `{M,N}`       | 匹配M~N次前面出现的正则表达式                                | [0-9]{5,9}               |
| `[…]`         | 匹配来自字符集的任意单一字符                                 | [aeiou]                  |
| `[x-y]`       | 匹配x~y范围中的任意单一字符                                  | [0-9], [A-Za-z]          |
| `[^…]`        | 不匹配此字符集中出现的任何一个字符, 包括某一范围的字符       | [^aeiou], \[^A-Za-z]     |
| `(*|+|?|{})?` | 用于匹配上面频繁出现/重复出现符号的非贪婪版本`(*、+、？、{})` | `.*?[a-z]`               |
| `(…)`         | 匹配封闭的正则表达式，然后另存为子组                         | `([0-9]{3})?,f(oo|u)bar` |

### 特殊符号

| 符号 | 描述                                      | 示例          |
| ---- | ----------------------------------------- | ------------- |
| `\d` | 匹配任何十进制数字，与`[0-9]`一致         | `data\d+.txt` |
| `\D` | 与`\d`相反                                |               |
| `\w` | 匹配任何字母数字字符，与`[A-Za-z0-9]`相同 |               |
| `\W` | 与`\w`相反                                |               |
| `\s` | 匹配任何空格字符，与`[\n\t\r\v\f]`相同    |               |
| `\S` | 与`\s`相反                                |               |
| `\N` | 匹配已保存的子组 N                        | `price:\1`    |
| `\c` | 逐字匹配任何特殊字符`c`                   | `\.,\\,\*`    |
| `\A` | 匹配字符串起始，与`^`相同                 |               |
| `\Z` | 匹配字符串结束，与`$`相同                 |               |

### 扩展符号

| 符号              | 描述                                                         | 示例         |
| ----------------- | ------------------------------------------------------------ | ------------ |
| ` (?iLmsux) `     | 在正则表达式本身中嵌入一个或多个特殊**特殊**标记 (vs. via function/method) | `(?x),(?im)` |
| `(?:...)`         | 匹配一个不用保存的分组                                       | `(?:\w+\.)`  |
| ` (?P<name>...) ` | 使用名字表示的正则分组                                       | `(?P<data>)` |
|                   |                                                              |              |

# 参考

- 《Python 核心编程》