    cmake_minimum_required(VERSION 3.8)
    project(CEvsZombies)

    set(CMAKE_CXX_STANDARD 17)

    # Include a library search using find_package()
    # via REQUIRED, specify that libraries are required
    find_package(Qt5Core REQUIRED)
    find_package(Qt5Gui REQUIRED)
    find_package(Qt5Widgets REQUIRED)
    set(SOURCE_FILES main.cpp GUI/AStarAlgthm.cpp GUI/AStarAlgthm.h GUI/gameMatrixGUI.cpp GUI/gameMatrixGUI.h GA/Zombies.cpp GA/Zombies.h GA/Genetic.cpp GA/Genetic.h)
    add_executable(CEvsZombies ${SOURCE_FILES})

    # specify which libraries to connect
    target_link_libraries(${PROJECT_NAME} Qt5::Core)
    target_link_libraries(${PROJECT_NAME} Qt5::Gui)
    target_link_libraries(${PROJECT_NAME} Qt5::Widgets)