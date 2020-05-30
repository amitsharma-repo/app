function(add_tests COMMAND)
set(options "")
set(oneValueArgs "")
set(multiValueArgs LABELS)

cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

if (NOT ARG_LABELS)
	message (FATAL_ERROR "LABELS not set for add_tests()" )
endif()

if(USE_GOOGLE_TEST)
	unset(labels)
	foreach(name ${ARG_LABELS})
		list(APPEND lables "LABELS" ${name})
	endforeach()
	gtest_discover_tests(${COMMAND} PROPERTIES ${LABELS})
else()
	string(REGEX REPLACE "^test_" "" name ${COMMAND})
	add_test(NAME ${name} COMMAND ${COMMAND})
	set_tests_properties(${name} PROPERTIES LABELS "${ARG_LABELS}")
endif()
endfunction()