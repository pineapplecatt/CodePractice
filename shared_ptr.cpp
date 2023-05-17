#include <iostream>

namespace ptr {

template <typename T>
class shared_ptr {
   public:
    shared_ptr()
        : _ptr((T*)0), _refCount(0) {}
    shared_ptr(T* obj)
        : _ptr(obj), _refCount(new int(1)) {}
    shared_ptr(shared_ptr& other)
        : _ptr(other._ptr), _refCount(&(++*other._refCount)) {}
    ~shared_ptr() {
        if (_ptr && --*_refCount == 0) {
            delete _ptr;
            delete _refCount;
        }
    }
    shared_ptr& operator=(shared_ptr& other) {
        if (this == &other) {
            return *this;
        }
        // 新指针引用计数++
        ++*other._refCount;
        // 原指针引用计数--
        if (--*_refCount == 0) {
            delete _ptr;
            delete _refCount;
        }
        _ptr = other._ptr;
        _refCount = other._refCount;
        return *this;
    }
    T& operator*() {
        if (_refCount == 0) {
            return (T*)0;
        }
        return *_ptr;
    }
    T* operator->() {
        if (_refCount == 0) {
            return 0;
        }
        return _ptr;
    }

   private:
    T* _ptr;
    int* _refCount;  // 拷贝构造时同一地址空间引用计数++
};
}  // namespace ptr

int main(){
    return 0;
}