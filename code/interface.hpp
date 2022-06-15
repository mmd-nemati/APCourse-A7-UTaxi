#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "myserver.hpp"
#include "utaxi.hpp"

class Interface 
{
    public:
        void run(char *argv[]);

    private:
        Utaxi *utaxi;
        void server_pages(MyServer &server);
        void server_css(MyServer &server);
        void server_js(MyServer &server);
        void server_images(MyServer &server);
        void server_handlers(MyServer &server);
};

#endif /* __INTERFACE_H__ */