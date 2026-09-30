cmake_minimum_required(VERSION 3.10)
project(nwbase C)

set(SOURCES 
	src/log.c
)

add_library(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
	C_STANDARD 17
	C_STANDARD_REQUIRED TRUE
)

target_include_directories(${PROJECT_NAME}
	PUBLIC include
)

target_compile_definitions(${PROJECT_NAME}
	PRIVATE $<$<CONFIG:Debug>:_DEBUG>
)

include(CTest)

if (BUILD_TESTING)
	add_subdirectory(tests)
endif()