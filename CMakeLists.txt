cmake_minimum_required(VERSION 4.0)
project(Blackjack)

set(CMAKE_CXX_STANDARD 23)

add_executable(Blackjack main.cpp Deck.cpp
        Player.cpp
        Player.h
)
