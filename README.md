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

（执行dpkg-source -b .命令后也可以使用dpkg-buildpackage -us -uc -nc基于当前宿主机环境打包，pbuilder是拉一起纯净环境打包）

cd ..

```bash
sudo pbuilder --build  --logfile log.txt --basetgz /var/cache/pbuilder/stable.tgz --allow-untrusted --hookdir /var/cache/pbuilder/hooks --use-network yes --aptcache "" --buildresult . --debbuildopts -sa *.dsc
```

＃对生成的deb进行检查

lintian -c *.changes

# 注意事项

最后一步命令实际上调用的是dpkg-buildpackage -rfakeroot


登陆纯净环境（登陆后可以安装依赖包\添加仓库源等）
sudo pbuilder login --basetgz /var/cache/pbuilder/stable.tgz --save-after-login

注意deb包源码文件的命名规则：模块名+版本号（llcmd-1.0.0）

构建64位打包环境：

```bash
sudo pbuilder create --mirror "http://pools.uniontech.com/desktop-professional" --distribution "eagle" --basetgz /var/cache/pbuilder/base.tgz --allow-untrusted --debootstrapopts --include=debian-archive-keyring 
```

参数解释：

--mirror :指定构建仓库

--distribution :指定codename

--basetgz: 指定构建base路径及文件名

--keyring: 指定仓库公钥位置及文件

--include: 添加除debootstrap外自定义软件包列表，用','隔开。

注：如果是构建deepin仓库，因为deepin-keyring不在debootstrap列表，所以必须加到--include里面。不然编译过程因为base环境没有公钥，可能无法使用deepin签名仓库。

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
