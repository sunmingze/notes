---
title: Shell 脚本示例
tags:
	- Shell
	- Linux
categories:
	- Linux
---

# 字符串

## 拼接

```shell
#### 1
"adgfdf""ccc"

#### 2
a="abc"
b="cde"
echo $a$b
abccde
```

# 循环

# 参数

# 路径

## 获取绝对路径

```shell
$ readlink -f ../../ctr-score
/home/work/sunzhenkai/Git/ctr-score
$ link=`readlink -f ../../ctr-score`
$ echo $link
/home/work/sunzhenkai/Git/ctr-score
```

## 打印当前目录下所有文件

```shell
###### 1
for file in *; do echo ${file}; done;
# 示例输出
test-01.sh
test-02.sh
test-03.sh

###### 2
for file in `ls`; do echo ${file}; done;
# 示例输出
test-01.sh
test-02.sh
test-03.sh
```

## 获取当前工作路径

```shell
### 1
# `pwd`
bovenson@ThinkCentre:~$ echo `pwd`
/home/bovenson

### 2
# ${PWD} or $PWD
bovenson@ThinkCentre:~$ echo ${PWD}
/home/bovenson
bovenson@ThinkCentre:~$ echo $PWD
/home/bovenson
```

## 获取脚本相对路径

获取脚本相对于当前工作路径的路径。

```shell
$(dirname $0)
```

## 获取脚本绝对路径

```shell
${PWD}/$(dirname $0)
```

```shell
bovenson@ThinkCentre:~/Tmp$ pwd
/home/bovenson/Tmp
bovenson@ThinkCentre:~/Tmp$ cat a/b/c/test.sh
#########################################################################
# File Name: a/b/c/test.sh
# Author: bovenson
# Email:  szhkai@126.com
# Created Time: 2017-09-21 10:07:32
#########################################################################
#!/bin/bash

BASEDIR=$(dirname $0)
FULLPATH="${PWD}/$(dirname $0)"

echo "PWD:      $PWD"
echo "BASEDIR:  $BASEDIR"
echo "FULLPATH: $FULLPATH"

bovenson@ThinkCentre:~/Tmp$ bash a/b/c/test.sh 
PWD:      /home/bovenson/Tmp
BASEDIR:  a/b/c
FULLPATH: /home/bovenson/Tmp/a/b/c
```

## 获取脚本所在目录

```shell
#### bash 获取执行的脚本所在的路径
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
```



## 更改PWD为文件所在路径

```shell
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

#### 有问题的版本
# FULLPATH="$PWD/$(dirname $0)"	# 提取路径
# cd "$FULLPATH"					# 更改pwd
```

## 提取文件路径

```shell
bovenson@MBP:~/Git/notes/Linux/Script$ echo $(dirname "/hello/sd.java")
/hello
bovenson@MBP:~/Git/notes/Linux/Script$ echo $(dirname "~/hello/sd.java")
~/hello
```
# 其他

## 执行脚本

```shell
$command
eval $command
`$command`

#### 上面三条命令是有区别的
bovenson@ThinkCentre:/home/public/Git/notes/Java/JavaNotes$ command="echo string"
bovenson@ThinkCentre:/home/public/Git/notes/Java/JavaNotes$ $command
string
bovenson@ThinkCentre:/home/public/Git/notes/Java/JavaNotes$ eval $command
string
bovenson@ThinkCentre:/home/public/Git/notes/Java/JavaNotes$ `$command`
```

## 只不删除特定文件

删除除例外文件外所有文件及文件夹。

```shell
#### 1
find . ! -name 'filename-pattern' -type f -exec rm -f {} +
# 删除除匹配'filename-pattern'外的所有常规文件(!递归删除所有文件只剩文件夹, 包括隐藏文件)
# 如果要删除文件夹, 把 -type f 改为 -type d, rm -f 改为 rm -rf
```

## 解压多个文件

```shell
bovenson@ThinkCentre:~/Git/Tianchi/o2o/input$ ls
ccf_offline_stage1_test_revised.zip  ccf_offline_stage1_train.zip  ccf_online_stage1_train.zip	sample_submission.zip
bovenson@ThinkCentre:~/Git/Tianchi/o2o/input$ for i in $(ls *.zip); do
> unzip $i
> done
Archive:  ccf_offline_stage1_test_revised.zip
  inflating: ccf_offline_stage1_test_revised.csv  
Archive:  ccf_offline_stage1_train.zip
  inflating: ccf_offline_stage1_train.csv  
Archive:  ccf_online_stage1_train.zip
  inflating: ccf_online_stage1_train.csv  
Archive:  sample_submission.zip
  inflating: sample_submission.csv   
bovenson@ThinkCentre:~/Git/Tianchi/o2o/input$ 
```

**单独Shell脚本**

```shell
#!/bin/bash
for i in $(ls *.zip 2>/dev/null)
do
    unzip $i
done
```

## 后台执行并重定向输出

新建文件`mstart`, 写入下面代码.

```bash
#!/bin/bash
$1 1>/etc/null 2>&1 &
```

**说明**

- `1>/etc/null`将标准输出(`stdout`)重定向到空设备文件,也可以重定向到文件,即将标准输出输出到指定文件(例如:`1>~/myapplog`)
- `2>&1` 把标准错误(`stderr`)输出重定向到标准输出(`stdout`), 也可以重定向到其他位置.
- `&` 将程序设置在后台运行

**使用**

- 首先更改权限

  `chmod a+x ./mstart`

- 将文件`mstart`放到环境变量中(需要使新设置的环境变量生效, 如:`source /etc/profile`(如果实在`/etc/profile`文件中配置的PATH的话))

- 使用`mstart`命令启动`gedit`

  `mstart gedit`

**这样就可以在后台启动一个程序,且不会在控制台打印程序的输出信息.**