[![Build Status](https://travis-ci.org/niXman/csprot.svg?branch=master)](https://travis-ci.org/niXman/csprot)

# csprot
Compile time string-literal protector for C++14

It can be used to prevent reverce-engineering of executable based on string-literal search. Any string-literal wrapped in `csprot::cstring` will be present in a executable as just a sequence of random-bytes.
