set_languages("c++23")
-- set toolset
--set_toolset("cxx", "clang")
--set_toolset("ld", "clang++")

target("test")
    set_kind("binary")
    add_files("*.cpp")
    add_rules("mode.release")
    