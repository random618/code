#include "src/code.h"
#include "src/code_factory.h"

// 计算从0到n-1的所有可能路径
class AllPaths : public Code {
public:
    static constexpr int kClassType = kAllPaths;

    void Init();
    void Run();
    void Print();
    void traverse(std::vector<int> &curPath, int idx, int n);

private:
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> paths;
};

void AllPaths::Init() {
    std::vector<std::vector<int>> input{{1,2}, {3}, {3}, {}};
    graph = std::move(input);
}

void AllPaths::Print() {
    for (int i = 0; i < graph.size(); i++) {
        std::cout << "vertex[" << i << "]: ";
        for (int j = 0; j < graph[i].size(); j++) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < paths.size(); i++) {
        std::cout << "path[" << i << "]: ";
        for (int j = 0; j < paths[i].size(); j++) {
            std::cout << paths[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// curPath表示当前已经遍历过的路径，以及即将要遍历的节点idx，n表示节点总数
void AllPaths::traverse(std::vector<int> &curPath, int idx, int n) {
    if (idx == n - 1) { // 表示到终点了
        curPath.push_back(idx);
        paths.push_back(curPath);
        return;
    }

    curPath.push_back(idx);
    for (int i = 0; i < graph[idx].size(); i++) { // 遍历idx的邻接节点
        traverse(curPath, graph[idx][i], n);
        curPath.pop_back();
    }
}

void AllPaths::Run() {
   std::cout << "AllPaths run" << std::endl;
   std::vector<int> curPath;
   int n = graph.size();
   traverse(curPath, 0, n);
}

CODE_FACTORY_REGISTER(Code, AllPaths)

