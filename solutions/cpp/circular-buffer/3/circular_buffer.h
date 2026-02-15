#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;
namespace circular_buffer {
    template <class T>
    class circular_buffer {
        private:
            vector<T> buf;
            int rpos;
            int wpos;
            int size;
            int capacity;
            
        public:
            circular_buffer(int cap_in) : capacity(cap_in) {
                rpos=0;
                wpos=0;
                size = 0;
                buf.reserve(capacity);
            };
            T read () {
                if (size==0) throw domain_error("no data");
                T data= buf[rpos];
                rpos++;
                if (rpos>(capacity-1)) rpos=0;
                size--;
                return data;
            }
            void write(T arg) {
                size++;
                if (size>capacity) throw domain_error("buffer full");
                buf[wpos]=arg;
                wpos++;
                if (wpos>(capacity-1)) wpos=0;
            }
            void overwrite(T arg) {
                if (size<capacity) {
                    size++;
                    buf[wpos]=arg;
                    wpos++;
                    if (wpos>(capacity-1)) wpos=0;
                } else {
                    buf[rpos]=arg;
                    rpos++;
                    if (rpos>(capacity-1)) rpos=0;
                }
            }
            void clear() {
                rpos=0;
                wpos=0;
                size = 0;
                for (int i=0; i<capacity-1;i++) buf.push_back(0);
            }
    };
}  // namespace circular_buffer

#endif // CIRCULAR_BUFFER_H