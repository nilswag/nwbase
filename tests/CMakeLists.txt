
add_executable(test_log test_log.c)
target_link_libraries(test_log PRIVATE nwbase)

add_test(
    NAME log
    COMMAND test_log
)