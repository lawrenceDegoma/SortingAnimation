////
//// Created by Lawrence Degoma on 5/2/24.
////
//
//#include "Application.h"
//
//Application::Application(int size, int width, int height, std::string title) {
//    _size = size;
//    _width = width;
//    _height = height;
//    _title = title;
//}
//
//void Application::run() {
//    std::vector<int> nums(_size);
//    sf::RenderWindow window(sf::VideoMode(_width, _height), _title);
//    srand(time(0));
//    for (int i=0; i< _size; ++i){
//        nums[i] = rand() % _height + 1;
//    }
//
//    while (window.isOpen()){
//        sf::Event event;
//        while (window.pollEvent(event)){
//            if (event.type == sf::Event::Closed){
//                window.close();
//            }
//        }
//    }
//}