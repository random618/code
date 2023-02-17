#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>
#include "src/code.h"

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

typedef std::function<std::unique_ptr<Code>()> CodeCreator;
typedef std::unordered_map<int, CodeCreator> CodeCreatorTable;

class CodeFactory {
public:
    CodeFactory() {};
    ~CodeFactory() {};

    static CodeCreatorTable& GetCodeCreatorTable() {
        static std::unique_ptr<CodeCreatorTable> table;
        if (!table) {
            table = make_unique<CodeCreatorTable>();
        }
        return *table;
    }
    
    static std::unique_ptr<Code> GetCode(int type) {
        auto found = GetCodeCreatorTable().find(type);
        if (found == GetCodeCreatorTable().end()) {
        return nullptr;
        }
        return found->second();
    }

    static int RegisterCode(int type, CodeCreator&& creator) {
        std::cout << "RegisterCode " << type << std::endl;
        GetCodeCreatorTable().emplace(type, creator);
        return 0;
    }
};

#define CODE_FACTORY_REGISTER(BASE, CLASS)                                 \
  static int CONCAT(factor_reg_, __COUNTER__) = CodeFactory::RegisterCode( \
      CLASS::kClassType, []() -> std::unique_ptr<BASE> {                   \
        std::unique_ptr<BASE> r = make_unique<CLASS>();                    \
        return r;                                                          \
      });

#define CONCAT(x, y) x ## y
