# 说明

This is a demo for makefile test & debian make deb.

# 使用方式

make -j


llcmd --help

# 清理

make clean

# 制作deb安装包make deb

cd llcmd-1.0.0


dh_make --createorig -sy


dpkg-source -b .


cd ..


sudo pbuilder --build  --logfile log.txt --basetgz /var/cache/pbuilder/stable.tgz --allow-untrusted --hookdir /var/cache/pbuilder/hooks --use-network yes --aptcache "" --buildresult . --debbuildopts -sa *.dsc


＃对生成的deb进行检查

lintian -c *.changes

# 注意事项

最后一步命令实际上调用的是dpkg-buildpackage -rfakeroot


登陆纯净环境（登陆后可以安装依赖包\添加仓库源等）
sudo pbuilder login --basetgz /var/cache/pbuilder/stable.tgz --save-after-login

注意deb包源码文件的命名规则：模块名+版本号（llcmd-1.0.0）

# 参考文档

deb包的构建(dpkg-buildpackage)过程详细过程说明

[https://blog.csdn.net/yygydjkthh/article/details/36902781]()

helloworld deb包制作

[https://blog.csdn.net/mountzf/article/details/51863859]()

使用lintian检测制作完成的deb包

[https://blog.csdn.net/qq_33154343/article/details/106366582](https://blog.csdn.net/qq_33154343/article/details/106366582)

Debian制作deb包官方指导

[https://www.debian.org/doc/manuals/maint-guide/index.zh-cn.html](https://www.debian.org/doc/manuals/maint-guide/index.zh-cn.html)

[https://www.debian.org/doc/manuals/debmake-doc/](https://www.debian.org/doc/manuals/debmake-doc/)
