#ifndef CANALYST_H
#define CANALYST_H

#include <iostream>
#include <iomanip>

#include <windows.h>
#include "ControlCAN.h"

class CanAlyst
{    
    int m_index;
    int m_cannum;
    int m_devtype;

public:
    CanAlyst();
    ~CanAlyst();

private:
    void sendFrame();
};

#endif // CANALYST_H
