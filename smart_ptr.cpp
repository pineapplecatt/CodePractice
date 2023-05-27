#include <iostream>
#include <memory>

using namespace std;

class A : public std::enable_shared_from_this<A> {
   private:
    std::weak_ptr<B> b_;
    std::weak_ptr<C> c_;

   public:
    void do_something() {}
    void set_B_C(const std::shared_ptr<B>& b, const std::shared_ptr<C>& c) {
        b_ = b;
        c_ = c;
    }
    void new_D() {
        std::shared_ptr<A> this_shared_ptr2 = shared_from_this();
        std::unique_ptr<D> d2(new D(this_shared_ptr2));
    }
};

class B {
   private:
    std::shared_ptr<A> a_;

   public:
    B(std::shared_ptr<A>& a)
        : a_(a) {}
};

class C {
   private:
    std::shared_ptr<A> a_;

   public:
    C(std::shared_ptr<A>& a)
        : a_(a) {}
};

class D {
   private:
    std::shared_ptr<A> a_;

   public:
    D(std::shared_ptr<A>& a)
        : a_(a) {}
};

int main() {
    class TestUnique {
       private:
        std::unique_ptr<A> a_ = make_unique<A>();

       public:
        void process1() {
            a_->do_something();
        }
        void process2() {
            a_->do_something();
        }
        ~TestUnique() {
            // 无需再手动删除a_
        }
    };

    /*std::unique_ptr<A> a1 = make_unique<A>();
    // std::unique_ptr<A> a1(new A());         // 离开a1作用域的时候自动释放内存
    // std::unique_ptr<A> a2 = a1;             // 编译报错，不允许复制，move-only
    std::unique_ptr<A> a3 = std::move(a1);  // 可以转移所有权，所有权转移后a1不再拥有任何指针

    // std::unique_ptr<A> a1(new A());
    A* origin_a = a1.get();  // 尽量不要暴露原生指针
    if (a1) {
        // a1 拥有指针
    }

    std::unique_ptr<A> a2(a1.release());  // 常见用法，转移拥有权
    a2.reset(new A());                    // 释放并销毁原有对象，持有一个新对象
    a2.reset();                           // 释放并销毁原有对象，等同于下面的写法
    a2 = nullptr;                         // 释放并销毁原有对象
    */
    /*std::shared_ptr<A> a1(new A());
    std::shared_ptr<A> a2 = a1;  // 编译正常，允许所有权的共享

    A* origin_a = a1.get();  // 尽量不要暴露原生指针

    if (a1) {
        // a1 拥有指针
    }

    if (a1.unique()) {
        // 如果返回true，引用计数为1
    }

    long a1_use_count = a1.use_count();  // 引用计数数量*/

    /*std::shared_ptr<A> a1(new A());
    std::weak_ptr<A> weak_a1 = a1;  // 不增加引用计数

    if (weak_a1.expired()) {
        // 如果为true，weak_a1对应的原生指针已经被释放了
    }

    long a1_use_count = weak_a1.use_count();  // 引用计数数量

    if (std::shared_ptr<A> shared_a = weak_a1.lock()) {
        // 此时可以通过shared_a进行原生指针的方法调用
    }

    weak_a1.reset();  // 将weak_a1置空*/
}