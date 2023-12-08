#include <iostream>
#include <gsl/gsl_integration.h>
#include <Eigen/Dense>
#define N 5
#define A 0.002

struct InteParam {
  double x1;
  double a;
};

// 定义被积函数
double integrand(double x, void* params) {
  InteParam* param = static_cast<InteParam*>(params);
  return 1 / (sqrt(std::pow((param->x1 - x), 2) + param->a * param->a));
}

int main() {
    // 创建一个积分工作空间
    gsl_integration_workspace* workspace = gsl_integration_workspace_alloc(1000);

    // 设置积分参数
    gsl_function F;
    F.function = &integrand;

    // 设置积分的上下限
    double lower_limit;
    double upper_limit;

    // 初始化积分结果和误差
    double result, error;

    Eigen::MatrixXd matrix(N, N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        InteParam* param = new InteParam{ (2*j + 1) / (2*N), A};
        F.params = param;
        lower_limit = j / N;
        upper_limit = j / N + 1;
        gsl_integration_qags(&F, lower_limit, upper_limit,0, 1e-7, 1000, workspace, &result, &error);
        matrix(i, j) = result;
      }
    }

    std::cout << matrix;

    // 释放积分工作空间
    gsl_integration_workspace_free(workspace);

    return 0;
}
