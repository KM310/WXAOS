# PPC64 architecture build rules

add_subdirectory(boot)
add_subdirectory(mm)
add_subdirectory(irq)
add_subdirectory(cpu)
add_subdirectory(timer)
add_subdirectory(uart)
add_subdirectory(platform)

add_library(arch_ppc64 OBJECT
    link.ld
)

target_include_directories(arch_ppc64 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
