# TD_Clock

Digital/ Analog Clock code for the first challenge of ENGF0001, as seen in [this video](https://youtu.be/Vvrx6xLA1Fw).

Displays the digital clock first by default, and on either button clicks, switches to analog and back.
Syncs with GMT+0 with Daylight Saving using `pool.ntp.org` with the time.h library.

# Usage

To use this code with the Arduino IDE, install the correct board manager (esp32 by Espressif Systems) alongside all the necessary libraries.
Remember to include a `secrets.h` file that defines a `USERNAME` and `PASSWORD` macro to log into the eduroam wifi. Alternatively, the `setupWifi` function can be changed.

# Dependencies

- TFT_eSPI.h
- SPI.h
- FastTrig.h
- time.h
- WiFi.h
- esp_eap_client
