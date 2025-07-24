set_warnings("all", "error")
set_optimize("fastest")
set_kind("binary")
set_targetdir("build")

target("jlox")
  set_languages("c++17")
  add_files("jlox/**.cc")
