#include <LightGBM/c_api.h>
#include <iostream>
#include <vector>

class Predictor
{
private:
        BoosterHandle model;
        int FEATURE_LENGTH;

public:
        Predictor(std::string, int);
        std::vector<double> predict(std::vector<float>& input_data);
};

Predictor::Predictor(std::string model_path, int feature_num)
{
        int temp;
        int p=1;
        FEATURE_LENGTH = feature_num;
        temp = LGBM_BoosterCreateFromModelfile(model_path.data(), &p, &model);
        if (temp == 0)
        {
                std::cout << "Load model success!" << std::endl;
        }
        else
        {
                std::cerr << "Cannot load model!!!" << std::endl;
        }
}
std::vector<double> Predictor::predict(std::vector<float>& input_data)
{
        void* in_p = static_cast<void*>(input_data.data());
        std::vector<double> out(1, 0);
        double* out_result = static_cast<double*>(out.data());
        int64_t out_len;
        int res = LGBM_BoosterPredictForMat(model, in_p, C_API_DTYPE_FLOAT32, 1, FEATURE_LENGTH, 1, C_API_PREDICT_NORMAL, 0, -1, "None", &out_len, out_result);
        //std::cout << "Predict state: " << res << std::endl;
        //std::cout << "Predict size: " << out.size() << " , result: " << out[0] << std::endl;
        return out;
}

int main()
{
        std::string model_path = "LightGBM_model.txt";
        int feature_len = 28;
        Predictor predictor(model_path, feature_len);

        std::vector<float> row = { 0.869, -0.635, 0.226, 0.327, -0.690, 0.754, -0.249, -1.092, 0.000, 1.375, -0.654, 0.930, 1.107, 1.139, -1.578, -1.047, 0.000, 0.658, -0.010, -0.046, 3.102, 1.354, 0.980, 0.978, 0.920, 0.722, 0.989, 0.877 };
        std::vector<double> out1;
        out1 = predictor.predict(row);
        std::cout << "Predict size: " << out1.size() << " , result: " << out1[0] << std::endl;

        std::cout << "###########################" << std::endl;

        std::vector<float> row2 = { 1.344, -0.877, 0.936, 1.992, 0.882, 1.786, -1.647, -0.942, 0.000, 2.423, -0.676, 0.736, 2.215, 1.299, -1.431, -0.365, 0.000, 0.745, -0.678, -1.360, 0.000, 0.947, 1.029, 0.999, 0.728, 0.869, 1.027, 0.958 };
        std::vector<double> out2;
        out2 = predictor.predict(row2);
        std::cout << "Predict size: " << out2.size() << " , result: " << out2[0] << std::endl;

        std::cout << "Success!" << std::endl;
        return 0;
}
