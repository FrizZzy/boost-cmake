cmake_minimum_required(VERSION 2.8)

project(boost-test)
#add_executable(${PROJECT_NAME} "main.cpp")

#set(Boost_USE_STATIC_LIBS        ON) # only find static libs
#set(Boost_USE_MULTITHREADED      ON)
#set(Boost_USE_STATIC_RUNTIME    OFF)
#find_package(Boost 1.54.0 COMPONENTS date_time filesystem system )
#if(Boost_FOUND)
#  include_directories(${Boost_INCLUDE_DIRS})
#  add_executable(${PROJECT_NAME} "main.cpp")
#  target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
#endif()


find_package(Boost 1.54.0 COMPONENTS date_time filesystem system )
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(${PROJECT_NAME} "main.cpp")
  target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()
