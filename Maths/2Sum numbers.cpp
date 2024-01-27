long long random_number()
{
    const long long min = -100'000'000'000;
    const long long max =  100'000'000'000;
    static std::mt19937_64 gen(std::time(nullptr));
    static std::uniform_int_distribution<long long> dist(min, max);
    return dist(gen);
}

bool is_sum_exist(const std::vector<long long>& data, long long x)
{
    auto j = std::lower_bound(data.begin(), data.end(), x)  -  data.begin();
    decltype(j) i = 0;
    if(j == data.size()) --j;
    while (i < j)  {
        long long sum = data[i]+data[j];
             if (sum == x)  return true;
        else if (sum >  x)  --j;
        else                ++i;
    }
    return false;
}