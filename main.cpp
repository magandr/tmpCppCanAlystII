#include <iostream>

#include <signal.h>

#include "canalyst.h"


int main()
{
    CanAlyst canAlyst;

    // грязный хак,
    // так как exit в случае нормального завершения должна вернуть 0
    // а в этом случае exit возвращает 2
    // но я не знаю как обратиться к 'a' за пределами области видимоcти main
    signal(SIGINT, std::_Exit);

//    ;
}
