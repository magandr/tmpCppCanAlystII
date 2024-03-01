#include "canalyst.h"

CanAlyst::CanAlyst() :
  m_index{0}
, m_cannum{0}
, m_devtype{ VCI_USBCAN1 }
{
    VCI_INIT_CONFIG InitInfo[1];
    InitInfo->Timing0=0x00;
    InitInfo->Timing1=0x14;
    InitInfo->Filter=0;
    InitInfo->AccCode=0x80000008;
    InitInfo->AccMask=0xFFFFFFFF;
    InitInfo->Mode=2;

    if( VCI_OpenDevice( m_devtype, m_index, m_cannum ) == 1 ) {

        if( VCI_InitCAN( m_devtype, m_index, m_cannum, InitInfo ) == 1 ) {

            Sleep(100);

            if(VCI_StartCAN( m_devtype, m_index, m_cannum) == 1 ) {


            } else {
                std::cout << "StartCAN failed" << std::endl;
            }

        } else {
            std::cout << "InitCAN failed" << std::endl;
        }
    } else {
        std::cout << "OpenCAN failed" << std::endl;
    }
}

CanAlyst::~CanAlyst()
{
    if( VCI_CloseDevice( m_devtype, m_index ) !=1 ) {
        std::cout << "CloseDevice failed" << std::endl;
    } else {
        std::cout << "CloseDevice successfule" << std::endl;
    }
}
