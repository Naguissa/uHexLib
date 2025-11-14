# Arduino (and standard C) tiny and cross-device compatible hexadecimal coding/decoding library.

Master status:  ![Arduino CI](https://github.com/Naguissa/uHexLib/workflows/arduino_ci/badge.svg)


## What is this repository for?

Standard C library to encode and decode bytes to hexadecimal.

Supports any microcontroller.


## Usage

You have this new type used as return type of encoding, which has 2 bytes, named 'a' and 'b':
    - uHexLib2Bytes: { uint8_t a; uint8_t b; }

You have uHexLib class with following static methods:

    - **uHexLib2Bytes uHexLib::encode(const char);** : Given one char it encodes it to 2 base64 chars and returns the struct
    - **char uHexLib::decode(const char inA, const char inB);** : Given two base64 chars it decodes and returns them as 1 char

    - **uint16_t uHexLib::encode(const char in[], char out[]<, optional uint16_t length>);** : Given one char array encodes it to 2*size base64 char array and returns the original array processed bytes number.
    - **uint16_t  uHexLib::decode(const char in[], char out[]<, optional uint16_t original_length>);** : Given one base64 char array it decodes to size/2 decoded char array and returns the original array decoded bytes number.
    

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
