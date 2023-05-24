#include <pthread.h>
#include <stdio.h>
#include <cstdlib>

class Mutex {
   public:
    Mutex();
    ~Mutex();
    void Lock();
    void Unlock();

   private:
    pthread_mutex_t mu_;
    Mutex(const Mutex&);
    void operator=(const Mutex&);
};