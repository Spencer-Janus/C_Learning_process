//
//#include <iostream>
//#include <cstdlib>
//#include <stdio.h>
//
//using namespace std;
//
//void FIFO(int a[], int n)
//{
//    int sum = 0;
//    int i, j, now;
//    float avg;
//    cout << "�����뵱ǰ�Ĵŵ���:";
//    cin >> now;
//    cout << "���̵���˳��Ϊ:" << endl;
//    for (i = 0; i < n; i++)
//    {
//        cout << a[i] << " ";
//    }
//    cout << endl;
//    sum += abs(a[0] - now);
//    cout << "�ӵ�ǰλ�õ���1���ŵ��ƶ��Ĵŵ���Ϊ��" << sum << endl;
//    for (i = 0, j = 1; j < n; i++, j++)
//    {
//        sum += abs(a[j] - a[i]);
//        cout << "�ӵ�" << i + 1 << "���ŵ�����" << j + 1 << "���ŵ����ƶ�����Ϊ:" << abs(a[j] - a[i]) << endl;
//    }
//    cout << endl;
//    cout << "�ƶ����ܴŵ���Ϊ:" << sum << endl;
//    avg = sum * 1.0 / n;
//    cout << "ƽ��Ѱ������Ϊ:" << avg << endl;
//}
//
//void SSTF(int a[], int n)
//{
//    int temp;
//    int now, L, r;
//    int j, i;
//    int k = 1;
//    int sum = 0;
//    float AVG;
//
//    for (i = 0; i < n; i++)
//        for (j = i + 1; j < n; j++)
//        {
//            if (a[i] > a[j])
//            {
//                temp = a[i];
//                a[i] = a[j];
//                a[j] = temp;
//            }
//        }
//    cout << "������˳���źõĴŵ���" << endl;
//    for (i = 0; i < n; i++)
//        cout << a[i] << " ";
//    cout << endl;
//    cout << "�����뵱ǰ�Ĵŵ���:";
//    cin >> now;
//    cout << "���̵���˳��Ϊ:" << endl;
//    if (now >= a[n - 1])
//    {
//        for (i = n - 1; i >= 0; i--)
//            cout << a[i] << " " << endl;
//        cout << "�ӵ�ǰλ�õ���1���ŵ��ƶ��Ĵŵ���Ϊ��" << now - a[n - 1] << endl;
//        for (i = 0, j = 1; j < n; i++, j++)
//            cout << "�ӵ�" << i + 1 << "���ŵ�����" << j + 1 << "���ŵ����ƶ�����Ϊ:" << abs(a[j] - a[i]) << endl;
//        sum = now - a[0];
//    }
//    else if (now < a[0])
//    {
//        for (i = 0; i < n; i++)
//            cout << a[i] << " " << endl;
//        cout << "�ӵ�ǰλ�õ���1���ŵ��ƶ��Ĵŵ���Ϊ��" << a[0] - now << endl;
//        for (i = 0, j = 1; j < n; i++, j++)
//            cout << "�ӵ�" << i + 1 << "���ŵ�����" << j + 1 << "���ŵ����ƶ�����Ϊ:" << abs(a[j] - a[i]) << endl;
//        sum = a[n - 1] - now;//ͬ����
//    }
//    else
//    {
//        while (a[k] < now)
//            k++;
//        L = k - 1;
//        r = k;
//        while ((L >= 0) && (r < n))
//        {
//            if ((now - a[L]) <= (a[r] - now))
//            {
//                cout << a[L] << " ";
//                sum += now - a[L];
//                now = a[L];
//                L--;
//            }
//            else
//            {
//                cout << a[r] << " ";
//                sum += a[r] - now;
//                now = a[r];
//                r++;
//            }
//        }
//        if (L = -1)
//        {
//            for (j = r; j < n; j++)
//                cout << a[j] << " ";
//            sum += a[n - 1] - a[0];
//        }
//        if (r == n)
//        {
//            for (j = k - 1; j > -1; j--)
//                cout << a[j] << " ";
//            sum += a[n - 1] - a[0];
//        }
//    }
//    cout << endl;
//    cout << "�ƶ����ܴŵ���:" << sum << endl;
//    AVG = sum * 1.0 / n;
//    cout << "ƽ��Ѱ������Ϊ:" << AVG << endl;
//}
//
//int main()
//{
//    int n;
//    int s;
//    int i;
//    cout << "������ŵ�����:" << endl;
//    cin >> n;
//    int* a = new int[n];
//    for (i = 0; i < n; i++)
//    {
//        cout << "�������" << i + 1 << "���ŵ���:";
//        cin >> a[i];
//    }
//    cout << endl;
//    while (1)
//    {
//        cout << endl;
//        cout << "1:�����ȷ����㷨:" << endl;
//        cout << "2:���Ѱ��ʱ���㷨:" << endl;
//        cout << "0:�˳�" << endl;
//        cout << endl;
//        cout << "��ѡ���ܺ�:";
//        cin >> s;
//
//        switch (s)
//        {
//        case 0:exit(0); break;
//        case 1:FIFO(a, n); break;
//        case 2:SSTF(a, n); break;
//        }
//
//    }
//    return 0;
//}
