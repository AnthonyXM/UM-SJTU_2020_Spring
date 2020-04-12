echo "---------- Compile module 3 ----------"
make
echo "----------- Load module 3 -----------"
sudo insmod module3.ko
lsmod | head -2
dmesg | tail -1
echo "---- Show the content of module3 ----"
cat /proc/module3
echo "---------- Remove module 3 ----------"
sudo rmmod module3.ko
dmesg | tail -1
echo "--------------- Clean ---------------"
make clean
