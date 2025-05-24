# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\architecture_lab3_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\architecture_lab3_autogen.dir\\ParseCache.txt"
  "architecture_lab3_autogen"
  )
endif()
