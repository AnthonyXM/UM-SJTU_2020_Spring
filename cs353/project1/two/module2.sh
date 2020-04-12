echo "---------- Compile module 2 ----------"
make
echo "----------- Load module 2 -----------"
sudo insmod module2.ko int_param=10 char_param=hello array_param=1,3,5,7,9
lsmod|head -2
dmesg|tail -8
echo "---------- Remove module 2 ----------"
sudo rmmod module2.ko
dmesg|tail -1
echo "--------------- Clean ---------------"
make clean
