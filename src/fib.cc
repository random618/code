#include "src/code.h"
#include "src/code_factory.h"

// 斐波那契数列
class Fib : public Code {
public:
    static constexpr int kClassType = kFib;

    void Init();
    void Run();
    void Print();

private:
    std::vector<int> dp; // dp[i]表示第i个数是多少，i=1...N，dp[0]=0，dp[1]=1，dp[2]=1，dp[3]=2，dp[4]=3
    int N;
};

void Fib::Init() {
    N = 20;
    std::vector<int> input(N+1, 0);
    dp = std::move(input);
    dp[0] = 0;
    dp[1] = 1;
}

void Fib::Print() {
    for (int i = 1; i <= N; i++) {
        std::cout << dp[i] << std::endl;
    }
}

void Fib::Run() {
   std::cout << "Fib run" << std::endl;
   for (int i = 2; i <= N; i++) {
       dp[i] = dp[i-1] + dp[i-2];
   }
}

CODE_FACTORY_REGISTER(Code, Fib)

