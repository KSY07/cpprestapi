#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <string>

using namespace web;
using namespace std;
using namespace web::http;
using namespace web::http::experimental::listener;

int main() {

    http_listener_config listen_config; // 설정값

    //listener 생성, Server URL, Port 지정, 설정값 전달.
    http_listener listener(U("http://localhost:1234/"), listen_config);

    // 기본 GET 메서드
    listener.support(methods::GET, [&listener](http_request req){

            auto path = listener.uri().path();
            auto scheme = listener.uri().scheme();
            auto user_info = listener.uri().user_info();
            auto host = listener.uri().host();
            auto port = listener.uri().port();
            auto query = listener.uri().query();
            auto fragment = listener.uri().fragment();
            auto response = req.get_response();

            std::cout << utility::conversions::to_utf8string(response.get().to_string()) << endl;
            std::cout << "path : " << utility::conversions::to_utf8string(path) << endl;
            std::cout << "scheme : " << utility::conversions::to_utf8string(scheme) << endl;
            std::cout << "user_info : " << utility::conversions::to_utf8string(user_info) << endl;
            std::cout << "host : " << utility::conversions::to_utf8string(host) << endl;
            std::cout << "port : " << port << endl;
            std::cout << "query : " << utility::conversions::to_utf8string(query) << endl;
            std::cout << "fragment : " << utility::conversions::to_utf8string(fragment) << endl;

            req.reply(status_codes::OK, "hello world!\n");
    });

    listener.open().then([&listener]() {
        std::cout << "\n start!!\n";
    }).wait();

    while(true);

    listener.close();

    return 0;
}
