#pragma once

#ifdef RingBufferModule_EXPORTS
#define RINGBUFFER_API __declspec(dllexport)
#else
#define RINGBUFFER_API __declspec(dllimport)
#endif

#include <vector>
#include <mutex>
#include <condition_variable>

template <typename T>
class  ThreadSafeRingBuffer
{
public:
    ThreadSafeRingBuffer(size_t capacity)
        : m_buffer(capacity), m_capacity(capacity), m_head(0), m_tail(0), m_size(0) {
    }

    ~ThreadSafeRingBuffer() = default;

    // write data (block)
    void push(const T& item)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cond_not_full.wait(lock, [&]() { return m_size < m_capacity; });

        m_buffer[m_tail] = item;
        m_tail = (m_tail + 1) % m_capacity;
        ++m_size;
        m_cond_not_empty.notify_one();
    }

    // read data (block)
    T pop()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cond_not_empty.wait(lock, [&]() { return m_size > 0; });

        T item = m_buffer[m_head];
        m_head = (m_head + 1) % m_capacity;
        --m_size;

        m_cond_not_full.notify_one();
        return item;
    }

private:
    std::vector<T> m_buffer;
    size_t m_capacity;
    size_t m_head;
    size_t m_tail;
    size_t m_size;
    std::mutex m_mutex;
    std::condition_variable m_cond_not_empty, m_cond_not_full;
};