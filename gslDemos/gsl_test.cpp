#include <iostream>
#include <gsl/gsl_integration.h>

// 定义被积函数
double integrand(double x, void* params) {
    return x * x;
}

int main() {
    // 创建一个积分工作空间
    gsl_integration_workspace* workspace = gsl_integration_workspace_alloc(1000);

    // 设置积分参数
    gsl_function F;
    F.function = &integrand;
    F.params = nullptr; // 你可以传递一些参数给被积函数，这里示例中没有使用

    // 设置积分的上下限
    double lower_limit = 0.0;
    double upper_limit = 1.0;

    // 初始化积分结果和误差
    double result, error;
    
    // 使用 GSL 积分函数进行数值积分
    gsl_integration_qags(&F, lower_limit, upper_limit, 0, 1e-7, 1000, workspace, &result, &error);

    // 输出积分结果和误差
    std::cout << "Result: " << result << std::endl;
    std::cout << "Error: " << error << std::endl;

    // 释放积分工作空间
    gsl_integration_workspace_free(workspace);

    return 0;
}
