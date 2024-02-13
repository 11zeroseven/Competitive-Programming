// in log(n) time using Binet’s formula and 0(1) space

long long fib(long long n) { 
  double phi = (1 + sqrt(5)) / 2; 
  return round(pow(phi, n) / sqrt(5)); 
} 

// in log(n) time and auxiliary space log(n) 

void multiply(vector<vector<ll>>& F, vector<vector<ll>>& M) {
  ll x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
  ll y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
  ll z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
  ll w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void pow_matrix(vector<vector<ll>>& F, ll n) {
  if (n == 0 || n == 1) {
    return;
  }

  vector<vector<ll>> M = {{1, 1}, {1, 0}};
  pow_matrix(F, n / 2);
  multiply(F, F); 

  if (n & 1) {
    vector<vector<ll>> temp = {{1, 1}, {1, 0}};
    multiply(F, temp);  
  }
}


ll fibonacci_fast(ll n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }

  vector<vector<ll>> F = {{1, 1}, {1, 0}};

  pow_matrix(F, n - 1);

  return F[0][0];
}
