cmake_minimum_required(VERSION 3.15)
project(dns C)

set(CMAKE_C_STANDARD 11)
include_directories(.)

add_executable(dns main.c requests.c requests.h whois.c whois.h regexp.c regexp.h)
