# HuffmanArchiver
This is an archiver/extractor tool based on [Canonical Huffman coding](https://en.wikipedia.org/wiki/Canonical_Huffman_code).

It is written in C++ and uses custom priority queue to achieve better speed, also consuming quite small RAM amount.

## Installation
Download and run installer:

```bash
$ wget https://raw.githubusercontent.com/cutehater/HuffmanArchiver/main/installer.sh
$ chmod +x installer.sh
$ ./installer.sh
```

After that, you can run archiver from `./HuffmanArchiver/build/`.

## Usage

* Archive files `file1, file2, ...` and save to `archive_name`:

```bash
$ archiver -c archive_name file1 [file2 ...]
```
* Extract files from archive `archive_name` to current directory

```bash
$ archiver -d archive_name
```

* Print help:

```bash
$ archiver -h
```
