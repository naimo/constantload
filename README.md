# Arduino constant load

Arduino sketch to go with simple constant load hardware based on
- Arduino Nano
- TLV271 rail-to-rail opamp
- IRLZ44N low threshold N-channel power mosfet
- Power resistor (0.2R)

## Features
Serial operation to switch state
- 'a' to arm and allow setting current
- '1' or '2' to set 1A or 2A discharging
- 'd' or '0' to disarm (set current to 0A)

Automatically switches back to disarm/0A when cutoff voltage is reached

Outputs every 100ms
> milliseconds,current(mA),voltage(mV),state