# Build

```
mkdir build
cd build
conan install ..
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake -build .
```

# Test

Ensure build steps have been run and then use `ctest`.

```
# cd build
ctest
```
