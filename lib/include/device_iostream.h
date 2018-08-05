#pragma once
#include "devices.h"
#include <iostream>
#include <string>

using namespace Devices;

class CDevice_IOStream : public CDevice{
public:
    CDevice_IOStream(std::istream& input_stream = std::cin, std::ostream& output_stream = std::cout)
    : m_input_stream(input_stream), m_output_stream(output_stream) {}

    ~CDevice_IOStream() {};

    virtual RetCode connect() final;
    virtual RetCode read(std::string&) final;
    virtual RetCode write(const std::string&) final;
private:
    std::istream& m_input_stream;
    std::ostream& m_output_stream;
};
