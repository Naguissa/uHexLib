# Arduino (and standard C) tiny and cross-device compatible hexadecimal coding/decoding library.

## What is this repository for?

Standard C library to encode and decode bytes to hexadecimal.

Supports any microcontroller.


## Usage ##

You have this new type used as return type of encoding, which has 2 bytes, named 'a' and 'b':
- uHexLib2Bytes: { uint8_t a; uint8_t b; }

You have uHexLib class with following static methods:
- **uHexLib2Bytes uHexLib::encode(const uint8_t);** : Given one byte it encodes it to 2 base64 bytes and returns the struct.
- **uint8_t uHexLib::decode(const uint8_t inA, const uint8_t inB);** : Given two base64 bytes it decodes and returns them as 1 byte.

## How do I get set up?

You can get it from Arduino libraries directly, searching by uHexLib.

For manual installation:

 * Get the ZIP from releases link: https://github.com/Naguissa/uHexLib/releases
 * Rename to uHexLib.zip
 * Install library on Arduino

## Example

Included on example folder, available on Arduino IDE.


## Who do I talk to?

 * [Naguissa](https://github.com/Naguissa)
 * https://www.foroelectro.net


## Contribute

Any code contribution, report or comment are always welcome. Don't hesitate to use GitHub for that.


 * You can sponsor this project using GitHub's Sponsor button: https://github.com/Naguissa/uHexLib
 * You can make a donation via PayPal: https://paypal.me/foroelectro


Thanks for your support.


Contributors hall of fame: https://www.foroelectro.net/hall-of-fame-f32/contributors-contribuyentes-t271.html
