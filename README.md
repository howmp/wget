# wget

## 使用

`usage: wget url filepath`

wget.exe https://www.qq.com 1.html

### 缓存问题

添加一个随机参数

wget.exe https://www.qq.com/?ts=11111 1.html

## 下载

<https://github.com/howmp/wget/blob/main/wgetmini.exe>

## 编译

1. 用VC6编译
1. 删除文件尾部\x00
1. patch
   1. PE的DOS_STUB,将两个字符串常量覆盖
   1. 根据偏移修改printf附近的汇编代码指向常量
   

## 更新

### 2024年12月13日

根据大佬[Laster-dev](https://github.com/Laster-dev)的指点，优化大小

1024 -> 862