#include <Arduino.h>
#include <AceCRC.h>

using namespace ace_crc::crc16ccitt_bit;

static const char CHECK_STRING[] = "123456789";
static const size_t LENGTH = sizeof(CHECK_STRING) - 1; // ignore NUL char

void setup() {
#if ! defined(UNIX_HOST_DUINO)
  delay(1000);
#endif
  SERIAL_PORT_MONITOR.begin(115200);
  while (!SERIAL_PORT_MONITOR); // Wait - Leonardo/Micro

  crc_t crc = crc_init();
  crc = crc_update(crc, CHECK_STRING, LENGTH);
  crc = crc_finalize(crc);

  SERIAL_PORT_MONITOR.print("0x");
  SERIAL_PORT_MONITOR.println((unsigned long) crc, 16);

#if defined(UNIX_HOST_DUINO)
  exit(0);
#endif
}

void loop() {
}