// in log(n) time using Binet’s formula and 0(1) space

long long fib(long long n) { 
  double phi = (1 + sqrt(5)) / 2; 
  return round(pow(phi, n) / sqrt(5)); 
} 
