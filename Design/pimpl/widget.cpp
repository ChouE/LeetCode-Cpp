#include <memory>
#include "widget.h"
class Widget::impl {
    int n;
public:
    void draw(const Widget& w) const {
        std::cout << "Widget::Impl::draw(" << w.n << ")\n";
    }
    impl(int n) : n(n) {}
};

void Widget::draw() const {
    pimpl->draw(*this);
}

Widget::Widget(int n) : pimpl{std::make_unique<Impl>(n)} {}

Widget::~Widget() = default;

Widget& Widget::operator=(Widget&&) = default;
