#include "singleton.hpp"
#include "basic_def/basic_def.h"

#include <map>

class TransferCheck 
{
private:
    TransferCheck();
    ~TransferCheck() {};
    TransferCheck(const TransferCheck&) = default;
    TransferCheck& operator=(const TransferCheck&) = default;
public:
    static TransferCheck* GetInstance() {
        static TransferCheck instance;
        return &instance;
    }

    const bool TypeCheck(const std::string& str1, const std::string& str2);
private:
    typedef std::map<std::string, std::vector<std::string>*> TransMap;
    TransMap m_trans_map;
};