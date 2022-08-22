#include <stdint.h>
#include <iostream>

using namespace std;

class Demo {

public:
  Demo() = default;
  ~Demo() = default;
  
  void set(uint8_t i, uint8_t v) { this->whatever[i] = v; }
  uint8_t get(uint8_t index) { return whatever[index]; }

  __root static uint8_t whatever[20] @ "System_Mailbox";
};

__no_init uint8_t Demo::whatever[20];

void main()
{
  Demo d;
  
  d.set(0, 0x41);
  d.set(1, 0x42);
  d.set(2, 0x43);
  
  cout << "whatever[0]=" << hex << static_cast<int>(d.get(0)) << endl;
  cout << "whatever[1]=" << hex << static_cast<int>(d.get(1)) << endl;
  cout << "whatever[2]=" << hex << static_cast<int>(d.get(2)) << endl;
  cout << "whatever[3]=" << hex << static_cast<int>(d.get(3)) << endl;
  
  while(1);
}
