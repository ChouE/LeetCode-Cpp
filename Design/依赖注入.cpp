#include <iostream>
#include <chrono>
#include <memory>

class Logger {
public:
    virtural void write(const std::string& str) = 0;
    virtual ~Logger() = default;
};

class SimpleLogger : public Logger {
    void write(const std::string& mess) override {
        std::cout << mess << std::endl;
    }
};

class TimeLogger : public Logger {
    using MySecondTick = std::chrono::duration<long double>;
    long double timeSinceEpoch() {
        auto timeNow = std::chrono::system_clock::now();
        auto duration = timeNow.time_since_epoch();
        MySecondTick sec(duration);
        return sec.count();
    }
    void write(const std::string& mess) override {
        std::cout << std::fixed << timeSinceEpoch() << " " << mess << '\n';
    }
};

class Client {
public:
    Client(std::shared_ptr<Logger> log) : logger(log) {}
    void doSomething() {
        logger->write("Client::doSomething()");
    }
    void setLogger(std::shared_ptr<Logger> log) {
        logger = log;
    }
private:
    std::shared_ptr<Logger> logger;
};

int main() {
    std::cout << '\n';
    Client cl(std::make_shared<SimpleLogger>());
    cl.doSomething();
    cl.setLogger(std::make_shared<TimeLogger>());
    cl.doSomething();
    cl.doSomething();

    std::cout << '\n';
    return 0;
}