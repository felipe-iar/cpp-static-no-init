#include <stdint.h>
#include <cmsis_iar.h>

void main()
{
  __no_init static uint8_t whatever[20] @ "System_Mailbox";
  
  whatever[0] = 0x42;
  whatever[1] = 0x43;
  whatever[2] = 0x44;

  while(1);
}
