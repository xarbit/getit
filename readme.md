## Build application

```
$ cd build
$ cmake ../
$ make getit
$ ./bin/getit
```

## Run tests

```
$ cd build
$ cmake ../
$ make getit_tests
$ ./bin/getit_tests
```

### Dependencies

#### cpprestsdk

GetIt makes use of the [Microsoft CPP Rest SDK](https://github.com/Microsoft/cpprestsdk) library. Please checkout the documentation to see how you can [install](https://github.com/Microsoft/cpprestsdk#getting-started) this on your computer.

#### OpenSSL

The Microsoft CPP Rest SDK uses the OpenSSL package.

https://gist.github.com/llbbl/c54f44d028d014514d5d837f64e60bac

#### Boost packages

- thread
- system
- chrono
