#include <stdio.h>
#include <windows.h>

int main() {
    //初始化变量
    int MesageNum = 0;
    int num = 0;

    //寻找窗口
    HWND WechatWindows = FindWindow(L"WeChatMainWndForPC", L"微信");

    //提示窗口是否找到
    if (WechatWindows == NULL) {
        printf("未找到微信窗口，请确保微信已打开。\n");
        return 1;
    }

    //置顶窗口
    SetWindowPos(WechatWindows, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

    //获取窗口位置
    RECT RectWechat;
    GetWindowRect(WechatWindows, &RectWechat);

    //在控制台里设置消息数量
    printf("请输入刷屏消息数量，填写-1代表无限循环\n");
    printf("注意，请先将微信窗口调出来再将其窗口最小化再使用\n");
    scanf_s("%d", &MesageNum);
    num = MesageNum; //我也不知道为什么我要写两个变量

    //判断循环方式
    if (MesageNum != -1 && MesageNum > 0)
    {
        //准备
        //移动光标
        SetCursorPos(RectWechat.left + 420, RectWechat.top + 430);
        //模拟鼠标点击
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

        //次数循环
        for (int i = 0; i < num; i++) 
        {
            BombStart();
        }
    }
    else if (MesageNum == -1)
    {
        while (true) {
            BombStart();
        }
    }
}

void BombStart() {
    //粘贴文本
    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event('V', 0, 0, 0);

    keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);

    Sleep(100);//等待0.1秒

    //回车发送
    keybd_event(VK_RETURN, 0, 0, 0);
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

    Sleep(100);//等待0.1秒
}
