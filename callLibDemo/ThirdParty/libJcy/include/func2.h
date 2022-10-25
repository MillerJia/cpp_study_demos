#ifndef _FUNC2_H
#define _FUNC2_H

// c++ 项目中调用 C库中的方法时需要标明 extern "C"
// C++调用函数时知道要以C语言函数规则寻找实现

#ifdef __cplusplus
extern "C" {
#endif

int add(int a, int b);

#ifdef __cplusplus
}
#endif

#endif