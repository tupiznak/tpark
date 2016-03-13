cd /home/iping/wl;
rm built-in.o;
rm Makefile;
rm Module.symvers;
rm modules.order;
rm wl.ko;
rm wl.mod.c;
rm wl.mod.o;
rm wl.o;
rm -rf lib;
rm -rf src;
tar xzf hybrid-v35_64-nodebug-pcoem-6_30_223_271.tar.gz;
make clean;
make;
make API=CFG80211;
rmmod ssb;
rmmod wl;	
echo "blacklist ssb" >> /etc/modprobe.d/blacklist.conf;
modprobe lib80211;
modprobe cfg80211;
insmod wl.ko;


