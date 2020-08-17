file(REMOVE_RECURSE
  "robogen.pb.cc"
  "robogen.pb.h"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/proto.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
