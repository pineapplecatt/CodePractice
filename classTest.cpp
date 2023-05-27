#include <iostream>
using namespace std;

// 实现时间类Time,提供以下操作并调⽤执⾏。
class Time {
   private:
    int hour;
    int minute;
    int second;

   public:
    Time(int h = 0, int m = 0, int s = 0)
        : hour(h), minute(m), second(s) {}

    void set(int h, int m, int s) {
        this->hour = h;
        this->minute = m;
        this->second = s;
    }

    void display() {
        cout << hour << ":" << minute << ":" << second;
    }

    bool equal(Time& other_time) {
        if (this->hour == other_time.hour) {
            if (this->minute == other_time.minute) {
                if (this->second == other_time.second) {
                    return true;
                }
                return false;
            }
            return false;
        }
        return false;
    }
};

// 定义⼀个类A，使得程序只能创建⼀个类A的对象，
// 当试图创建类A的第⼆个对象时，返回第⼀个对象的指针。
class A {
   private:
    A() {}
    static A* p;

   public:
    static A* getA() {
        if (p != nullptr) {
            return p;
        } else {
            p = new A();
            return p;
        }
    }
};
A* A::p = nullptr;

// 实现字符串类String，提供以下操作并调⽤执⾏。
class String {
   private:
    char* data;

   public:
    String() {
        data = new char[1];
        data[0] = '\0';
    }
    String(const char* str) {
        if (str == nullptr) {
            data = new char[1];
            data[0] = '\0';
        } else {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        }
    }
    String(const String& str) {
        this->data = new char[strlen(str.data) + 1];
        strcpy(this->data, str.data);
    }
    ~String() {
        if (data != nullptr) {
            delete[] data;
        }
    }
    // 判断⼦串是否在当前字符串⾥
    bool is_substring(const String& sub_str) {
        char* p1 = this->data;
        char* p2 = sub_str.data;
        int cnt;
        while (*p1 != '\0') {
            cnt = 0;
            while (*(p1 + cnt) != '\0' && *(p2 + cnt) != '\0') {
                if (*(p1 + cnt) != *(p2 + cnt)) {
                    break;
                }
                cnt++;
            }
            if ('\0' == *(p2 + cnt)) {
                return true;
            }
            p1++;
        }
        return false;
    }
    // 返回子串出现的位置
    int find_str(const char* sub_str) {
        char* p1 = this->data;
        const char* p2 = sub_str;
        int cnt;
        while (*p1 != '\0') {
            cnt = 0;
            while (*(p1 + cnt) != '\0' && *(p2 + cnt) != '\0') {
                if (*(p1 + cnt) != *(p2 + cnt)) {
                    break;
                }
                cnt++;
            }
            if ('\0' == *(p2 + cnt)) {
                return p1 - this->data;
            }
            p1++;
        }
        return -1;
    }
    // 从pos开始。len长度的子串替换为str
    char* replace1(int pos, int len, const char* str) {
        char* newdata = nullptr;
        if (len < strlen(str)) {
            newdata = new char[strlen(data) + (strlen(str) - len) + 1];
        } else {
            newdata = data;
        }
        strncpy(newdata, data, pos);
        strcpy(newdata + pos, str);
        strcpy(newdata + pos + strlen(str), data + pos + len);
        if (len < strlen(str)) {
            delete[] data;
        }
        data = newdata;
        return data;
    }
    // 查找⼦串并替换,返回替换次数
    int replace(const char* find, const char* replace) {
        int pos = find_str(find);
        int count = 0;
        while (pos != -1) {
            replace1(pos, strlen(find), replace);
            count++;
            pos = find_str(find);
        }
    }
};

size_t strlen(const char* str) {
    if (str == nullptr) {
        return 0;
    }
    int res = 0;
    while (*str != '\0') {
        res++;
        str++;
    }
}
char* strcpy(char* dst, const char* src) {
    if (dst == nullptr || src == nullptr) {
        return nullptr;
    }
    char* ret = dst;
    while ((*dst++ = *src++) != '\0')
        ;
    return ret;
}
char* strncpy(char* dst, const char* src, int n) {
    if (dst == nullptr || src == nullptr) {
        return nullptr;
    }
    char* ret = dst;
    int count = 0;
    while (count < n && (*dst++ = *src++) != '\0') {
        count++;
    }
    return ret;
}

int main() {
    /* Time t(20, 34, 5);
    t.display();
    cout << endl;
    t.set(12, 13, 4);
    t.display();
    cout << endl;
    Time i(12, 13, 4);
    if (t.equal(i)) {
        cout << "111";
    } */
    /* A* p1 = A::getA();
    A* p2 = A::getA();
    cout << p1 << endl;
    cout << p2 << endl; */
    return 0;
}