#pragma once

#include <thread>
#include <mutex>

// source : https://refactoring.guru/ru/design-patterns/singleton/cpp/example#example-1

class Singleton
{
private:
    static Singleton* pinstance_;
    static std::mutex mutex_;

protected:
    Singleton(const std::string value) : value_(value)
    {
    }
    ~Singleton() {}
    std::string value_;

public:
    Singleton(Singleton& other) = delete;
    void operator=(const Singleton&) = delete;
    static Singleton* GetInstance(const std::string& value)
    {
        std::lock_guard<std::mutex> lock(mutex_); // RAII
        if (pinstance_ == nullptr)
        {
            pinstance_ = new Singleton(value);
        }
        return pinstance_;
    }
    void SomeBusinessLogic()
    {
        // ...
    }
    std::string value() const
    {
        return value_;
    }
};