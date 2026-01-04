# peanut

peanut is a simple application layer protocol inspired by the gopher protocol.
peanut's goal is to be minimal and easy to implement.

## features

- texts
- links

## details

the peanut protocol assumes TCP. peanut servers should listen on port `5050`. peanut clients connect
to peanut servers (on port 5050) and send one line requesting a plain text file. if the request is
empty then the peanut server should send the peanutmap file (the root of the peanut site).

example:

```
client: {connects to peanut server on port 5050}
server: {accepts connection but says nothing}
client: {sends ""}
server: {respond with the contents of the peanutmap file}
server: {closes client's connection}
```

## peanutmap

the peanutmap file is a plain text file that serves as the root of a
peanut site (similar to the gophermap file). it can provide links to other
plain text files.

example:

```
Welcome to peanut!
                                   _
           _ __  ___ __ _ _ _ _  _| |_
          | '_ \/ -_) _` | ' \ || |  _|
          | .__/\___\__,_|_||_\_,_|\__|
          |_|

[about](./about.txt)
```

## links

links have a markdown-like syntax with the name of the link (what the client should display) in square brackets and
the plain text file path (what the client should request) in parentheses.

## available server implemenatations

- peanutd (official implementation)

## available client implementations

- none (official implementation in progress)

although there is no available clients for peanut, you can still access peanut sites with
network utilities such as netcat.

example:

`echo "" | nc {ip} 5050`
