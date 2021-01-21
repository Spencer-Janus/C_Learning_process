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
//    cout << "请输入当前的磁道号:";
//    cin >> now;
//    cout << "磁盘调度顺序为:" << endl;
//    for (i = 0; i < n; i++)
//    {
//        cout << a[i] << " ";
//    }
//    cout << endl;
//    sum += abs(a[0] - now);
//    cout << "从当前位置到第1个磁道移动的磁道数为：" << sum << endl;
//    for (i = 0, j = 1; j < n; i++, j++)
//    {
//        sum += abs(a[j] - a[i]);
//        cout << "从第" << i + 1 << "个磁道到第" << j + 1 << "个磁道的移动距离为:" << abs(a[j] - a[i]) << endl;
//    }
//    cout << endl;
//    cout << "移动的总磁道数为:" << sum << endl;
//    avg = sum * 1.0 / n;
//    cout << "平均寻道长度为:" << avg << endl;
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
//    cout << "按递增顺序排好的磁道：" << endl;
//    for (i = 0; i < n; i++)
//        cout << a[i] << " ";
//    cout << endl;
//    cout << "请输入当前的磁道号:";
//    cin >> now;
//    cout << "磁盘调度顺序为:" << endl;
//    if (now >= a[n - 1])
//    {
//        for (i = n - 1; i >= 0; i--)
//            cout << a[i] << " " << endl;
//        cout << "从当前位置到第1个磁道移动的磁道数为：" << now - a[n - 1] << endl;
//        for (i = 0, j = 1; j < n; i++, j++)
//            cout << "从第" << i + 1 << "个磁道到第" << j + 1 << "个磁道的移动距离为:" << abs(a[j] - a[i]) << endl;
//        sum = now - a[0];
//    }
//    else if (now < a[0])
//    {
//        for (i = 0; i < n; i++)
//            cout << a[i] << " " << endl;
//        cout << "从当前位置到第1个磁道移动的磁道数为：" << a[0] - now << endl;
//        for (i = 0, j = 1; j < n; i++, j++)
//            cout << "从第" << i + 1 << "个磁道到第" << j + 1 << "个磁道的移动距离为:" << abs(a[j] - a[i]) << endl;
//        sum = a[n - 1] - now;//同上面
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
//    cout << "移动的总磁道数:" << sum << endl;
//    AVG = sum * 1.0 / n;
//    cout << "平均寻道长度为:" << AVG << endl;
//}
//
//int main()
//{
//    int n;
//    int s;
//    int i;
//    cout << "请输入磁道个数:" << endl;
//    cin >> n;
//    int* a = new int[n];
//    for (i = 0; i < n; i++)
//    {
//        cout << "请输入第" << i + 1 << "个磁道号:";
//        cin >> a[i];
//    }
//    cout << endl;
//    while (1)
//    {
//        cout << endl;
//        cout << "1:先来先服务算法:" << endl;
//        cout << "2:最短寻道时间算法:" << endl;
//        cout << "0:退出" << endl;
//        cout << endl;
//        cout << "请选择功能号:";
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
