#include "device_iostream.h"
#include <iostream>

using namespace Devices;

RetCode CDevice_IOStream::connect(){
    return RET_OK;
}

RetCode CDevice_IOStream::read(std::string& data){
    m_input_stream >> data;
    return RET_OK;
}

RetCode CDevice_IOStream::write(const std::string& data){
    m_output_stream << "sending '" << data << "'\n";
    return RET_OK;
}
