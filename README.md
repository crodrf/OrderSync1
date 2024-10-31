
# OrderMatchEngine

OrderMatchEngine is a C++ order matching engine designed to simulate trade order processing in a financial exchange environment. It supports Market, Limit, and Fill-or-Kill orders, with modular matching strategies and both console and file-based logging. Ideal for backtesting and exploring order matching mechanics in financial markets.

## Features

- **Order Types Supported**: Market, Limit, and Fill-or-Kill orders.
- **Modular Design**: Easily extensible with strategies for order matching and logging.
- **Unit Testing**: Includes comprehensive tests with Google Test.
- **Logging Options**: Console and file-based logging for order and trade history.

## Getting Started

### Prerequisites

- **CMake**: Version 3.10 or higher
- **G++**: Recommended version 7 or higher
- **Google Test**: Automatically downloaded if not found

### Building the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/OrderMatchEngine.git
   cd OrderMatchEngine
   ```

2. Create a build directory and run CMake:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

3. Run the application:
   ```bash
   ./OrderMatchEngine
   ```

4. Run the tests:
   ```bash
   ./OrderMatchEngine_tests
   ```

## Usage

The main application simulates an order matching engine. You can add custom order types and strategies by extending the provided classes in `src/` and `include/`.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
