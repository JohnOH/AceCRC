# See https://github.com/bxparks/UnixHostDuino for documentation about using
# UnixHostDuino to compile and run AUnit tests natively on Linux or MacOS.

APP_NAME := MemoryBenchmark
ARDUINO_LIBS := AceCRC
MORE_CLEAN := more_clean
include ../../../../UnixHostDuino/UnixHostDuino.mk

.PHONY: benchmarks

TARGETS := nano.txt micro.txt samd.txt esp8266.txt esp32.txt teensy32.txt

README.md: $(TARGETS) generate_readme.py generate_table.awk
	./generate_readme.py > $@

benchmarks: $(TARGETS)

nano.txt:
	./collect.sh --cli nano $@

micro.txt:
	./collect.sh --cli micro $@

samd.txt:
	./collect.sh --cli samd $@

esp8266.txt:
	./collect.sh --cli esp8266 $@

esp32.txt:
	./collect.sh --cli esp32 $@

# Teensy does not support ArduinoCLI as far as I know.
teensy32.txt:
	./collect.sh --ide teensy32 $@

more_clean:
	echo "Use 'make clean_benchmarks' to remove *.txt files"

clean_benchmarks:
	rm -f $(TARGETS)
