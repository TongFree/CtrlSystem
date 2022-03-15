#pragma once
#include "afxcmn.h"

CString ITEMNAME[] = {"输入检测通道", "模拟信号输出", "信号发生器", "多条件输出", "电源开关", "三态输出", "可编程电阻", "工装通道", "可编程电子负载", "夹具设置", "静态电流测试"};
CString ITEMTYPE[] = {""};
int CHANNEL;
CString CHANNELTYPE;
CString STATE;
CString OPTION[] = {"拉高", "拉低", "断开"};
int BRATE; // 占空比
CString DELAY;
CString SILENT;
CString STEP;
CString ISJAG;
int HZ;
CString WAVE[] = {"方波","三角波", "正弦波"};
CString PULSE;
int V;
CString A;
CString R;
CString DB;
CString VALUE1;
CString VALUE2;
CString VALUE3;
CString VALUE4;
CString VALUE5;
CString VALUE6;
CString VALUE7;
