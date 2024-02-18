# Cpp_Black_Hat
<h3><b>Black Hat C++</b>: C++ For Pentesters course</h3>

/network/code.c file use: <br>
`gcc -lcurl code.c` to compile
/network/boost_http_request.cpp file use `-std=c++11` and include boost
change {PATH} to the path to your boost library <br>
`g++ -std=c++11 boost_http_request.cpp -I/{PATH}/boost/1.84.0/include/`

server.cpp <br>
`g++ -std=c++11 -I/Users/djmekki/.brew/Cellar/boost/1.84.0/include/ server.cpp`
```bash
curl 127.0.0.1:80
```
