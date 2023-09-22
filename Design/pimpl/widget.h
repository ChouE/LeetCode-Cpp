/**
 * Pimpl Idiom 是一种设计模式，它的目的是减少头文件的依赖，提高编译速度。
 * 将一个外部可见类的实现细节放到一个单独的类中，这个类就是实现类。
 * 将这个实现类的指针作为外部可见类的成员变量，传递给外部可见类的构造函数。
 * 原理：如果是私有变量或者函数，每次更改都要重新编译，而交给impl指针，则不用更改变量
 * 只需要更改impl的实现就可以了，这样就可以减少编译时间。
 */
class Widget {
    class impl;
    std::unique_ptr<impl> pimpl;
public:
    // public API that will be forwarded to the implementation
    void draw();
    // defined in the implementation file
    Widget(int);
    // defined in the implementation file
    ~Widget();

    Widget(Widget&&) = default;
    Widget(const& Widget) = delete;

    Widget& operator=(Widget&&);
    Widget& operator=(const& Widget) = delete;
};