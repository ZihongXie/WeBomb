#include <stdio.h>
#include <windows.h>

void BombStart() {
    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event('V', 0, 0, 0);

    keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);

    Sleep(100);//�ȴ�0.05��

    //�س�����
    keybd_event(VK_RETURN, 0, 0, 0);
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

    Sleep(100);//�ȴ�0.05��
}

int main() {
    int MesageNum = 0;
    int num = 0;

    //Ѱ�Ҵ���
    HWND WechatWindows = FindWindow(L"WeChatMainWndForPC", L"΢��");

    //��ʾ�����Ƿ��ҵ�
    if (WechatWindows == NULL) {
        printf("δ�ҵ�΢�Ŵ��ڣ���ȷ��΢���Ѵ򿪡�\n");
        return 1;
    }

    //�ö�����
    SetWindowPos(WechatWindows, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

    //��ȡ����λ��
    RECT RectWechat;
    GetWindowRect(WechatWindows, &RectWechat);

    //��cmd��������Ϣ����
    printf("������ˢ����Ϣ��������д-1��������ѭ��\n");
    printf("ע�⣬���Ƚ�΢�Ŵ��ڵ������ٽ��䴰����С����ʹ��\n");
    scanf_s("%d", &MesageNum);
    num = MesageNum;

    //�ж�ѭ����ʽ
    if (MesageNum != -1 && MesageNum > 0)
    {
        //׼��
        //�ƶ����
        SetCursorPos(RectWechat.left + 420, RectWechat.top + 430);
        //ģ�������
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

        //����ѭ��
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