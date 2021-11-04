# HuffmanArchiver
This is an archiver/extractor tool based on [Canonical Huffman coding](https://en.wikipedia.org/wiki/Canonical_Huffman_code).

It is written in C++ and uses custom priority queue to achieve better speed, also consuming quite small RAM amount.

## Installation
1. Clone the repository:

```bash
git clone https://github.com/cutehater/HuffmanArchiver.git
```

2. Create build folder and open it: 

```bash
mkdir HuffmanArchiver/build
cd HuffmanArchiver/build

```
3. Create executable file `archiver`: 

```bash
cmake ..
make
```

## Usage
* Archive files `file1, file2, ...` and save to `archive_name`:

```bash
archiver -c archive_name file1 [file2 ...]
```
* Extract files from archive `archive_name` to current directory

```bash
archiver -d archive_name
```

* Print help:

```bash
archiver -h
```
