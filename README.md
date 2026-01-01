# peanut

peanut is a minimal application layer protocol inspired by gopher.

"peanut" is also a server for the peanut protocol.

## peanut (the protocol)

peanut is a very minimal application layer protocol designed to be very easy to implement inspired by gopher.

peanut only has:
- texts
- links

## peanut (the server)

peanut (the server) is an official server implementation of the peanut protocol.

## installation

1. clone the repo
2. run `sudo make install`

## setting up a peanut site

after installing peanut (the server), you need to make the `/var/peanut/peanutmap` file which
serves as the root for the peanut site. now run `peanut` and visit your peanut site (with a peanut client) at 127.0.0.1 on port 5050.
