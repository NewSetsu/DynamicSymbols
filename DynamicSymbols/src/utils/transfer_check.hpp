#include "singleton.hpp"
#include "basic_def/basic_def.h"

#include <map>

class TransferCheck : public SingletonBase<TransferCheck>
{
    friend class SingletonBase<TransferCheck>;
public:
    const bool TypeCheck(const std::string& str1, const std::string& str2);

private:
    TransferCheck();
    typedef std::map<std::string, std::vector<std::string>*> TransMap;
    TransMap m_trans_map;
};