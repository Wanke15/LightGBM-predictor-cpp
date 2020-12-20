# LightGBM-predictor-cpp

### 1. Build LightGBM
```bash
git clone --recursive --branch stable --depth 1 https://github.com/Microsoft/LightGBM && \
    mkdir LightGBM/build && \
    cd LightGBM/build && \
    cmake .. && \
    make -j8 && \
    make install && \
```

### 2. Train a binary classification model
```bash
cd LightGBM/examples/binary_classification &&
    lightgbm config=train.conf
```
We will get the output model: **LightGBM_model.txt**, it will be used in test.cpp

### 3. Build test.cpp
In test.cpp, **row** and **row2** are from *LightGBM/examples/binary_classification/binary.train*
```bash
g++ -g -Wall -std=c++11 test.cpp -l_lightgbm -Wl,-R /usr/local/lib -o test
```

### 4. Run
```bash
./test
```
### 5. Output
```
Load model success!
Predict state: 0
Predict size: 1 , result: 0.870713
###########################
Predict state: 0
Predict size: 1 , result: 0.472528
Success!
```
