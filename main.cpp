#include <iostream>

#include <windows.h>
#include "ControlCAN.h"

using namespace std;

int main()
{
    int index = 0;
    int cannum = 0;

    VCI_INIT_CONFIG InitInfo[1];
    InitInfo->Timing0=0x00;
    InitInfo->Timing1=0x14;
    InitInfo->Filter=0;
    InitInfo->AccCode=0x80000008;
    InitInfo->AccMask=0xFFFFFFFF;
    InitInfo->Mode=2;

//    initconfig.AccCode=StrToInt("0x"+Edit2->Text);

     int m_devtype = /*m_nDevType == 1 ?  *//*VCI_USBCAN2 :*/  VCI_USBCAN1;
//    initconfig.AccMask=StrToInt("0x"+Edit3->Text);
//    initconfig.Timing0=StrToInt("0x"+Edit5->Text);
//    initconfig.Timing1=StrToInt("0x"+Edit6->Text);
//    initconfig.Filter=ComboBox3->ItemIndex;
//    initconfig.Mode=ComboBox4->ItemIndex;

        if( VCI_OpenDevice( m_devtype, index, 0 ) == 1 ) {

                if( VCI_InitCAN( m_devtype, index, cannum, InitInfo ) ==1 ) {

                    Sleep(100);

//                        m_connect=1;
//                        m_devind=0;
//                        m_cannum=cannum;
//                        m_readhandle=(HANDLE)_beginthread(ReceiveThread,0,(void*)ListBox1);
                } else {
                    cout << "not init";
                }
        } else {
            cout << "not open";
        }

    return 0;
}
