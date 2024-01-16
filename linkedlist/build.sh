rm -rf build
cmake -E make_directory build
cd build
cmake ..
cmake --build .
cd test
./test
