#include <iostream>
#include <gsl/gsl_integration.h>

double f(double x, void* params) {
  // double f = sin(x) * 2;
  // return f;
  double f = x * x + x * x * x;
  return f;
}

int main()
{
  gsl_integration_fixed_workspace* w;
  const gsl_integration_fixed_type* T = gsl_integration_fixed_legendre;
  w = gsl_integration_fixed_alloc(T, 2, 1, 2, 0,0);

  gsl_function F;
  F.function = &f;
  F.params = nullptr;

  double result;
  gsl_integration_fixed(&F, &result, w);

  std::cout << "result:" << result;
}