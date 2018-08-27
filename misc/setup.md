# OPENCV  compile and install
cmake   -D CMAKE_BUILD_TYPE=RELEASE   -D CMAKE_INSTALL_PREFIX=/usr/local  -D BUILD_TIFF=ON  -D WITH_TIFF=ON  -D WITH_TBB=ON   -D WITH_V4L=ON   -D WITH_QT=ON   -D WITH_OPENGL=ON   -D WITH_CUDA=ON   -D ENABLE_FAST_MATH=1   -D CUDA_FAST_MATH=1   -D CUDA_NVCC_FLAGS="-D_FORCE_INLINES"   -D WITH_CUBLAS=1 -D WITH_OPENMP=ON ..

make -j8  
sudo make make install  

# python
pip install scrapy -i https://pypi.tuna.tsinghua.edu.cn/simple
# QT
## Download
wget http://mirrors.ustc.edu.cn/qtproject/archive/qt/5.6/5.6.2/qt-opensource-linux-x64-5.6.2.run
## install
sudo ./qt-opensource-linux-x64-5.6.2.run
chmod +x qt-opensource-linux-x64-5.6.2.run
## set library path in .bashrc
export LD_LIBRARY_PATH="/home/xd/Qt5.6.2/5.6/gcc_64/lib/:$LD_LIBRARY_PATH"
export QT_PLUGIN_PATH=/home/xd/Qt5.6.2/5.6/gcc_64/plugins/platforms

# PCL
```
sudo apt-get install libpcl-dev
sudo apt-get install pcl-tools
```
I had the exact same error after installing from the same source. I finally tracked down the error to a wrong entry in the PCLConfig.cmake file. The PCL_ROOT variable there is beeing set to /usr/local, while the files were actually installed into /usr. Changing this variable resolved the problem for me.

Error: /usr/bin/ld: cannot find -lvtkproj4
solution:
```
list(REMOVE_ITEM PCL_LIBRARIES “vtkproj4”)
```

# Ceres
http://ceres-solver.org/installation.html

# g2o
The latest master branch incorporates changes that are API incompatible.

# Pangolin
//usr/lib/x86_64-linux-gnu/libsoxr.so.0: undefined reference to 'GOMP_parallel@GOMP_4.0'  
The problem has been solved. It is due to Anaconda.  
Delete Anaconda from $PATH and LD_LIBRARY_PATH

# ORB_SLAM2
compiling error:
> /usr/local/lib/libopencv_calib3d.so.3.3.1: undefined reference to `GOMP_parallel@GOMP_4.0'

add /usr/lib/x86_64-linux-gnu/ to $LD_LIBRARY_PATH
But I wrong typed /lib/ into /local/
fix it and works.
