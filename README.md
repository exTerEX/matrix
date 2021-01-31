# libmatrix

Libmatrix is a project trying to create a lightweight, efficient and easy-to-use C++ library for working with matrices. The core library include both scalar and matrix operations, functions (transpose, linear transformations, etc.) and utilities (submatrix extraction, decomposition, etc.) The library is intended to not rely on any non-standard C++17 library. Python and golang bindings will be available.

## Getting Started

TODO

### Prerequisites

TODO

### Installation

## Example

```c++
#import "libmatrix/matrix.hpp" // if located in include/libmatrix

int main(int argc, char **argv) {
    ; // TODO
}
```

More examples will be available in `examples`.

## Roadmap

Currently working on core functionality.

## Contributing

Read [CONTRIBUTING.md](/blob/main/.github/CONTRIBUTING.md) for a detailed description of how to contribute.

## Target branch rules

To contribute follow the branch naming convention,

| Instance |   Branch   |                Description & Instructions |
| :------- | :--------: | ----------------------------------------: |
| Stable   |   stable   |  Accepts merges from Working and Hotfixes |
| Working  |    main    | Accepts merges from Features and Hotfixes |
| Feature  | \*-feature |                    Always branch off Main |
| Bugfix   |   \*-fix   |                  Always branch off Stable |

## License

This project is licensed under `MIT`. See [LICENSE](LICENSE) for more information.

## Contact

Andreas Sagen - developer@sagen.io - [@andreas_sagen](https://twitter.com/andreas_sagen)
