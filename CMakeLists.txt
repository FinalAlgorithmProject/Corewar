cmake_minimum_required(VERSION 3.7)
project(corewar)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES cor/virtual_machine/vp_virtual_main.c cor/virtual_machine/vp_err_u.c
        cor/virtual_machine/vp_basic.c cor/virtual_machine/vp_commands.c
        cor/virtual_machine/vp_instructions.c
        cor/virtual_machine/new_chmp.c
        cor/virtual_machine/additional_func.c
        cor/virtual_machine/vp_output_err.c
        cor/virtual_machine/reg_dir_ind.c

        cor/instructions/vp_live.c
        cor/instructions/vp_add.c
        cor/instructions/vp_aff.c
        cor/instructions/vp_and.c
        cor/instructions/vp_fork.c
        cor/instructions/vp_ld.c
        cor/instructions/vp_ldi.c
        cor/instructions/vp_lfork.c
        cor/instructions/vp_lld.c
        cor/instructions/vp_lldi.c
        cor/instructions/vp_or.c
        cor/instructions/vp_st.c
        cor/instructions/vp_sti.c
        cor/instructions/vp_sub.c
        cor/instructions/vp_xor.c
        cor/instructions/vp_zjmp.c

        op.c
        cor/virtual_machine/virtualm.h op.h corewar.h)

file(GLOB LIBFT "libft/src/libft/*.c")

file(GLOB VM "cor/virtual_machine/*.c" "cor/instructions/*.c")

add_executable(corewar ${SOURCE_FILES} ${LIBFT} ${VM})

target_link_libraries(corewar ${CMAKE_SOURCE_DIR}/libft/libft.a)