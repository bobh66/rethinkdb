#ifndef __PROTOCOL_REDIS_PROTO_HPP__
#define __PROTOCOL_REDIS_PROTO_HPP__

#include "arch/types.hpp"
#include "redis/redis.hpp"

template <class protocol_type>
class namespace_interface_t;

void serve_redis(tcp_conn_t *, namespace_interface_t<redis_protocol_t> *);

struct redis_output_writer : public home_thread_mixin_t {
    explicit redis_output_writer(tcp_conn_t *conn) : out_conn(conn) {;}
    void output_response(redis_protocol_t::redis_return_type response);
    void output_error(const char *error);
protected:
    tcp_conn_t *out_conn;
};

#endif /* __PROTOCOL_REDIS_PROTO_HPP__*/
