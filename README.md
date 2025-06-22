# Project introduction👋
Welcome to izip's github page! Izip is easy to use lightweight cross-platform and multi-algorithm support file-compression and decompression software.

## Nice to know's ⁉️
 - as of 18.06.2025 the software only is stable on macosx and linux.
 - The recursive flag for recursively processing an archive is an temerary solution for decompressing folders, an more automatic solution is under development!
 - as of 10.06.2025 the project only support decompression of archives.

## Available command-line args 😜
```
OPTIONS:
  -h,     --help              Print this help message and exit 
  -v,     --verison           Display program version information and exit 
  -d,     --decompress TEXT   Takes file-path/filename for decompression
```


## Techlologies 🌟
 - [Libarchive](https://www.libarchive.org/) - C library for advanced compression & decompression of archives.
 - [Fmt](https://fmt.dev/) - Text formatting library for C++.
 - [SpdLog](https://cppget.org/spdlog) - C++ logging library for simple structured function set.
 - [GoogleTest](https://google.github.io/googletest/) - Mocking & Unittest library developed by google.
 - [CLI11](https://cliutils.github.io/CLI11/book/) - Interactive library for advanced cli application development for C++.

## Planned technologies 📌
 - Incicators - Relativly advanced library for developing fancy status-bars for cli applications.


## Clone & install dependencies ⏬
Clone github project repository

``git clone https://github.com/Trind03/izip.git``

The project installs dependencies from git-submodules
to keep it consistent cross-platform

``git submodule update --init --recursive``

## Build and install 👾
Generate project files

``cmake -S . -B ./bin``

Build - __Optionally__ you can append for multithreaded builds
``-j 5``

``cmake --build ./bin ``

If you're using as generator you can use for system-wide access

``cd bin; make install``