# MoreMultilib

A comprehensive multi-language library demonstrating equivalent implementations across C, C++, Rust, and Python. This project serves as an educational resource for understanding how to translate concepts and patterns between different programming languages.

## Project Overview

This project demonstrates how to implement the same functionality across multiple programming languages, making it easier to:
- Understand language-specific features and idioms
- Learn how to translate code between languages
- Compare implementation approaches
- Study design patterns in different contexts

## Supported Languages

- **C** (C17)
- **C++** (C++17)
- **Python** (3.x)
- **Rust** (latest stable)

## Project Structure

The project is organized into the following directories:

```
project-root/
│
├── c/
│ └── src/
│   ├── basic/
│   ├── advanced/
│   └── dp/
│
├── cpp/
│ └── src/
│   ├── basic/
│   ├── advanced/
│   └── dp/
│
├── python/
│ └── src/
│   ├── basic/
│   ├── advanced/
│   └── dp/
│
└── rust/
  └── src/
    ├── basic/
    ├── advanced/
    └── dp/

```


## Available Tests

Each language implementation supports the following test commands:
- `test_visibilita_variabili`: Variable scope and visibility
- `files_handling`: File I/O operations
- `variadic_example`: Variadic functions
- `timedate_handling`: Date and time operations
- `union_test`: Union type usage
- `basic_class_example`: Basic OOP concepts
- `multiple_inheritance`: Multiple inheritance examples
- `template_example`: Template/Generic programming
- `factory_example`: Factory pattern implementation
- `all`: Run all available tests

## Language-Specific Notes

### C
- Uses C17 standard
- Implements OOP concepts using structs and function pointers
- Includes memory management examples

### C++
- Uses C++17 standard
- Demonstrates modern C++ features
- Includes template metaprogramming examples

### Python
- Uses Python 3.x
- Includes Python-specific features like decorators
- Demonstrates Python's dynamic typing and duck typing

### Rust
- Uses latest stable Rust
- Demonstrates Rust's ownership system
- Includes safe concurrency examples



## Tab of modules

| Modulo | C   | Rust | C++ | Py  |
| --- | --- | --- | --- | --- |
| basic/var | X   | X   | X   | X   |
| basic/files | X   | X   | X   | X   |
| basic/variadic | X   | X   | X   | X   |
| basic/datetime | X   | X   | X   | X   |
| basic/union | X   | X   | X   | X   |
| advanced/basic_namespace |     | X   | X   |     |
| advanced/basic_object | X   | X   | X   | X   |
| advanced/object_namespace |     |     | X   |     |
| advanced/multiple_inheritance |     | X   | X   |  X   |
| advanced/template_class |     | X   | X   | X   |
| advanced/template_inheritance |     | X   | X   | X   |
| advanced/mro |     | X   | X   | X   |
| advanced/mt_data_race | X   | X   |     | X   |
| dp/creational/singleton | X   | X   |     | X   |
| dp/creational/mt_singleton |     | X   |     |     |
| dp/creational/borg |     |     |     | X   |
| dp/creational/union_singleton | X   | X   | X   |     |
| dp/creational/mt_union_singleton |     | X   |     |     |
| dp/creational/factory | X   | X   | X   | X   |
| dp/structural/decorator |     | X   |     | X   |

## Building and Running

### C
```bash
cd c/src
make
./program.out [test_name]
```

### C++
```bash
cd cpp/src
make
./program.out [test_name]
```

### Python
```bash
cd Python/src
python main.py [test_name]
```

### Rust
```bash
cd rust
cargo run [test_name]
```

## Available Tests

Each language implementation supports the following test commands:
- `test_visibilita_variabili`: Variable scope and visibility
- `files_handling`: File I/O operations
- `variadic_example`: Variadic functions
- `timedate_handling`: Date and time operations
- `union_test`: Union type usage
- `basic_class_example`: Basic OOP concepts
- `multiple_inheritance`: Multiple inheritance examples
- `template_example`: Template/Generic programming
- `factory_example`: Factory pattern implementation
- `all`: Run all available tests

## Language-Specific Notes

### C
- Uses C17 standard
- Implements OOP concepts using structs and function pointers
- Includes memory management examples

### C++
- Uses C++17 standard
- Demonstrates modern C++ features
- Includes template metaprogramming examples

### Python
- Uses Python 3.x
- Includes Python-specific features like decorators
- Demonstrates Python's dynamic typing and duck typing



## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.
