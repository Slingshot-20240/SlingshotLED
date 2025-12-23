# 💡 SlingshotLED 🚨

RP2040-controlled 8x8 WS2812B LED Panel  
A **20240 Slingshot** robot peripheral for the DECODE™ season.

> [!NOTE]
> 🚧 This project is in development. We'll update this repository with hardware information soon.

## Development

### Prerequisites

- Visual Studio Code
- [PlatformIO IDE extension for VS Code](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)

### Project Setup

Depending on your specific RP2040 board, you may need to change the configuration in [`platformio.ini`](platformio.ini). The default board is the Raspberry Pi Pico (compatible with most generic boards) with a flash size of 16 MB. 

If you are using the clangd VS Code extension, make sure to disable it for this repository, as it'll generate errors due to an environment mismatch between your machine and the RP2040 board. Use the [C/C++ extension by Microsoft](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) instead.

### Build and Run

Simply build and/or upload the code with the PlatformIO extension! It doesn't get any simpler than this.

### TeamCode Integration

Coming soon...

## Legal

### Disclaimer

*FIRST*®, *FIRST*® Tech Challenge, FTC®, *FIRST*® AGE™, DECODE™, and all accompanying logos as they are created, are trademarks of For Inspiration and Recognition of Science and Technology (*FIRST*®) (www.firstinspires.org). These trademarks are used by special permission of *FIRST* which is not overseeing, involved with, or responsible for this activity, product, or service. © 2025 *FIRST*®. Used by special permission. All rights reserved.

### Copyright

© 2025 FTC Team 20240 Slingshot and Contributors. [MIT License](https://github.com/Slingshot-20240/SlingshotLED/blob/release/LICENSE).