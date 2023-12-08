#include <iostream>
//#include <D:/MyGithub/third_party/eigen/Eigen/Dense>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <sstream>

int main() {
//     // 创建一个3x3的矩阵
//     Eigen::MatrixXd matrix(3, 3);
    
//     // 赋值
//     matrix << 1, 2, 3,
//               4, 5, 6,
//               7, 8, 9;

//     // 输出矩阵
//     std::cout << "原始矩阵:\n" << matrix << "\n\n";

//     // 访问矩阵元素
//     std::cout << "矩阵(2,2)的元素为: " << matrix(2, 2) << "\n\n";

//     // 矩阵乘法
//     Eigen::MatrixXd result = matrix * matrix;
//     std::cout << "矩阵乘法的结果:\n" << result << "\n\n";

//     // 特征值和特征向量
//     Eigen::EigenSolver<Eigen::MatrixXd> solver(matrix);
//     std::cout << "矩阵的特征值:\n" << solver.eigenvalues() << "\n\n";
//     std::cout << "矩阵的特征向量:\n" << solver.eigenvectors() << "\n";

//     std::cout << matrix.nonZeros();
//     return 0;
// }
    Eigen::SparseMatrix<double> matrix(3, 3);
    matrix.insert(0, 0) = 1;
    matrix.insert(1, 0) = 1;
    matrix.insert(0, 2) = 1;
    const int* outerIndices = matrix.outerIndexPtr();
    const int* innerIndices = matrix.innerIndexPtr();

    // 遍历非零元素
    for (int j = 0; j < matrix.cols(); ++j) {
        for (int k = outerIndices[j]; k < outerIndices[j + 1]; ++k) {
            int i = innerIndices[k];
            std::cout << "nonzero:(" << i << ", " << j << ")" << std::endl;
        }
    }
    
    for ()
}