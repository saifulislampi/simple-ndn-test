# Simple NDN Test
This project demonstrates a simple test using Named Data Networking (NDN). It includes a producer and consumer application to showcase basic NDN communication.

## Prerequisites/Setup

Before you begin, ensure you have the following software installed:
- Follow the instructions on the [ndn-cxx GitHub repository](https://github.com/named-data/ndn-cxx) to install `ndn-cxx`.

- Follow the instructions on the [NFD GitHub repository](https://github.com/named-data/NFD) to install `NFD`.

Here is a quick guide to install `ndn-cxx` and `NFD`:

After installing build essentials for your operating system, follow these steps:

**Step 1: Install NDN dependencies:**
```sh
git clone --recursive https://github.com/named-data/ndn-cxx.git
cd ndn-cxx
./waf configure --with-examples
./waf
sudo ./waf install
```

**Step 2: Update the Library Cache**
```sh
sudo ldconfig
```

Or in macos
```sh
sudo update_dyld_shared_cache
```

**Step 3: Install NFD:**
```sh
git clone --recursive https://github.com/named-data/NFD.git
cd NFD
./waf configure
./waf
sudo ./waf install
```
**Step 4: Configure NFD:**
```sh
sudo mkdir -p /usr/local/etc/ndn
sudo cp /usr/local/etc/ndn/nfd.conf.sample /usr/local/etc/ndn/nfd.conf
```


**Step 5: Start NFD:**

```sh
nfd-start
```

## How to Run This Test

1. **Create a build directory:**

    ```sh
    mkdir build
    cd build
    ```

2. **Run CMake and make:**

    ```sh
    cmake ..
    make
    ```

3. **Keep NFD status open in one terminal:**

    ```sh
    nfd-status
    ```

4. **Run the producer in another terminal:**

    ```sh
    ./producer
    ```

5. **Run the consumer in another terminal:**

    ```sh
    ./consumer
    ```

## Troubleshooting
If you encounter any issues, ensure that:

- `ndn-cxx` and `NFD` are correctly installed.
- `NFD` is running before you start the producer and consumer applications.
- You have the necessary permissions to run the applications.

For further assistance, refer to the [NDN documentation](https://named-data.net/doc/).

## Acknowledgements

This project uses the Named Data Networking libraries and tools. Special thanks to the NDN community for their support and contributions.
