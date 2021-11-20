This is a demo for makefile test & debian make deb.
make -j
# 使用方式
llcmd --help
# 清理
make clean

# make deb
cd llcmd-1.0.0
dh_make --createorig -sy
dpkg-source -b .
cd ..
sudo pbuilder --build  --logfile log.txt --basetgz /var/cache/pbuilder/stable.tgz --allow-untrusted --hookdir /var/cache/pbuilder/hooks --use-network yes --aptcache "" --buildresult . --debbuildopts -sa *.dsc
＃对生成的deb进行检查
lintian -c *.changes
说明：最后一步命令实际上调用的是　dpkg-buildpackage -rfakeroot
登陆纯净环境（登陆后可以安装依赖包\添加仓库源等）
sudo pbuilder login --basetgz /var/cache/pbuilder/stable.tgz --save-after-login