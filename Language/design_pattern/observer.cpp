#include <iostream>
#include <list>

class Observer;

// subject 被观察者
class Subject {
 public:
  virtual ~Subject() {}
  virtual void attach(Observer* obs) = 0;
  virtual void detach(Observer* obs) = 0;
  virtual void notify() = 0;
};

class Observer {
 public:
  virtual ~Observer() {}
  virtual void update() = 0;
};

// 具体的subject
class WeatherData : public Subject {
 private:
  std::list<Observer*> observers;
  float temperature;

 public:
  void attach(Observer* obs) override { observers.push_back(obs); }
  void detach(Observer* obs) override { observers.remove(obs); }

  void notify() override {
    for (Observer* observer : observers) {
      observer->update();
    }
  }

  void setTemprature(float temp) {
    temperature = temp;
    notify();
  }
  float getTemprature() const { return temperature; }
};

// 具体的observer
class TemperatureDisplay : public Observer {
 private:
  WeatherData& weatherdata;

 public:
  TemperatureDisplay(WeatherData& wd) : weatherdata(wd) {
    weatherdata.attach(this);
  }
  ~TemperatureDisplay() { weatherdata.detach(this); }
  void update() override {
    std::cout << "Current temperature is : " << weatherdata.getTemprature()
              << "°C\n";
  }
};

int main() {
  WeatherData wd;
  TemperatureDisplay display(wd);
  wd.setTemprature(21.3f);
  wd.setTemprature(33.1f);
  return 0;
}