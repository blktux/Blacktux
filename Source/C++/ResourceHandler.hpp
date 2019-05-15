/*-----------------------------
Copyright (c) 2019 M.I.T. License

Author(s):
- Jordan S.H. (blktux)

Note(s):
- Value of 1 means the call was
  terminated due to a flag had
  been called.
- Value of 0 means execution
  was successful.
- Value of (-1) means an unex-
  pected failure occured.
-----------------------------*/

#include <cstdlib>
#include <cstdio>
#include <chrono>
#include <thread>

namespace Blacktux 
{
    class Memory
    {
    public:
        Memory();
        ~Memory();
        // This method attempts to borrow memory from the heap.
        volatile decltype(auto) Allocate(unsigned bytes) noexcept;
        // This method attempts to give back memory to the heap.
        volatile decltype(uintptr_t) Deallocate(void &pointer) noexcept;
    };
    
    Memory::Memory() {
        return;
    }
    
    Memory::~Memory() {
        delete (this);
    }
    
    volatile decltype(auto) Allocate(unsigned bytes) noexcept {
        int *ptr = nullptr;
        ptr = static_cast<int*>(malloc(bytes));
        return ptr;
    }
    
    volatile decltype(uintptr_t) Deallocate(void &pointer) noexcept {
        if (pointer == NULL) {
            return pointer;
        } else if (!pointer == NULL) {
            free(pointer);
            return 0;
        }
    }
    
    class Time
    {
    public:
        Time();
        ~Time();
        constexpr decltype(auto) GetCurrentTime();
        const void Delay(unsigned time);
    };
    
    constexpr decltype(auto) Time::GetCurrentTime() {
        auto time = std::chrono::system_clock::now();
        return time;
    }
    
    const void Time::Delay(unsigned time) {
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        return;
    }
    
    Time::Time() {
        return;
    }
    
    Time::~Time() {
        delete (this);
    }
} // namespace Blacktux
