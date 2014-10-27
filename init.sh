#!/bin/sh
echo "帮助您自动生成可发布的源码包..."

echo "1、调用autoconf等标准工具"
autoreconf --install
if test $? != 0 ; then
echo "缺少标准开发工具autoconf libtool，请先安装开发工具"
exit 1
fi

echo "2、调用./configure脚本自动完成各项检查"
./configure
if test $? != 0 ; then
echo "缺少开发库，请参考README文档安装所有开发工具"
echo "Please install pkg-config libssl-dev"
exit 2
fi

