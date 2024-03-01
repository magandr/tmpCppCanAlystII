#ifndef CANALYST_H
#define CANALYST_H

#include <iostream>
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
};

#endif // CANALYST_H
