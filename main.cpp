#include <stdint.h>
#include <iostream>

using namespace std;

class Demo {
public:
  Demo() = default;
  ~Demo() = default;

  void set(uint8_t i, uint8_t v) { this->whatever[i] = v; }
  void print() {
    cout << "whatever[0]=" << hex << static_cast<int>(this->whatever[0]) << endl;
    cout << "whatever[1]=" << hex << static_cast<int>(this->whatever[1]) << endl;
    cout << "whatever[2]=" << hex << static_cast<int>(this->whatever[2]) << endl;
    cout << "whatever[3]=" << hex << static_cast<int>(this->whatever[3]) << endl;
  }
  __root static uint8_t whatever[20] @ "System_Mailbox";
};

__no_init uint8_t Demo::whatever[20];

void main()
{
  Demo d1,d2;

  while(1) {
    d1.set(0, 0x41);
    d1.set(1, 0x42);
    d1.set(2, 0x43);
    d1.print();

    d2.set(0, 0x14);
    d2.set(1, 0x24);
    d2.set(2, 0x34);
    d2.print();
  }
}

