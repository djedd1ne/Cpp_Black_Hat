#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp; // TCP protocol for network communication

std::string make_response() {
    std::string response_body = "<html><body>You successfully made a request to the server</body></html>";
    std::string status_line = "HTTP/1.1 200 OK\r\n";
    std::string content_type_header = "Content-Type: text/html\r\n";
    std::string content_length_header = "Content-Length: " + std::to_string(response_body.size()) + "\r\n";
    return status_line + content_type_header + content_length_header + "\r\n" + response_body;
}

int main()
{
    try {
        boost::asio::io_context io_context; // create an I/O context fot Boost.asio
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 80));
        while (true) // accept incoming connections indefinitely 
        {
            tcp::socket socket(io_context); // create socket object
            acceptor.accept(socket);

            std::cout << "Received request from: " <<  socket.remote_endpoint().address().to_string() << std::endl;
            //print the IP address of remote endpoint
            std::string response = make_response(); // Generate the HTTP response
            boost::asio::write(socket, boost::asio::buffer(response)); // send the response to the client
            socket.shutdown(tcp::socket::shutdown_both); // shutdown write/read on the socket
            socket.close();
        }
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl; // print any exceptions that occur
    }
    return 0; //exit the program
}