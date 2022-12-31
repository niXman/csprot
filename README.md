[![Build Status](https://travis-ci.org/niXman/csprot.svg?branch=master)](https://travis-ci.org/niXman/csprot)

# csprot
C++14 compile time literal-string encoder, which decodes a strings at run-time

It can be used to prevent reverce-engineering of executable based on string-literal search. Any string-literal wrapped in `csprot::cstring` will be present in a executable as just a sequence of random-bytes.
