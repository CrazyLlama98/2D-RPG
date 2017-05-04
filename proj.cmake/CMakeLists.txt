cmake_minimum_required (VERSION 2.6)
project (2D-RPG)

add_subdirectory(../../../../../../oxygine/oxygine-framework oxygine-framework)
add_definitions(${OXYGINE_DEFINITIONS})
include_directories(${OXYGINE_INCLUDE_DIRS})
link_directories(${OXYGINE_LIBRARY_DIRS})

file(GLOB_RECURSE BOX2DSRC
		../box2d/*.cpp
		../box2d/*.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OXYGINE_CXX_FLAGS}")

add_executable(2D-RPG ${BOX2DSRC} ../src/Game.cpp ../src/main.cpp ../src/Entity.cpp ../src/Utils.cpp ../src/Character.cpp ../src/Environment.cpp ../src/SpecialEnvironment.cpp ../src/Map.cpp ../src/Hero.cpp ../src/MainActor.cpp ../src/res.cpp ../src/Game.h ../src/Entity.h ../src/Utils.h ../src/Character.h ../src/Environment.h ../src/SpecialEnvironment.h ../src/Map.h ../src/Hero.h ../src/MainActor.h ../src/res.h)
source_group(box2d FILES ${BOX2DSRC})
include_directories(../box2d)

target_link_libraries(2D-RPG ${OXYGINE_CORE_LIBS})




if (WIN32) #disable console mode for VC++
	set_target_properties(2D-RPG PROPERTIES WIN32_EXECUTABLE TRUE)
endif(WIN32)



if (EMSCRIPTEN)
	SET(CMAKE_EXECUTABLE_SUFFIX ".html")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s NO_EXIT_RUNTIME=1 -s WARN_ON_UNDEFINED_SYMBOLS=1 --memory-init-file 0 -s TOTAL_MEMORY=50331648")
	em_link_pre_js(2D-RPG  ${OXYGINE_JS_LIBRARIES}  ${CMAKE_CURRENT_SOURCE_DIR}/data.js)
endif(EMSCRIPTEN)
