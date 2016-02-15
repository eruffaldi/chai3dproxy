
add_definitions(--std=c++11)
include_directories(/opt/local/include/eigen3)
include_directories(.)
include_directories(collisions)

add_executable(main main.cpp fingerproxy.cpp collisions/CCollisionAABB.cpp collisions/CCollisionAABBTree.cpp collisions/CGenericCollision.cpp)