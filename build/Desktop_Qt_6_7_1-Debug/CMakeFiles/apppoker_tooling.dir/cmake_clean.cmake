file(REMOVE_RECURSE
  "poker/CardLibrary"
  "poker/Main.qml"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/apppoker_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
