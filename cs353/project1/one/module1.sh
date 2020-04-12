echo "--------- Compile module 1 ---------"
make
echo "---------- Load module 1 ----------"
sudo insmod module1.ko
lsmod | head -2
dmesg | tail -1
echo "---------- Remove module 1 ----------"
sudo rmmod module1.ko
dmesg | tail -1
echo "--------------- Clean ---------------"
make clean
