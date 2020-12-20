# LightGBM-predictor-cpp

### 1. Build LightGBM
```bash
git clone --recursive --branch stable --depth 1 https://github.com/Microsoft/LightGBM && \
    mkdir LightGBM/build && \
    cd LightGBM/build && \
    cmake .. && \
    make -j4 && \
    make install && \
```

### 2. Build test.cpp
```bash
g++ -g -Wall -std=c++11 test.cpp -l_lightgbm -Wl,-R /usr/local/lib -o test
```

### 3. Run
```bash
./test
```
### 4. Output
```
Load model success!
Predict state: 0
Predict size: 1 , result: 0.870713
###########################
Predict state: 0
Predict size: 1 , result: 0.472528
Success!
```
