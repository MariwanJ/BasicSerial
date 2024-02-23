mkdir -p build;
cd build;
cmake .. -GNinja -DCMAKE_BUILD_TYPE=Develop -DMBED_TARGET=NUCLEO_F207ZG && ninja -j20;
cd ..;