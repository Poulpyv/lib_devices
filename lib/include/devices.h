#pragma once
#include <string>

namespace Devices{
    enum RetCode {RET_OK, RET_KO};

    class CDevice{
    public:
        virtual ~CDevice() = default;

        virtual RetCode connect() { return RET_OK; };
        virtual RetCode read(std::string&,uint32_t) = 0;
        virtual RetCode write(const std::string&) = 0;
    };

} // namespace Devices
