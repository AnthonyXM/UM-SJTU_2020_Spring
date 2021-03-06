echo "---------- Compile module 4 ----------"
make
echo "----------- Load module 4 -----------"
sudo insmod module4.ko
lsmod | head -2
dmesg | tail -1
echo "---- Show the content of module4 ----"
cat /proc/module4_dir/module4
echo "--------- Write to module4 ---------"
echo "new module4 text" > /proc/module4_dir/module4
echo "-- Show the new content of module4 --"
cat /proc/module4_dir/module4
echo "---------- Remove module 4 ----------"
sudo rmmod module4.ko
dmesg | tail -1
echo "--------------- Clean ---------------"
make clean
