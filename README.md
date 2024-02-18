# Steganography

This is a simple steganography tool that can be used to hide text in an image. The tool uses the least significant bit (LSB) method to hide the text in the image. The tool can also be used to extract the hidden text from the image.

## Installation

To install the tool, execute the following commands:

```bash
git clone https://github.com/FujiwaraChoki/fuji-steg.git
cd fuji-steg
mkdir build && cd build
cmake ..
make
```

## Usage

To hide text in an image, execute the following command:

```bash
./fuji-steg embed <input_image_path> <output_image_path> <text>
```

To extract the hidden text from an image, execute the following command:

```bash
./fuji-steg extract <input_image_path>
```

## Example

To hide the text "Hello, World!" in the image `input.png` and save the result in `output.png`, execute the following command:

```bash
./fuji-steg embed input.png output.png "Hello, World!"
```

To extract the hidden text from the image `output.png`, execute the following command:

```bash
./fuji-steg extract output.png
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
