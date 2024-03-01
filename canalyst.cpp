#include "canalyst.h"

CanAlyst::CanAlyst() :
  m_index{0}
, m_cannum{0}
, m_devtype{ VCI_USBCAN1 }
{
    VCI_INIT_CONFIG InitInfo[1];

    // 125 Kbit/s
    InitInfo->Timing0=0x03;
    InitInfo->Timing1=0x1C;

    InitInfo->Filter=0;
    InitInfo->AccCode=0x80000008;
    InitInfo->AccMask=0xFFFFFFFF;
    InitInfo->Mode=0; // 11-bit

    if( VCI_OpenDevice( m_devtype, m_index, m_cannum ) == 1 ) {

        std::cout << "OpenCAN successfule" << std::endl;

        if( VCI_InitCAN( m_devtype, m_index, m_cannum, InitInfo ) == 1 ) {

            std::cout << "InitCAN successfule" << std::endl;

            Sleep(100);

            if(VCI_StartCAN( m_devtype, m_index, m_cannum) == 1 ) {

                std::cout << "StartCAN successfule" << std::endl;

                sendFrame();

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

void CanAlyst::sendFrame()
{
    VCI_CAN_OBJ sendbuf[1];

    sendbuf->ID = 0x00000083; // status TableT

    sendbuf->DataLen = 0;
    sendbuf->Data[0] = 0;
    sendbuf->Data[1] = 0;
    sendbuf->Data[2] = 0;
    sendbuf->Data[3] = 0;
    sendbuf->Data[4] = 0;
    sendbuf->Data[5] = 0;
    sendbuf->Data[6] = 0;
    sendbuf->Data[7] = 0;

    sendbuf->SendType = 0;
    sendbuf->ExternFlag = 0;
    sendbuf->RemoteFlag = 0;
    sendbuf->TimeFlag = 0;
    sendbuf->TimeStamp = 0;

    sendbuf->Reserved[0] = 0;
    sendbuf->Reserved[1] = 0;
    sendbuf->Reserved[2] = 0;


    int flag = VCI_Transmit( m_devtype, m_index, m_cannum, sendbuf, 1); //CAN message send

    if( flag < 1 ) {
        if( flag == -1 )
            std::cout << "failed- device not open" << std::endl;
        else if( flag == 0 )
            std::cout << "send error" << std::endl;
        return;
    }


    std::cout << "VCI_Transmit successfule" << std::endl;
//    Sleep(100);

    while (1) {
        const int numberFrame = 0;

        VCI_CAN_OBJ pCanObj[numberFrame];

        int NumValue = VCI_Receive( m_devtype, m_index, m_cannum, pCanObj, numberFrame, 10);

        if( NumValue > 0 ) {
            for( int i; i < NumValue ; i++) {
                std::cout << pCanObj->ID;
            }
            return;
        }
    }
}
